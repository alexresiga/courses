use Lab4
go

create or alter view view3
AS
	select TOP 10 count(E.eId) as NoExams, E.eRoom
	from exams E, exams_groups EG
	where E.eId = EG.eId
	group by E.eRoom
	order by count(E.eId) DESC