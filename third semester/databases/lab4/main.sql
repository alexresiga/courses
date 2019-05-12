--main
USE Lab4
GO

--insert tables to test
INSERT INTO Tables(Name) VALUES
	('grades'),
	('students'),
	('teachers')
GO


--insert views
INSERT INTO Views(Name) VALUES
	('view1'),
	('view2'),
	('view3')
GO


--insert tests
INSERT INTO Tests(Name) VALUES
	('insert_table1'),
	('insert_table2'),
	('insert_table3'),
	('select_table1'),
	('select_table2'),
	('select_table3'),
	('delete_table3'),
	('delete_table2'),
	('delete_table1')

INSERT INTO TestViews(TestID, ViewID) VALUES
(1, 1),
(2, 2),
(3, 3)

INSERT INTO TestTables(TestID, TableID, NoOfRows, Position)
VALUES
(1, 3, 100, 1),
(2, 2, 1000, 2),
(3, 1, 500, 3),
(7, 1, 500, 4),
(8, 2, 1000, 5),
(9, 3, 100, 6)
GO


CREATE OR ALTER PROCEDURE run_tests
AS
BEGIN

	DELETE FROM TestRuns
	DELETE FROM TestRunTables
	DELETE FROM TestRunViews


	DECLARE @tableId INT = 1
	DECLARE @posMax INT
	DECLARE @testStartDate DATETIME
	DECLARE @testEndDate DATETIME
	DECLARE @procName VARCHAR(64)
	DECLARE @numRows INT

	SELECT TOP (1) @numRows = NoOfRows 
	FROM TestTables

	SELECT @posMax = MAX(TableID) FROM TestTables
	

	WHILE @tableId <= @posMax
		BEGIN
			
			DECLARE @startTableTest DATETIME = getDate()
			SET @testStartDate = @startTableTest

			DECLARE @insPos INT

			SELECT @insPos = Position
			FROM TestTables
			WHERE TableID = @tableId

			--do all inserts to current table
			DECLARE @currIndex INT = 1

			WHILE @currIndex <=  @insPos
				BEGIN
				
				--take testID for every Index
				DECLARE @testInsertID INT
				SELECT @testInsertID = TestID 
				FROM TestTables
				WHERE Position = @currIndex

				--take procedure name

				SELECT @procName = Name
				FROM Tests
				WHERE @testInsertID = TestID

				--PRINT @procName
				EXEC @procName @numRows
				
				SET @currIndex = @currIndex + 1
				END
			

			--For Delete
			DECLARE @deletePos INT

			SELECT @deletePos = MAX(Position)
			FROM TestTables
			WHERE @tableId = TableID

			DECLARE @deleteIndex INT = @posMax
			--make all deletes till our insert

			WHILE @deleteIndex > @deletePos
				BEGIN
				DECLARE @testDeleteId INT

				SELECt @testDeleteId = TestId
				FROM TestTables
				WHERE Position = @deleteIndex

				SELECT @procName = Name
				FROM Tests
				WHERE @testDeleteId = TestID

				--PRINT @procName

				EXEC @procName @numRows
				SET @deleteIndex = @deleteIndex - 1
				END

			DECLARE @endTableTest DATETIME = getDate()
			--PRINT DATEDIFF(ms, @startTableTest, @endTableTest)

			DECLARE @startViewTest DATETIME = getDatE()

			--TEST VIEWS
			DECLARE @view INT

			SELECT @view = ViewID
			FROM TestViews
			WHERE ViewID = @tableId

			DECLARE @viewName VARCHAR(64)
			SELECT @viewName = Name
			FROM Views
			WHERE @view = ViewID
			
			DECLARE @querry VARCHAR(64) = 'SELECT * FROM ' + @viewName
			
			EXECUTE (@querry)

			DECLARE @endViewTest DATETIME = getDate()
			--PRINT DATEDIFF(ms, @startViewTest, @endViewTest)
			
			SET @testEndDate = @endViewTest

			--SET TEST TABLES
			DECLARE @testDesc VARCHAR(64) = 'TEST ON TABLE ' + CONVERT(VARCHAR(4), @tableId)
			INSERT INTO TestRuns(Description, StartAt, EndAt) VALUES (@testDesc, @testStartDate, @testEndDate)

			DECLARE @lastTestRun INT

			SELECT @lastTestRun = MAX(TestRunID)
			FROM TestRuns

			INSERT INTO TestRunTables(TestRunID, TableID, StartAt, EndAt) VALUES (@lastTestRun, @tableId, @startTableTest, @endTableTest)

			INSERT INTO TestRunViews(TestRunID, ViewID, StartAt, EndAt) VALUES (@lastTestRun, @view, @startViewTest, @endViewTest)

			PRINT  @deleteIndex

			SET @tableId = @tableId + 1

		END

END
GO

SET NOCOUNT ON
GO
EXEC run_tests

SELECT * FROM TestRunTables
SELECT * FROM TestRunViews

SELECT * FROM students
SELECT * FROM teachers
SELECT * FROM grades

EXEC insert_table1 10
EXEC insert_table2 10
EXEC insert_table3 10

EXEC delete_table3 10
EXEC delete_table2 10
EXEC delete_table1 10
