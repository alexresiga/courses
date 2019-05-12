use StackOverflow
drop table if exists [Version]
CREATE TABLE Version
(
    VID INT NOT NULL
)
INSERT INTO [Version]
VALUES
    (0)

--a) modify column
GO
CREATE OR ALTER PROCEDURE D1
AS
BEGIN
    ALTER TABLE Communities
ALTER COLUMN Name VARCHAR(100)
    PRINT 'D1'
END
GO

CREATE OR ALTER PROCEDURE I1
AS
BEGIN
    ALTER TABLE Communities
    ALTER COLUMN Name VARCHAR(50)
    PRINT 'I1'
END
GO

--b) add column
CREATE OR ALTER PROCEDURE D2
AS
BEGIN
    ALTER TABLE Answers
    ADD Votes INT
    PRINT 'D2'
END
GO

CREATE OR ALTER PROCEDURE I2
AS
BEGIN
    ALTER TABLE Answers
    DROP COLUMN Votes
    PRINT 'I2'
END
GO

--c) default
CREATE OR ALTER PROCEDURE D3
AS
BEGIN
    ALTER TABLE Answers
    ADD CONSTRAINT df_Votes DEFAULT 0 for Votes
    PRINT 'D3'
END
GO

CREATE OR ALTER PROCEDURE I3
AS
BEGIN
    ALTER TABLE Answers
    DROP CONSTRAINT df_Votes
    PRINT 'I3'
END
GO

--d) primary key
CREATE OR ALTER PROCEDURE D4
AS
BEGIN
    ALTER TABLE Version
    ADD CONSTRAINT pk_Version PRIMARY KEY(VID)
    PRINT 'D4'
END 
GO

CREATE OR ALTER PROCEDURE I4
AS
BEGIN
    ALTER TABLE Version
    DROP CONSTRAINT pk_Version
    PRINT 'I4'
END
GO

--e) candidate key
CREATE OR ALTER PROCEDURE D5
AS
BEGIN
    ALTER TABLE Questions
    ADD CONSTRAINT uk_Questions UNIQUE(DateAdded)
    PRINT 'D5'
END
GO

CREATE OR ALTER PROCEDURE I5
AS
BEGIN
    ALTER TABLE Questions
    DROP CONSTRAINT uk_Questions
    PRINT 'I5'
END
GO

--g) create table
CREATE OR ALTER PROCEDURE D6
AS
BEGIN
    CREATE TABLE Jobs
    (
        JID INT PRIMARY KEY,
        Name VARCHAR(100),
        Salary INT NOT NULL,
        VID INT
    )
    PRINT 'D6'
END
GO

CREATE OR ALTER PROCEDURE I6
AS
BEGIN
    DROP TABLE Jobs
    PRINT 'I6'
END
GO

--f) foreign key
CREATE OR ALTER PROCEDURE D7
AS
BEGIN
    ALTER TABLE Jobs
    ADD CONSTRAINT fk_Jobs FOREIGN KEY (VID) REFERENCES Version (VID)
END
PRINT 'D7'
GO

CREATE OR ALTER PROCEDURE I7
AS
BEGIN
    ALTER TABLE Jobs
    DROP CONSTRAINT fk_Jobs
    PRINT 'I7'
END
GO

SET NOCOUNT ON
GO
CREATE OR ALTER PROCEDURE main
    @version INT
AS
BEGIN
    DECLARE @currentVersion INT
    SET @currentVersion = (SELECT VID
    FROM Version)

    IF @version > 7 OR @version < 0
    BEGIN
        RAISERROR('This is not a valid version', 10, 1)
        RETURN
    END
    IF @currentVersion = @version
    BEGIN
        RAISERROR('Current version', 10, 1)
        RETURN
    END
    PRINT 'Old version: ' + CAST(@currentVersion as VARCHAR(12))
    IF @currentVersion > @version
    BEGIN
        WHILE @currentVersion > @version
        BEGIN
            DECLARE @Undo  NVARCHAR(12)
            SET @Undo = N'I' + CAST(@currentVersion as [nvarchar](12))
            EXECUTE sp_executesql @Undo
            SET @currentVersion = @currentVersion - 1
        END
    END
    IF @currentVersion < @version
BEGIN
        SET @currentVersion = @currentVersion + 1
        WHILE @currentVersion <= @version
    BEGIN
            DECLARE @Query NVARCHAR(12)
            SET @Query = N'D' + CAST(@currentVersion as [nvarchar](12))
            EXECUTE sp_executesql @QUERY
            SET @currentVersion = @currentVersion + 1
        END
    END
    UPDATE [Version] SET VID = @version
    PRINT 'Current version: ' + CAST(@version as VARCHAR(12))
END
GO

EXEC main 7
