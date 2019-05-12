CREATE DATABASE p
go

use p
go

if object_id('SpaceEquip', 'U') is not NULL
    drop table SpaceEquip

if object_id('SpaceShips', 'U') is not NULL
    drop table SpaceShips

if object_id('Equipments', 'U') is not NULL
    drop table Equipments

if object_id('PlanetsRocks', 'U') is not NULL
    drop table PlanetsRocks

if object_id('Rocks', 'U') is not NULL
    drop table Rocks

if object_id('Planets', 'U') is not NULL
    drop table Planets
    
create table Equipments (
    EID int PRIMARY key IDENTITY,
    ename VARCHAR(20),
    weight VARCHAR(20)
)

alter table Equipments
alter column weight int

create table Rocks (
    RID int PRIMARY key IDENTITY,
    rname VARCHAR(20),
    hardness INT
)

create table Planets (
    PID int PRIMARY key IDENTITY,
    pname VARCHAR(20),
    dTS int
)

create table SpaceShips (
    SID int PRIMARY key IDENTITY,
    sname VARCHAR(20), 
    capacity int,
    PID int REFERENCES Planets(PID)
)

create table PlanetsRocks (
    PID int REFERENCES Planets(PID),
    RID int REFERENCES Rocks(RID),
    PRIMARY key(PID, RID),
    predominant bit
)

create table SpaceEquip (
    SID int REFERENCES SpaceShips(SID),
    EID int REFERENCES Equipments(EID),
    purpose VARCHAR(20),
    startDate DATE
)

insert into Planets VALUES ('p1', 123), ('p2', 1245), ('p3', 56), ('p4', 2345)
insert into Rocks VALUES ('r1', 2), ('r2', 3), ('r3', 5) 
insert into Equipments VALUES ('e1', 20), ('e2', 10), ('e3', 30)
insert into SpaceShips VALUES ('s1', 100, 1), ('s2', 200, 2), ('s3', 400, 1), ('s4', 140, 4)
insert into SpaceEquip VALUES (1, 1, 'p1', '2017-04-03'), (2, 3, 'p2', '2014-04-03')  
insert into PlanetsRocks VALUES (1, 1, 0), (1,2,1), (2,2,1), (1,3, 1)
GO
create or alter procedure uspAddEquip @Equip VARCHAR(20), @Ship VARCHAR(20), @purp VARCHAR(20), @SD DATE
AS
BEGIN
    DECLARE @EQID INT = (SELECT EID from Equipments where ename = @Equip),
            @SSID INT = (SELECT SID from SpaceShips where sname = @Ship)

    IF @EQID IS NULL OR @SSID IS NULL
        RAISERROR('do not exist', 16, 1)
    ELSE IF EXISTS (SELECT * FROM SpaceEquip WHERE SID = @SSID AND EID = @EQID)
        begin   
        RAISERROR('ALREADY EXISTS', 16, 1)
        RETURN
        end
    ELSE INSERT INTO SpaceEquip VALUES (@SSID, @EQID, @purp, @SD)
END
select * from SpaceEquip
exec uspAddEquip 'e1', 's1', 'ceva', '2012-03-04'
exec uspAddEquip 'e1', 's2', 'ceva', '2012-03-04'

GO
create or alter view vPredRock
AS
SELECT R.rname as RockName
FROM PlanetsRocks PR INNER JOIN Rocks R ON R.RID = PR.RID
WHERE PR.PID = 1 AND PR.predominant = 1

GO
select * from vPredRock
GO
create or alter FUNCTION ufminEquip(@distance INT)
RETURNS TABLE
AS
RETURN
SELECT SS.sname as Name
FROM SpaceShips SS INNER JOIN Planets P on SS.PID = P.PID
WHERE P.dTS = @distance AND SS.SID IN 
    (SELECT TOP 1 A.SID
    FROM 
    (SELECT SE.SID, SUM(E.weight) as suma
    FROM SpaceEquip SE INNER JOIN Equipments E on SE.EID = E.EID
    GROUP BY SE.SID 
    ) A
    ORDER BY A.suma)
go
SELECT * from ufminEquip(123)