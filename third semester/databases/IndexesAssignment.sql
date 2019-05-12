use Lab5
go

drop table if exists Delivery
drop table if exists Letters
drop table if exists Postmen
--table Ta
create table Postmen(
	pID INT PRIMARY KEY IDENTITY(1, 1),
	pName VARCHAR(50),
	pZone INT UNIQUE
)

--table Tb
create table Letters(
	lID INT PRIMARY KEY IDENTITY(1, 1),
	sender VARCHAR(50),
	recipient VARCHAR(50),
	lZone INT
)

--table Tc
create table Delivery(
	dID INT PRIMARY KEY IDENTITY(1, 1),
	pID INT FOREIGN KEY REFERENCES PostMen(pID),
	lID INT FOREIGN KEY REFERENCES Letters(lID)
)
select * from Postmen
select * from Letters
select * from Delivery

insert into Postmen values ('Alex', 2), ('Mircea', 3), ('Andrei', 1), ('Mircea', 4), ('Stefan', 5)
insert into Letters values ('Ioana', 'Renata', 2), ('Renata', 'Diana', 3), ('Ioana', 'Andrei', 1), ('Andrei', 'Antonia', 4), ('Andrei', 'Ioana', 1), ('Antonia', 'Diana', 3), ('Stefania', 'Paul', 2)
insert into Delivery values (1, 1), (1, 7), (2, 2), (2, 6), (3, 3), (3, 5), (4, 4)

--clustered index scan on table Postmen
SELECT PM.pID as ID, PM.pName as Name
FROM Postmen PM
ORDER BY PM.pId

--clustered index seek on table Postmen
SELECT PM.pName as Name, PM.pZone as Zone
FROM Postmen PM
WHERE PM.pID > 3

--nonclustered index scan on table Postmen
DROP INDEX if exists index_1_Postmen on Postmen
CREATE NONCLUSTERED INDEX index_1_Postmen on Postmen(pZone)
SELECT PM.pID, PM.pZone
FROM Postmen PM

--nonclustered index seek on table Postmen
SELECT PM.pID, PM.pZone
FROM Postmen PM 
--WITH (INDEX = index_1_Postmen)
WHERE pZone = 3

--key lookup on table Postmen
SELECT *
FROM Postmen PM
WHERE PM.pName like 'Mircea'
ORDER BY PM.pZone

--SELECT * FROM Postmen WITH (INDEX = index_1_Postmen)

--Write a query on table Tb with a WHERE clause of the form WHERE b2 = value 
--and analyze its execution plan. Create a nonclustered index that can speed up the query. 
--Recheck the query�s execution plan (operators, SELECT�s estimated subtree cost).

DROP INDEX IF EXISTS ix_lZone_Letters ON Letters

SELECT L.lZone
FROM Letters L
WHERE L.lZone = 2

CREATE NONCLUSTERED INDEX ix_lZone_Letters on Letters(lZone)

SELECT L.lZone 
FROM Letters L
WHERE L.lZone = 2

--Create a view that joins at least 2 tables. 
--Check whether existing indexes are helpful; if not, reassess existing indexes / examine the cardinality of the tables.


DROP INDEX IF EXISTS index_1_Postmen on Postmen
DROP INDEX IF EXISTS index_2_Letters on Letters

CREATE NONCLUSTERED INDEX index_2_Letters on Letters(recipient)
CREATE NONCLUSTERED INDEX index_1_Postmen on Postmen(pZone)
go
create or alter view LettersToDiana
as
	select PM.pName as PostManName, PM.pZone as Zone, L.sender as Sender
	from Postmen PM INNER JOIN Delivery D on D.pID = PM.pID  AND PM.pZone = 3
	INNER JOIN Letters L on L.lID = D.lID AND L.recipient like 'Diana'
go


select * from LettersToDiana

DROP INDEX IF EXISTS index_1_Postmen on Postmen
DROP INDEX IF EXISTS index_2_Letters on Letters
select * from LettersToDiana