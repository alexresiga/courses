use Lab4
go

create or alter view view2
AS
	select top 1000 C.cName as CourseName, C.cTeacher as Teacher, E.eHour as StartingHour, E.eRoom as Room
	from courses C INNER JOIN exams E on C.cId = E.cId 
	where E.eDay like 'Tuesday' or E.eday like 'Sunday' 
	order by E.eHour


