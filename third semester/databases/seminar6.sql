create DATABASE wannabe
use wannabe
go

if object_id('RoutesStations', 'U') is not NULL
    drop table RoutesStations

if object_id('Stations', 'U') is not NULL
    drop table Stations

if object_id('Routes', 'U') is not NULL
    drop table Routes

if object_id('Trains', 'U') is not NULL
    drop table Trains

if object_id('TrainTypes', 'U') is not NULL
    drop table TrainTypes

CREATE TABLE TrainTypes(
    TTID TINYINT PRIMARY KEY IDENTITY(1,1),
    Description VARCHAR(100)
)

CREATE TABLE Trains(
    TID SMALLINT PRIMARY KEY IDENTITY(1,1),
    TName VARCHAR(70),
    TTID TINYINT REFERENCES TrainTypes(TTID)
)

CREATE TABLE Routes(
    RID SMALLINT PRIMARY KEY IDENTITY(1,1),
    RName VARCHAR(70),
    TID SMALLINT REFERENCES Trains(TID)
)

CREATE TABLE Stations(
    SID SMALLINT PRIMARY KEY IDENTITY(1,1),
    SName VARCHAR(100)
)

CREATE TABLE RoutesStations(
    RID SMALLINT REFERENCES Routes(RID),
    SID SMALLINT REFERENCES Stations(SID),
    Arrival TIME,
    Departure TIME,
    PRIMARY KEY(RID, SID)
)
GO
INSERT TrainTypes VALUES('per'), ('acc')
INSERT Trains VALUES ('t1', 1), ('t2', 1), ('t3', 2)
INSERT Routes VALUES ('r1', 1), ('r2', 2), ('r3', 3)
INSERT Stations VALUES ('s1'), ('s2'), ('s3')
INSERT RoutesStations(RID, SID, Arrival, Departure) VALUES
(1, 1, '7:00', '7:10'), (1, 2, '8:00', '8:10'), (1, 3, '9:00', '9:10'),
(2, 1, '7:00', '7:10'), (2, 2, '8:00', '8:10'), (2, 3, '9:00', '9:10'),
(3, 3, '9:00', '9:10')

select * from TrainTypes
select * from Trains
select * from Routes
select * from Stations
select * from RoutesStations
GO
CREATE OR ALTER PROCEDURE uspAddStationToRoute @RName VARCHAR(70), @SName VARCHAR(70), @Arrival TIME, @Departure TIME
AS
    declare @RID SMALLINT = (SELECT RID from Routes WHERE RName = @RName),
            @SID SMALLINT = (SELECT SID from Stations WHERE SName = @SName)

    IF @RID IS NULL or @SID IS NULL
        RAISERROR('route and/or station not present', 16, 1)
    ELSE IF EXISTS (SELECT * FROM RoutesStations WHERE RID = @RID AND SID = @SID)
        RAISERROR('station already on route', 16, 1)
    ELSE
        INSERT RoutesStations(RID, SID, Arrival, Departure) VALUES
            (@RID, @SID, @Arrival, @Departure)
GO

uspAddStationToRoute 'r3', 's2', '10:00', '10:20'
GO
CREATE OR ALTER VIEW vRoutesWithAllStations
AS
SELECT R.RName
FROM Routes R
WHERE NOT EXISTS
    (SELECT SID
    FROM Stations
    EXCEPT
    SELECT SID
    FROM RoutesStations
    WHERE RID = R.RID)
GO

SELECT * FROM vRoutesWithAllStations

GO
CREATE OR ALTER FUNCTION ufGetStationsByNoRoutes(@R INT)
RETURNS TABLE
RETURN SELECT S.SName
from Stations S
WHERE S.SID IN
(
SELECT SID
FROM RoutesStations
GROUP BY SID
HAVING COUNT(*) > @R)
GO

select * from ufGetStationsByNoRoutes(2)
