use bank
go

if object_id('Transactions', 'U') is not NULL
    drop table Transactions

if object_id('ATMS', 'U') is not NULL
    drop table ATMS

if object_id('Cards', 'U') is not NULL
    drop table Cards

if object_id('BankAcc', 'U') is not NULL
    drop table BankAcc

if object_id('Customers', 'U') is not NULL
    drop table Customers


create table Customers (
    CID INT PRIMARY key IDENTITY,
    CName VARCHAR(20),
    DoB DATE,
)

create table Cards (
    CAID INT PRIMARY KEY IDENTITY,
    CVV INT,
)
alter table Cards
add [Number] INT
create table BankAcc (
    BID INT PRIMARY KEY IDENTITY,
    IBAN VARCHAR(30),
    Holder VARCHAR(20),
    CID INT REFERENCES Customers(CID),
    CAID INT REFERENCES Cards(CAID)
)

create table ATMS (
    AID int PRIMARY key IDENTITY,
    [Address] VARCHAR(50)
)

create TABLE Transactions (
    TID int primary key IDENTITY,
    AID int REFERENCES ATMS(AID),
    SumW int,
    WTIME DATETIME,
    CAID int REFERENCES Cards(CAID)
)

insert into Customers VALUES('cus1', '1997-04-03')
insert into Cards VALUES(344, 12313), (123, 12345), (341, 85490), (573, 19239)
insert into BankAcc VALUES('asdsgf1412', 'h1', 1, 1), ('asdcasd1412', 'h1', 1, 2), ('gtsdfsffsd', 'h1', 1, 3), ('asdsad1412', 'h1', 1, 4)
insert into ATMS VALUES('acs'), ('asd'), ('cda')
insert into Transactions VALUES(1,213,'2016-03-04', 1), (2,123,'2016-03-04', 1), (3,2223,'2016-03-04', 1)
go
create or alter PROCEDURE uspDeleteTrans(@CARD INT)
AS
BEGIN
DECLARE @CardID INT = (SELECT CAID FRom Cards where dbo.[Cards].[Number] = @CARD)
delete from Transactions where CAID = @CardID
END
go
exec uspDeleteTrans 12313

GO
create or alter view vAllATMS
AS
SELECT C.[Number]
FROM Cards C
WHERE NOT EXISTS
(SELECT AID
FROM ATMS
EXCEPT
SELECT T.AID
FROM Transactions T
WHERE C.CAID = T.CAID)

GO
select * from vAllATMS

GO
create or alter function ufCeva()
RETURNS TABLE
AS
RETURN
SELECT C.[Number], c.CVV
FROM Cards C 
WHERE C.CAID IN 
(SELECT T.CAID
FROM Transactions T
GROUP BY T.CAID
HAVING SUM(T.SumW) > 2000)
GO

SELECT * from ufCeva()