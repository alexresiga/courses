

CREATE OR ALTER PROCEDURE delete_table1
	@num_lines INT
AS
BEGIN
	DELETE FROM teachers WHERE
	tId in (SELECT TOP(@num_lines) tId FROM teachers ORDER BY tId DESC)
END
GO

CREATE OR ALTER PROCEDURE delete_table2
	@num_lines INT
AS
BEGIN
	DELETE FROM students WHERE
	tId in (SELECT TOP (@num_lines) tId FROM students ORDER BY tId DESC)

END
GO

CREATE OR ALTER PROCEDURE delete_table3
	@num_lines INT
AS
BEGIN
	DELETE FROM grades WHERE
	tId in (SELECT TOP (@num_lines) tId FROM grades ORDER BY tId DESC)
END
GO

CREATE OR ALTER PROCEDURE insert_table1
	@num_lines INT
AS
BEGIN
	DECLARE @i INT = 1
	WHILE @i <= @num_lines
		BEGIN
			INSERT INTO teachers(tName) VALUES ('Alexandra')
			SET @i = @i + 1
		END
END
GO

CREATE OR ALTER PROCEDURE insert_table2
	@num_lines INT
AS
BEGIN
	DECLARE @teacherId INT
	SELECT TOP (1) @teacherId = tId from teachers
	DECLARE @i INT = 1
	WHILE @i <= @num_lines
		BEGIN
			INSERT INTO students(sName, tId) VALUES ('Diana', @teacherId)
			SET @i = @i + 1
		END
END 
GO


CREATE OR ALTER PROCEDURE insert_table3
	@num_lines INT
AS
BEGIN
	DECLARE @i INT = 1
	DECLARE @teacherId INT
	DECLARE @studentId INT
	DECLARE @maxTeacherId INT

	SELECT @teacherId = MIN(tId) FROM teachers
	SELECT @studentId = MIN(sId) FROM students
	SELECT @maxTeacherId = MAX(tId) FROM teachers 
	WHILE @i <= @num_lines
		BEGIN
			INSERT INTO grades(tId,sId,gVal) VALUES(@teacherId, @studentId, 9)
			IF (@teacherId < @maxTeacherId)
				SET @teacherId = @teacherId + 1
			SET @i = @i + 1
		END
END 
GO

CREATE OR ALTER PROCEDURE select_table1
	@num_lines INT
AS
BEGIN
	SELECT TOP (@num_lines) * from teachers
END
GO

CREATE OR ALTER PROCEDURE select_table2
	@num_lines INT
AS
BEGIN
	SELECT TOP (@num_lines) * from students
END
GO

CREATE OR ALTER PROCEDURE select_table3
	@num_lines INT
AS
BEGIN
	SELECT TOP (@num_lines) * from grades
END
GO