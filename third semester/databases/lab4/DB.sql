drop table if exists grades
drop table if exists students
drop table if exists teachers
drop table if exists exams_groups
drop table if exists groups
drop table if exists exams
drop table if exists courses

create table teachers(
	tId INT IDENTITY(1, 1) not null PRIMARY KEY,
	tName VARCHAR(50)
)


create table students(
	sId INT IDENTITY(1, 1) not null PRIMARY KEY,
	sName VARCHAR(50),
	tId INT FOREIGN KEY REFERENCES teachers(tId)
)

create table grades(
	tId INT not null,
	sId INT not null,
	gVal INT,
	PRIMARY KEY (tId, sId),
	CONSTRAINT grades_tkk FOREIGN KEY(tId) REFERENCES teachers(tId),
	CONSTRAINT grades_skk FOREIGN KEY(sId) REFERENCES students(sId)
	
)

create table courses(
	cId INT IDENTITY(1, 1) NOT NULL PRIMARY KEY,
	cName VARCHAR(50),
	cTeacher VARCHAR(50)
)

create table exams(
	eId INT IDENTITY(1,1) NOT NULL PRIMARY KEY,
	cId INT FOREIGN KEY REFERENCES courses(cId),
	eHour INT NOT NULL,
	eDay VARCHAR(50),
	eRoom INT NOT NULL
)

create table groups(
	gId INT NOT NULL PRIMARY KEY
)
create table exams_groups(
	gId INT FOREIGN KEY REFERENCES groups(gId),
	eId INT FOREIGN KEY REFERENCES exams(eId)
)

INSERT INTO courses(cName,cTeacher) values ('MAP', 'Craciun Florin'),
										   ('PS', 'Micula Sanda'), ('PLF', 'Pop Horia'), ('CN', 'Darabant Adrian'), ('BD', 'Surdu Sabina')

INSERT INTO exams(cId, eHour, eDay, eRoom) values (1, 12, 'Monday', 321), (1,8,'Tuesday',402), (1,8,'Wednesday',308),(1,12,'Thursday',306), (1,12,'Friday',402),
												  (2,8,'Monday',7), (2,8,'Tuesday',7), (2,8,'Wednesday',6), (2,16,'Thursday',6), (2,16,'Friday',12), (2,12,'Saturday',9),
												  (3,8,'Monday',321), (3,12,'Tuesday',7), (3,16,'Wednesday',308), (3,8,'Thursday',306), (3,8,'Thursday',6), (3,8,'Friday',402),
												  (4,16,'Monday',321), (4,16,'Tuesday',7), (4,8,'Wednesday',402), (4,12,'Thursday',6), (4,8,'Friday',12),(4,8,'Saturday',9),
												  (5,12,'Monday',321), (5,12,'Tuesday',306), (5,8,'Wednesday',421), (5,12,'Wednesday',402), (5,12,'Thursday',421), (5,12,'Friday',12)

INSERT INTO groups(gId) values (921),(922),(923),(924),(925),(926),(927)

INSERT INTO exams_groups(gId, eId) values (921,4), (922,1), (923,5), (924,2), (925,2), (926, 3), (927,3),
									(921,7), (922,11), (923,9), (924,6), (925,10), (926,8), (927,8),
									(921,17), (922,17), (923,15), (924,12), (925,14), (926,13), (927,16),
									(921,22), (922,23), (923,19), (924,18), (925,19), (926,20), (927,21),
									(921,27), (922,28), (923,24), (924,24), (925,29), (926,25), (927,26)
