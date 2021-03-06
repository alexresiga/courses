 --a)modify column
ALTER TABLE Person
ALTER COLUMN City VARCHAR(100)

ALTER TABLE Person
ALTER COLUMN City VARCHAR(10)

--b)add column
ALTER TABLE Orders
ADD ODate DATE

ALTER TABLE Orders
DROP COLUMN ODate

--c)default
ALTER TABLE Orders
ADD CONSTRAINT df_DATE DEFAULT GETDATE() for ODate

ALTER TABLE Orders
DROP CONSTRAINT df_DATE

--d) primary key
ALTER TABLE Orders
ADD CONSTRAINT pk_Orders PRIMARY KEY(Oid)

ALTER TABLE Orders
DROP CONSTRAINT pk_Orders

--e) candidate key
ALTER TABLE Orders
ADD CONSTRAINT uk_Orders UNIQUE(Oid)

ALTER TABLE Orders
DROP CONSTRAINT uk_Orders

--f) foreign key

ALTER TABLE Orders
ADD CONSTRAINT fk_Orders FOREIGN KEY (Pid) REFERENCES Person(Pid)

ALTER TABLE Orders
DROP CONSTRAINT fk_Orders

--g) create table
CREATE TABLE Products(
    PRID INT PRIMARY KEY,
    Name VARCHAR(30),
    Quantity INT
)

DROP TABLE Products

--STORED PROCEDURES
GO
CREATE OR ALTER PROCEDURE A1
AS
BEGIN
ALTER TABLE Person
ALTER COLUMN City VARCHAR(100)
PRINT 'column modified'
END
GO

EXEC A1

GO
CREATE OR ALTER PROCEDURE main
@v INT
AS
BEGIN
DECLARE @p INT
SET @p = 0
END
GO
--CREATE TABLE VERSION (VID INT)
--EXEC MAIN 5 -> D1, D2, D3, D4, D5
--EXEC MAIN 7 -> D6, D7
--EXEC MAIN 3 -> I7, I6, I5, I4

