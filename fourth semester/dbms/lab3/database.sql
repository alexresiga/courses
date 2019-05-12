create database Homework

use Homework


drop table if exists Assignments
drop table if exists Students
drop table if exists Teachers
SET NOCOUNT ON
create table Teachers(
	TID int primary key identity,
	TName varchar(20),
	TDepartment varchar(20)
)

create table Students(
	SID int primary key identity,
	SName varchar(20)
)

insert into Teachers values ('teacher1', 'Art'), ('teacher2', 'History'), ('teacher3', 'Science') 
insert into Students values ('Student1'), ('Student2'), ('Student3')

create table Assignments(
	TID int foreign key references Teachers,
	SID int foreign key references Students,
	primary key(TID, SID)
)
GO
create or alter function uf_validateTeachers(@name varchar(20), @department varchar(20)) returns int as
begin
	declare @return int
	set @return = 0
	if (@department in ('art', 'history', 'science') and @name <> '')
		set @return = 1
	return @return
end
go
create or alter function uf_validateStudents(@name varchar(20)) returns int as
begin
	declare @return int
	set @return = 0
	if (@name <> '')
		set @return = 1
	return @return
end
go
create or alter procedure addTeachers @name varchar(20), @department varchar(20) as
begin
	begin tran
		begin try
			if (dbo.uf_validateTeachers(@name, @department) <> 1)
				begin
					raiserror('Invalid input',14,1)
				end
			insert into Teachers values (@name, @department)
			commit tran
			PRINT 'transaction committed'
		end try
		begin catch
			rollback tran
			PRINT 'transaction rollbacked'
		end catch
end
go
exec addTeachers 'alex', 'art'
delete from Teachers where tid=5
select * from Teachers
go
create or alter procedure addAssignment @StudentsName varchar(20), @teacherName varchar(20), @teacherDepartment varchar(20) as
begin
    begin tran
		begin try
			if (dbo.uf_validateStudents(@StudentsName) <> 1)
				begin
					raiserror('Invalid input', 14, 1)
				end
			insert into Students values(@StudentsName)
			commit tran
			select 'transaction committed'
		end try
		begin catch
			rollback tran
			select 'transaction rollbacked'
		end catch
		
	begin tran
		begin try
			if (dbo.uf_validateTeachers(@teacherName, @teacherDepartment) <> 1)
				begin
					raiserror('Invalid input', 14, 1)
				end
			insert into Teachers values (@teacherName, @teacherDepartment)
			commit tran
			select 'transaction committed'
		end try
		begin catch
			rollback tran
			select 'transaction rollbacked'
		end catch
	
	begin tran
		declare @sid int = (select SID from Students where SName = @StudentsName)
		declare @tid int = (select TID from Teachers where TName = @teacherName and TDepartment = @teacherDepartment)
        if @sid is not null and @tid is not null
		    insert into Assignments values (@tid, @sid)
		commit tran
end
go



exec addAssignment 's7', 't7', 'art'