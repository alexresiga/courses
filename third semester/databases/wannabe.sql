create database test
use test
go
if object_id('ListofHeroes', 'U') is not NULL
    drop table ListofHeroes

if object_id('Heroes', 'U') is not NULL
    drop table Heroes

if object_id('Cinematics', 'U') is not NULL
    drop table Cinematics

if object_id('Games', 'U') is not NULL
    drop table Games

if object_id('Companies', 'U') is not NULL
    drop table Companies

create table Companies (
    CID INT PRIMARY KEY IDENTITY(1,1),
    [Name] VARCHAR(20),
    [Description] VARCHAR(50),
    Website VARCHAR(10)
)

create TABLE Games (
    GID INT PRIMARY KEY IDENTITY(1,1),
    GName VARCHAR(20),
    ReleaseDate DATE,
    CID INT REFERENCES Companies(CID)
)

create TABLE Cinematics (
    CMID INT PRIMARY KEY IDENTITY(1,1),
    CMName VARCHAR(20),
    GID INT REFERENCES Games(GID)
)

create TABLE Heroes (
    HID INT PRIMARY KEY IDENTITY(1,1),
    [Name] VARCHAR(20),
    [Description] VARCHAR(50),
    Importance TINYINT
)

create TABLE ListOfHeroes (
    CMID INT REFERENCES Cinematics(CMID),
    HID INT REFERENCES Heroes(HID),
    PRIMARY KEY(CMID, HID),
    EntryMoment TIME
)
SELECT * FROM  Games
GO
insert into Companies VALUES('c1', 'd1', 'w1'), ('c2', 'd2', 'w2')
insert into Games VALUES('g1', '2012-05-02', 1), ('g2', '1998-03-02', 2)
insert into Cinematics VALUES('cm1', 1), ('cm2', 1), ('cm3', 2), ('cm4', 1), ('cm5', 2)

insert into Cinematics VALUES('cm3', 1)
insert into Heroes VALUES('h1', 'd1', 2), ('h2', 'd2', 1), ('h3', 'd3', 3)
insert into ListOfHeroes VALUES(9,1, '02:09'), (9,2, '03:04'), (10,1, '05:02'), (12,2, '01:34')
insert into ListOfHeroes VALUES(11, 1, '23:03'), (12, 1, '05:43'), (13, 1, '02:33')
insert into Games values ('dc game1', '2000-12-01', 1),
							('dc game2', '2005-12-01', 1),
							('dc game1', '2016-01-01', 1),
							('dc game1', '2016-12-01', 1)

go
CREATE OR ALTER PROCEDURE uspAddCinematicToHero @HName VARCHAR(20), @CName VARCHAR(20), @EM TIME
AS
BEGIN
    DECLARE @HID INT = (select HID from Heroes where Name like @HName),
            @CMID INT = (SELECT CMID from Cinematics where CMName like @CName)
    IF @HID IS NULL OR @CMID IS NULL
        RAISERROR('HERO OR CINEMATIC DOES NOT EXIST', 16, 1)
    ELSE IF EXISTS (SELECT * FROM ListOfHeroes WHERE @HID = HID and @CMID = CMID)
        BEGIN
            UPDATE ListOfHeroes
            SET EntryMoment = @EM
            WHERE @HID = HID and @CMID = CMID
        END
    ELSE INSERT INTO ListOfHeroes VALUES (@CMID, @HID, @EM)
END
GO
EXEC uspAddCinematicToHero 'h1', 'cm1', '05:05'
EXEC uspAddCinematicToHero 'h2', 'cm4', '03:22'
select * from ListOfHeroes
go

create or alter view vHeroesCinematics 
AS
SELECT H.Name, H.Importance
FROM Heroes H
WHERE NOT EXISTS
    (SELECT CMID
    FROM Cinematics
    EXCEPT
    SELECT CMID
    FROM ListOfHeroes
    WHERE H.HID = HID)
GO
SELECT *  FROM Games
SELECT * FROM vHeroesCinematics
GO
create or alter function ufCeva()
RETURNS TABLE
AS
RETURN 
SELECT C.Name, G.GName, CM.CMName
FROM Cinematics CM INNER JOIN Games G on CM.GID = G.GID INNER JOIN Companies C on G.CID = C.CID
WHERE G.ReleaseDate >= '2000-12-02' AND G.ReleaseDate <= '2016-01-01'
GO
SELECT * from ufCeva()