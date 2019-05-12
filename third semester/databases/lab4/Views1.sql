use Lab4
go 

create or alter view view1
AS
	select E.eId, E.eDay,E.eRoom
	from exams E
	where E.eHour = 12


