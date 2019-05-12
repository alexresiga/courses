use StackOverflow
CREATE TABLE Tea (
    CID int primary key IDENTITY,
    Name Varchar(50),
    price int)

insert into Tea VALUES ('Menta', 8), ('Ghimbir', 10), ('Tei', 9), ('Negru', 15)
select * from Tea
order by CID

select * from sys.indexes

if exists (select name from sys.indexes where name='N_idx_Tea_Name')
drop index N_idx_Tea_Name on Tea

create NONCLUSTERED index N_idx_Tea_Name
on Tea(Name)

select * from Tea
order by Name
