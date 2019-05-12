use cinema
go
if object_id('StageDirectors', 'U') is not NULL
    drop table StageDirectors

if object_id('CinemaProductions', 'U') is not NULL
    drop table CinemaProductions

if object_id('Companies', 'U') is not NULL
    drop table Companies

if object_id('Movies', 'U') is not NULL
    drop table Movies

if object_id('Actors', 'U') is not NULL
    drop table Actors

create table Companies (
    COMID INT PRIMARY KEY IDENTITY,
    [name] VARCHAR(20)
)

create table StageDirectors (
    SID int PRIMARY KEY IDENTITY,
    [name] VARCHAR(20),
    awards int
)

create table Movies (
    MID int PRIMARY KEY IDENTITY,
    mname VARCHAR(20),
    releaseDate DATE,
    COMID int REFERENCES Companies(COMID),
    SID int REFERENCES StageDirectors(SID)
)

create table Actors (
    AID int PRIMARY key IDENTITY,
    aname VARCHAR(20),
    ranking TINYINT
)

CREATE TABLE CinemaProductions (
    CID int PRIMARY key IDENTITY,
    title VARCHAR(20),
    MID int REFERENCES Movies(MID)
)

create table Appearance(
    CID int REFERENCES CinemaProductions(CID),
    AID int REFERENCES Actors
    PRIMARY KEY(AID, CID)
    EntryMom TIME
)