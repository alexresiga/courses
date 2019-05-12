create database practic29012016
go
use practic29012016
go


drop table if exists Comments
drop table if exists Grades
drop table if exists Tasks
drop table if exists Students
drop table if exists Groups

create table Groups(
	ID INT NOT NULL PRIMARY KEY IDENTITY(1, 1),
	GName VARCHAR(50)
)

create table Students(
	SID INT NOT NULL PRIMARY KEY IDENTITY(1, 1),
	SName VARCHAR(50),
	GID INT FOREIGN KEY REFERENCES Groups(ID)
)

create table Tasks(
	TID INT NOT NULL PRIMARY KEY IDENTITY(1, 1),
	TName VARCHAR(50)
)

create table Grades(
	GID INT NOT NULL PRIMARY KEY IDENTITY(1, 1),
	GValue INT,
	SID INT FOREIGN KEY REFERENCES Students(SID),
	TID INT FOREIGN KEY REFERENCES Tasks(TID)
)

create table Comments(
	CID INT NOT NULL PRIMARY KEY IDENTITY(1, 1),
	Status VARCHAR(50),
	GID INT FOREIGN KEY REFERENCES Grades(GID)
)

insert into groups values ('group1'), ('group2'), ('group3'), ('group4')
insert into students values ('student10', 3), ('student11', 1), ('student14', 4), ('student27', 4), ('student1089', 2), ('student6', 1)
insert into tasks values ('tasksA'), ('taskB'), ('taskC'), ('taskD'), ('taskE')
insert into Grades values (10, 1, 3), (9, 1, 4), (4, 6, 4), (5, 6, 1), (8, 2, 3), (9, 3, 2)
insert into Comments values ('opened', 1), ('opened', 2), ('opened', 4), ('closed', 6)
--3)
go
create or alter view showAllStudents
as
	SELECT DISTINCT S.*
	FROM Students S INNER JOIN Grades G ON G.SID = S.SID INNER JOIN Comments C ON C.GID = G.GID
	WHERE C.Status like 'opened'
go

create or alter view orderDescendingByNoOfGrades
as
	select top (100) s.SName, count(*) as noOfGrades
	from Students S inner join Grades g on g.SID = s.SID 
	group by s.SName
	order by noOfGrades desc
go


--4)
SELECT s.SName as StudentName, 
	   FinalGrade = (SELECT SUM(GValue)/COUNT(*) FROM Grades G WHERE G.SID = S.SID)
FROM Students s 

select * from students
select * from grades
select * from comments

select * from showAllStudents

--2)
go
create or alter procedure insertGrade
					 @studentName VARCHAR(50),
					 @groupName VARCHAR(50),
					 @taskName VARCHAR(50),
					 @gradeValue INT,
					 @commentStatus VARCHAR(50)
as
	DECLARE @groupId INT = (SELECT G.ID FROM Groups G WHERE G.GName = @groupName)
	IF @groupId is null
	BEGIN
		print 'group does not exist'
		return 1
	END
	DECLARE @studentId INT = (SELECT S.SID FROM Students S WHERE S.SName = @studentName AND S.GID = @groupId)
	IF @studentId is null
	BEGIN
		print 'student does not exist'
		return 1
	END
	DECLARE @taskId INT = (SELECT T.TID FROM Tasks T WHERE T.TName = @taskName)
	IF @taskId is null
	BEGIN
		print 'task does not exist'
		return 1
	END
	DECLARE @gradeId INT = (SELECT GR.GID FROM Grades GR WHERE GR.SID = @studentId AND GR.TID = @taskId)
	if @gradeId is null
	BEGIN
		insert into Grades values (@gradeValue, @studentId, @taskId)	
		print 'grade added to the database'
		SET @gradeId = (SELECT GR.GID FROM Grades GR WHERE GR.GValue = @gradeValue AND GR.SID = @studentId AND GR.TID = @taskId)
		insert into Comments values (@commentStatus, @gradeId)
		print 'comment added to the database'
	END
	else
	BEGIN
	    UPDATE Grades 
			SET GValue = @gradeValue
			WHERE GID = @gradeId AND SID = @studentId AND TID = @taskId
		print 'grade updated'
		insert into Comments values (@commentStatus, @gradeId)
		print 'comment added'
	END	 
go
select * from Groups
select * from students
select * from tasks
select * from grades
select * from comments

exec insertGrade 'student10', 'group3', 'tasksA', 10, 'opened'