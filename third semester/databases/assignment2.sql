use StackOverflow
INSERT INTO Communities VALUES (1, 'Programmers', 'Community dedicated for programmers'), (2, 'Moderators', 'Community for moderators'), (3, 'Students', 'Community dedicated for students')

INSERT INTO Users VALUES (130, 'Alex Resiga', 'lxrsg', 'resiga.alex@gmail.com', 3), (171, 'John Doe', 'johnd', 'john.doe@gmail.com', 2), (258, 'Mark Hoppus', 'blink', 'rock_mark@gmail.com', 1), (299, 'Oli Sykes', 'bmth', 'olyy.bmth@gmail.com', 1)

INSERT INTO Users VALUES (362, 'Alex Turner','aturner','alext@gmail.com', 2),
						 (364, 'Martin Soderstrom','martinS','soder@gmail.com', 2),
						 (448, 'Nick O''Maley','niky','nick@gmail.com', 1),
						 (460, 'Jamie Cook','pythonLover121','pythoneer@gmail.com', 2),
						 (675, 'Matt Helders','mattDrums','amRocks@gmail.com', 3),
						 (736, 'Mark Zucc','zuccifer','marky@gmail.com', 2),
						 (750, 'Matei Stroia','matystroia','matystroia@gmail.com', 1),
						 (757, 'Borza Andrei','borzescu','borza@gmail.com', 3),
						 (814, 'Alex Lup','wolFF','lup@gmail.com', 3),
						 (890, 'Miruna Vasiu','cotisel','radubogdan@gmail.com', 3)
INSERT INTO Users VALUES (965, 'Dorian Popa', 'HATZ', 'hatz@gmail.com', 2)
--violates primary key constraint
INSERT INTO Users VALUES (130, 'Matei Stroia', 'matystroia', 'matystroia@gmail.com', 3)

INSERT INTO Topics VALUES (1, 'python', 'questions regarding python'), (2, 'sql', 'sql questions'), (3, 'webdev', 'webdev discussion')

INSERT INTO  Tags VALUES (24, 'python'), (65, 'c++'), (96, 'php'), (57, 'angular'), (21, NULL), (36, NULL)

UPDATE Communities
SET Name = 'DEVELOPERS'
WHERE Name like 'P%'

SELECT * FROM Comments

UPDATE Users
SET COMID = 1
WHERE Username LIKE 'b%' AND UID > 500

UPDATE Questions
SET Title = 'QUESTION TITLE 4'
WHERE UID BETWEEN 200 AND 2000 AND QID = 345

UPDATE Questions
SET UID = 231
WHERE QID = 355

DELETE FROM Questions
WHERE UID IN (1323, 100, 1233)

DELETE FROM Tags
WHERE Name is not null and Name like 'p_p'
-- question ids that have 'css' in the title or answer ids that are good
SELECT Q.UID
FROM Questions Q
WHERE Q.Title LIKE '%css%'
UNION
SELECT A.UID
FROM Answers A
WHERE A.Content LIKE '%good%'

-- users that have usernames starting with b or community id = 1
SELECT Name
FROM Users
WHERE Username LIKE 'b%' OR COMID = 1

-- users that have also posted questions and answer questions as well
SELECT U.Email
FROM USERS U, Questions Q
WHERE U.UID = Q.UID
INTERSECT
SELECT U2.Email
FROM Users U2, Answers A
WHERE U2.UID = A.UID

--user names that asked question from topic 1 or 2
SELECT DISTINCT U.Name
FROM Users U, Questions Q
WHERE U.UID = Q.UID AND Q.TopicID IN (1, 2)

--users that asked question about c++ but not about python
SELECT *
FROM Users U1, Questions Q1
WHERE U1.UID = Q1.UID AND Q1.Title LIKE '%c++%'
EXCEPT
SELECT *
FROM Users U2, Questions Q2
WHERE U2.UID = Q2.UID AND Q2.Title LIKE '%python%'

-- COMMENTS TO ANSWERS THAT WERE NOT MADE BY USERS 736, 130, 757, 890
SELECT  C.Content, C.UID*2+14 as just_why
FROM Answers A, Comments C
WHERE C.AID = A.AID AND C.UID NOT IN (736, 130, 757, 890)

-- users that answered other users' questions
SELECT U.UID
FROM Users U INNER JOIN Questions Q ON U.UID = Q.UID INNER JOIN Answers A ON Q.QID = A.QID
GROUP BY U.UID

-- users who answered questions
INSERT INTO Users VALUES (100, 'TEST', 'TEST', 'TEST', 1)
SELECT DISTINCT *
FROM Users U LEFT JOIN Answers A ON U.UID = A.UID

-- comments on answers
SELECT *
FROM Comments RIGHT JOIN Answers ON Comments.AID = Answers.AID

-- users who answered questions
SELECT *
FROM Users U FULL OUTER JOIN Answers A ON U.UID = A.UID

--2 many to many relationships
INSERT INTO QuestionsTags VALUES (1035, 36), (1398, 24), (1035, 24), (4268, 57), (1398, 57), (2077, 36), (4268, 96), (2220, 36), (2220, 24), (2220, 57), (1607, 65), (2622, 36)
INSERT INTO Badges VALUES (10, 'power user', 2), (11, 'moderator', 3), (12, 'spectator', default), (13, 'geek', 4), (14, 'commentator', 3)
INSERT INTO Awards VALUES (10, 364), (10, 460), (11, 965), (13, 965), (14, 965), (13, 757), (12, 757), (10, 130), (10, 258), (12, 364), (12, 460), (12, 299), (13, 448), (11, 258)

-- BADGES TITLES OF EACH QUESTIONS TAGS
SELECT B.Title, T.Name
FROM Badges B FULL OUTER JOIN Awards AW ON B.BID = AW.BID FULL OUTER JOIN Users U ON U.UID = AW.UID INNER JOIN Questions Q ON Q.UID = U.UID FULL OUTER JOIN QuestionsTags QT ON Q.QID = QT.QID FULL OUTER JOIN Tags T ON T.TID = QT.TID

--e
-- questions which have month in answers' month
SELECT Q.Title
FROM Questions Q
WHERE MONTH(Q.DateAdded) IN (SELECT MONTH(A.DateAdded) FROM Answers A)

-- answers which year is in years of comments made by user community 
SELECT DISTINCT A.QID
FROM Answers A
WHERE YEAR(A.DateAdded) IN (SELECT YEAR(C.DateAdded) FROM Comments C WHERE C.UID IN (SELECT UID FROM Users WHERE Users.COMID = 2))

--f
-- users with comid >=2 and there are questions which have answers 
SELECT U.Username
FROM Users U
WHERE U.COMID >=2 AND EXISTS (SELECT * FROM Questions Q, Answers A WHERE Q.QID = A.QID)

-- topic names that appear in questions
SELECT T.Name
FROM Topics T
WHERE EXISTS (SELECT * FROM Questions Q WHERE Q.TopicID = T.TopicID)

--g
-- questions content which have tags 
SELECT DISTINCT A.Content
FROM (SELECT Q.Content FROM QuestionsTags QT RIGHT JOIN Questions Q ON QT.QID = Q.QID) A

-- communitites of users which emails' containt letter t
SELECT DISTINCT B.[Description]
FROM (SELECT C.[Description] FROM Communities C INNER JOIN Users U ON C.COMID = U.COMID WHERE U.Email LIKE '%t%') B

--H
-- 
SELECT U.Name, AVG(A.QID)/44 AS MEDIAN
FROM Users U INNER JOIN Answers A ON U.UID = A.UID
GROUP BY U.Name

SELECT U.Email, AVG(A.QID) AS CEVA_MEDIE
FROM Users U INNER JOIN Answers A ON U.UID = A.UID
GROUP BY U.Email
HAVING AVG(A.QID) < 3000

SELECT  U.Username, COUNT(*)
FROM Users U INNER JOIN Questions Q ON U.UID = Q.UID
GROUP BY U.Username
HAVING COUNT(*) <ANY(SELECT U.COMID FROM Users U WHERE U.Name LIKE '_o%')

SELECT TOP 5 A.QID, A.UID, MAX(A.DateAdded) AS LATEST_POST
FROM Answers A INNER JOIN  Users U ON U.UID = A.UID
GROUP BY A.QID, A.UID
HAVING A.UID IN (SELECT U.UID FROM Users U WHERE U.COMID=1)

-- LATEST POST DATE OF USERS WHO COMMENTED ON AT LEAST 5 ANSWERS IN THE CURRENT YEAR AND HAVE AT LEAST 2 RANK 3 BADGES
SELECT US.UID, B.Rank
FROM (SELECT D.UID, COUNT(*) AS TOTAL_COMMENTS
FROM (SELECT U.UID FROM Users U INNER JOIN Comments C ON U.UID = C.UID WHERE YEAR(C.DateAdded) = 2012) D
GROUP BY D.UID
HAVING COUNT(*) >= 2) US INNER JOIN Awards AW ON US.UID = AW.UID INNER JOIN Badges B ON AW.BID = B.BID WHERE B.Rank = 3

--i
SELECT Q.Title
FROM Questions Q
WHERE Q.QID <ALL(SELECT Q.QID FROM Questions Q WHERE Q.Content LIKE '%loops%')

SELECT Q.Title, Q.Content
FROM Questions Q
WHERE Q.QID < (SELECT MIN(Q.QID) FROM Questions Q WHERE Q.Content LIKE '%loops%')

SELECT C.CID, C.Content
FROM Comments C
WHERE C.DateAdded >ANY(SELECT A.DateAdded FROM Answers A WHERE A.AID = C.AID)

SELECT C.CID, C.Content
FROM Comments C
WHERE C.DateAdded >(SELECT MIN(A.DateAdded) FROM Answers A WHERE A.AID = C.AID)

SELECT A.Content, A.DateAdded
FROM Answers A
WHERE A.QID <>ALL(SELECT Q.QID FROM Questions Q WHERE YEAR(A.DateAdded) = YEAR(Q.DateAdded))
ORDER BY A.DateAdded

SELECT A.Content, A.DateAdded
FROM Answers A
WHERE A.QID NOT IN (SELECT Q.QID FROM Questions Q WHERE YEAR(A.DateAdded) = YEAR(Q.DateAdded))
ORDER BY A.DateAdded

SELECT TOP 3 U.Name, (A.BID+5)/6 as non_sense
FROM Users U INNER JOIN Awards A ON U.UID = A.UID
WHERE A.BID =ANY(SELECT B.BID FROM Badges B INNER JOIN Awards AW ON B.BID = AW.BID WHERE U.UID = AW.UID)
ORDER BY A.BID DESC

SELECT TOP 5 U.Name, A.BID
FROM Users U INNER JOIN Awards A ON U.UID = A.UID
WHERE A.BID IN (SELECT B.BID FROM Badges B INNER JOIN Awards AW ON B.BID = AW.BID WHERE U.UID = AW.UID)
ORDER BY A.BID DESC

INSERT INTO Questions VALUES (1004, 'one problem with css', 'monkey skips c++ crazily.', '2001-01-29 15:53:53.736', 675, 2),
(1032, 'another problem with c++', 'ide skips html merrily.', '2001-05-23 06:41:57.757', 736, 1),
(1035, 'another question with c++', 'girl lags c++ occasionally.', '2009-06-02 13:58:23.258', 130, 1),
(1047, 'some problem with css', 'girl skips html crazily.', '2008-10-15 07:37:37.364', 965, 3),
(1255, 'one issue with c', 'coder loops java dutifully.', '2003-03-21 16:01:05.460', 675, 1),
(1398, 'some question with c', 'girl wont run python dutifully.', '2004-11-07 21:43:49.171', 736, 2),
(1598, 'another question with css', 'monkey crashes html occasionally.', '2007-01-14 16:27:13.362', 890, 3),
(1607, 'some question with c++', 'programmer loops php foolishly.', '2009-03-23 04:17:08.364', 736, 3),
(1660, 'another problem with java', 'programmer lags html foolishly.', '2002-04-11 16:03:36.299', 736, 2),
(1713, 'another question with html', 'girl wont run html merrily.', '2002-04-09 17:24:17.757', 130, 3),
(1940, 'another question with html', 'girl loops c++ dutifully.', '2016-10-13 21:37:12.814', 890, 2),
(2077, 'some problem with html', 'girl crashes java crazily.', '2007-05-08 21:05:31.814', 965, 3),
(2089, 'one problem with python', 'ide lags php crazily.', '2011-10-24 11:22:56.171', 258, 2),
(2212, 'one problem with c', 'programmer wont run python foolishly.', '2008-08-18 10:03:27.675', 965, 3),
(2220, 'some question with css', 'ide loops python dutifully.', '2012-03-11 06:32:50.814', 299, 3),
(2245, 'one question with python', 'coder crashes html occasionally.', '2007-12-04 21:38:49.736', 750, 1),
(2350, 'another question with java', 'girl crashes html crazily.', '2018-11-01 02:50:08.364', 171, 2),
(2474, 'one question with css', 'girl wont run java foolishly.', '2002-09-19 15:41:02.362', 448, 2),
(2508, 'another problem with html', 'girl crashes python crazily.', '2002-08-17 10:59:40.750', 736, 3),
(2520, 'another question with html', 'girl wont run c++ crazily.', '2006-11-22 19:30:09.460', 171, 3),
(2622, 'some issue with java', 'coder skips python merrily.', '2012-04-09 17:36:54.171', 890, 2),
(2653, 'one question with c', 'programmer loops python occasionally.', '2012-02-17 15:20:33.299', 675, 1),
(2689, 'one issue with c', 'girl loops python foolishly.', '2012-07-25 02:38:52.299', 364, 2),
(2762, 'another problem with c', 'monkey loops c++ dutifully.', '2003-06-30 20:35:15.814', 258, 3),
(2970, 'some issue with python', 'ide loops html occasionally.', '2009-06-21 07:12:08.448', 448, 2),
(3044, 'one question with java', 'monkey skips java merrily.', '2002-09-10 21:50:10.299', 299, 3),
(3046, 'one question with html', 'programmer crashes python merrily.', '2007-01-12 13:48:50.965', 448, 2),
(3286, 'some question with c++', 'ide skips java occasionally.', '2007-02-26 18:07:32.364', 757, 2),
(3436, 'some question with c++', 'coder crashes python crazily.', '2010-10-28 05:40:24.171', 965, 3),
(3468, 'one issue with c++', 'programmer lags php occasionally.', '2010-03-16 01:44:35.299', 814, 3),
(3480, 'some question with c', 'coder crashes python foolishly.', '2013-01-26 19:21:35.258', 364, 3),
(3513, 'another problem with css', 'coder wont run c++ foolishly.', '2004-08-13 22:33:53.130', 814, 3),
(3581, 'another question with css', 'coder skips java dutifully.', '2006-08-07 03:44:27.130', 814, 3),
(3593, 'some question with python', 'programmer crashes html dutifully.', '2008-08-05 16:17:39.364', 448, 1),
(3682, 'one problem with css', 'monkey crashes c++ foolishly.', '2013-01-14 03:16:34.750', 750, 2),
(3748, 'another problem with css', 'ide loops c++ merrily.', '2001-08-20 03:28:36.364', 736, 1),
(3890, 'some issue with c', 'coder wont run php crazily.', '2011-06-15 21:37:09.258', 364, 3),
(3946, 'one issue with java', 'programmer wont run html merrily.', '2004-01-09 18:33:49.965', 890, 2),
(4033, 'some issue with python', 'programmer skips php occasionally.', '2001-09-02 18:03:44.448', 130, 2),
(4051, 'some issue with c', 'programmer wont run python dutifully.', '2015-01-24 08:34:53.890', 675, 3),
(4132, 'one question with java', 'ide wont run php occasionally.', '2001-01-23 00:50:03.814', 130, 3),
(4268, 'another problem with css', 'ide wont run python occasionally.', '2017-06-10 00:10:34.364', 171, 2),
(4361, 'one issue with python', 'monkey loops c++ crazily.', '2016-09-08 23:46:38.362', 460, 3),
(4389, 'one question with java', 'programmer crashes html crazily.', '2014-06-06 05:04:35.362', 258, 1),
(4392, 'some issue with html', 'coder loops c++ merrily.', '2016-05-24 02:19:35.299', 965, 1),
(4446, 'some issue with c++', 'girl wont run html occasionally.', '2007-04-14 07:35:50.258', 890, 1),
(4517, 'one problem with java', 'monkey lags html dutifully.', '2006-03-22 10:05:59.130', 130, 3),
(4593, 'some problem with css', 'coder lags java occasionally.', '2014-03-10 09:44:33.130', 736, 2),
(4779, 'another problem with css', 'monkey wont run java crazily.', '2004-03-30 16:43:00.362', 965, 1),
(4803, 'some problem with css', 'programmer crashes php crazily.', '2016-01-23 22:34:34.299', 675, 1)

INSERT INTO Answers VALUES (11196, 'another solution for python', '2002-05-11 03:04:37.448', 814, 3436),
(12037, 'some idea for c', '2001-03-28 00:07:07.364', 675, 3682),
(12297, 'one idea for python', '2006-01-17 01:30:11.757', 814, 3480),
(13494, 'some idea for c++', '2000-12-20 09:29:34.460', 364, 3468),
(13539, 'another useful for c', '2017-02-15 05:37:47.890', 814, 1255),
(13611, 'some useful for html', '2014-04-09 07:03:31.890', 448, 3468),
(14126, 'some useful for java', '2015-08-04 00:15:34.299', 890, 3748),
(14407, 'one fix for python', '2010-10-07 04:16:28.757', 258, 2077),
(14799, 'one idea for python', '2000-09-13 20:24:50.890', 814, 4803),
(15129, 'another idea for c', '2007-02-07 05:06:52.448', 890, 2474),
(15605, 'another idea for java', '2008-01-09 01:03:40.814', 171, 4779),
(15651, 'one idea for css', '2018-04-25 06:06:55.757', 736, 3513),
(15765, 'some fix for c', '2005-08-20 17:34:26.736', 299, 3890),
(15777, 'another useful for java', '2010-01-03 09:55:17.736', 965, 1047),
(15915, 'one fix for html', '2005-05-02 12:29:52.448', 814, 3513),
(18263, 'one idea for c++', '2009-11-23 06:01:53.757', 362, 3480),
(19376, 'another useful for python', '2003-10-05 10:26:36.299', 675, 3581),
(20048, 'one solution for html', '2002-05-03 21:20:30.750', 757, 1035),
(22005, 'another useful for java', '2018-03-11 07:41:10.448', 757, 2520),
(22611, 'some solution for c', '2011-02-12 13:31:54.364', 362, 2212),
(22909, 'some useful for java', '2003-06-02 13:35:50.750', 965, 2970),
(24143, 'some useful for css', '2010-05-31 10:25:02.814', 460, 2520),
(24788, 'one idea for python', '2013-11-04 20:52:33.171', 460, 4803),
(24848, 'some fix for java', '2007-09-12 08:06:20.448', 448, 1713),
(25438, 'another solution for python', '2015-12-01 18:00:34.675', 364, 2245),
(27087, 'one solution for c', '2005-11-21 00:13:22.675', 814, 1255),
(28084, 'one idea for c', '2003-03-15 22:03:39.299', 675, 2508),
(28318, 'another idea for python', '2005-08-01 06:05:07.965', 364, 3044),
(28405, 'some fix for css', '2001-01-16 14:59:11.460', 130, 2089),
(32163, 'one solution for css', '2012-01-14 12:38:05.364', 364, 3946),
(33046, 'some fix for c', '2001-09-11 19:11:36.814', 965, 1607),
(34361, 'some fix for c', '2000-10-25 14:42:39.750', 362, 2689),
(35334, 'some idea for css', '2015-12-11 13:17:35.362', 299, 1255),
(37766, 'another useful for html', '2003-08-04 18:45:29.757', 965, 2970),
(38935, 'one fix for python', '2005-07-17 12:12:14.362', 675, 3286),
(40635, 'one idea for java', '2008-06-03 00:25:42.460', 258, 3682),
(41223, 'another fix for c', '2001-09-25 00:12:28.299', 675, 2762),
(41809, 'another useful for c', '2003-11-29 05:40:16.736', 364, 3046),
(43579, 'some solution for python', '2012-01-07 02:53:39.258', 965, 2245),
(44312, 'some fix for java', '2004-04-10 21:07:20.750', 362, 3946),
(44528, 'some solution for css', '2001-10-23 13:15:36.814', 171, 4446),
(45415, 'one fix for css', '2017-03-07 00:40:14.736', 299, 4593),
(46166, 'another useful for java', '2003-07-22 23:15:14.448', 965, 2520),
(46652, 'another fix for python', '2012-07-26 08:23:05.130', 299, 2220),
(47775, 'another fix for java', '2011-05-30 04:36:31.362', 448, 3593),
(48926, 'one solution for java', '2001-05-02 06:53:05.448', 130, 4051),
(49039, 'one fix for css', '2016-10-28 09:45:20.675', 675, 1660),
(49140, 'another fix for html', '2009-08-22 10:20:29.890', 736, 4446),
(49819, 'another useful for python', '2010-12-10 15:07:10.675', 299, 2508),
(50375, 'another useful for c', '2000-12-30 14:36:03.965', 814, 2212),
(50597, 'one idea for python', '2012-04-05 02:27:51.965', 130, 4389),
(51928, 'one idea for html', '2009-10-18 22:03:18.736', 364, 1047),
(52098, 'some fix for python', '2003-04-11 01:08:02.362', 171, 4593),
(52798, 'one fix for css', '2010-07-02 14:44:56.258', 890, 2653),
(54879, 'one solution for java', '2014-03-23 00:52:00.890', 299, 4389),
(56141, 'another idea for css', '2006-07-06 23:39:11.299', 965, 3480),
(56704, 'one fix for html', '2003-08-25 00:15:42.171', 675, 2520),
(57729, 'some fix for css', '2012-09-05 18:10:01.171', 736, 3468),
(58746, 'some solution for c++', '2003-04-05 09:15:47.814', 171, 3480),
(59547, 'some fix for c', '2001-01-26 08:24:33.362', 675, 2689),
(60611, 'one useful for python', '2005-09-05 05:07:25.171', 736, 1398),
(60814, 'another useful for python', '2003-05-29 23:19:54.750', 258, 1598),
(62192, 'one idea for c++', '2017-02-22 14:39:23.890', 299, 2520),
(63589, 'some useful for c++', '2011-07-06 21:11:41.448', 448, 2762),
(66685, 'some solution for c', '2011-11-21 12:45:18.171', 460, 3513),
(67160, 'another fix for python', '2002-01-21 22:13:07.448', 965, 3468),
(67306, 'another solution for c', '2012-04-19 18:07:04.130', 362, 3682),
(68569, 'one solution for css', '2018-03-03 22:45:43.814', 362, 4389),
(70324, 'another idea for c', '2014-11-15 17:15:07.750', 460, 4446),
(70589, 'another useful for html', '2010-09-07 17:18:38.890', 448, 4392),
(70719, 'one solution for c++', '2011-02-07 21:34:27.362', 460, 4268),
(71376, 'one useful for java', '2000-05-06 20:15:39.750', 750, 2520),
(71600, 'another solution for java', '2000-10-05 21:11:04.362', 364, 1004),
(72745, 'another idea for css', '2004-10-18 22:22:21.130', 258, 2508),
(73254, 'another idea for css', '2009-05-30 18:32:19.171', 258, 2653)

INSERT INTO Comments VALUES (539376, 'another not useful idea question c++', '2005-05-02 03:13:42.890', 49140, 362),
(723554, 'another not useful solution question css', '2006-10-25 01:01:17.364', 24788, 814),
(348771, 'one bad fix question python', '2009-07-27 08:01:38.171', 67160, 171),
(939094, 'another not useful solution problem c', '2002-07-27 18:24:36.965', 63589, 965),
(191249, 'some horrible useful issue html', '2000-11-14 04:18:21.757', 15915, 448),
(451070, 'another not useful idea problem c', '2017-06-08 10:20:08.736', 15129, 890),
(242337, 'another not useful fix problem html', '2007-04-17 07:49:51.675', 43579, 130),
(878954, 'one not useful idea question python', '2016-07-21 15:53:48.364', 49819, 750),
(545020, 'one not useful solution issue c++', '2013-02-16 10:51:43.965', 70719, 448),
(514983, 'some bad idea question java', '2016-08-24 09:17:03.460', 37766, 757),
(228683, 'some horrible idea problem python', '2017-03-14 04:37:26.258', 14126, 757),
(545502, 'some bad solution problem c', '2005-04-23 10:00:12.258', 15915, 448),
(793384, 'another bad useful issue python', '2010-09-28 11:52:38.736', 60814, 757),
(109189, 'one bad idea issue c', '2002-06-28 10:59:29.448', 56704, 736),
(890127, 'one bad idea problem java', '2007-06-07 13:39:38.890', 68569, 736),
(483484, 'another bad fix problem c', '2013-09-11 05:23:36.460', 22611, 364),
(327601, 'some not useful idea problem c++', '2011-01-25 09:29:11.965', 73254, 130),
(153644, 'one not useful fix question python', '2002-08-05 19:31:35.736', 12297, 299),
(779949, 'one not useful fix issue java', '2009-07-02 13:44:47.736', 49140, 130),
(399846, 'one not useful fix issue c++', '2006-09-23 14:23:16.736', 49819, 750),
(377432, 'one bad fix problem python', '2005-03-26 12:08:42.736', 60611, 130),
(174802, 'another bad idea issue html', '2012-05-24 06:37:36.965', 54879, 171),
(959221, 'some not useful useful question c', '2006-04-06 13:33:16.965', 13539, 448),
(684630, 'another bad fix problem html', '2015-08-08 04:29:59.362', 28084, 736),
(100149, 'one horrible solution problem c', '2012-05-28 10:35:20.171', 57729, 171),
(834839, 'one horrible useful question html', '2006-05-30 08:53:59.299', 12037, 130),
(590971, 'some not useful idea question html', '2013-01-26 21:15:44.814', 73254, 130),
(252912, 'another horrible useful problem c++', '2012-01-09 13:45:16.750', 50375, 130),
(835202, 'one horrible idea question java', '2006-08-07 03:28:34.364', 37766, 675),
(330500, 'one horrible fix problem c++', '2013-08-20 06:22:02.362', 63589, 364),
(960802, 'some not useful solution question c++', '2013-04-10 11:24:29.171', 66685, 171),
(202502, 'some not useful idea issue c++', '2001-06-21 00:40:56.757', 58746, 362),
(981876, 'another horrible solution problem java', '2005-06-05 02:37:46.258', 40635, 448),
(238138, 'another not useful useful issue c', '2003-08-16 21:19:33.750', 20048, 675),
(820561, 'some horrible solution problem css', '2004-05-15 21:22:16.171', 28084, 675),
(545689, 'another horrible solution problem java', '2017-05-14 04:21:59.364', 15915, 460),
(851141, 'one not useful fix problem python', '2013-07-22 01:58:13.258', 15605, 299),
(418641, 'one horrible useful problem java', '2016-06-02 15:36:51.130', 24848, 299),
(468343, 'another not useful useful problem c', '2012-03-12 02:53:53.675', 51928, 299),
(996495, 'another not useful useful question c', '2011-09-03 13:41:02.258', 44528, 171),
(382940, 'another not useful fix question c++', '2011-04-04 00:36:01.364', 28084, 736),
(831060, 'one bad solution problem html', '2010-06-16 08:27:31.757', 35334, 890),
(863108, 'some horrible solution question html', '2002-11-05 04:25:34.757', 63589, 890),
(505914, 'some bad fix problem c', '2013-11-17 08:34:35.364', 54879, 750),
(105069, 'another not useful idea issue css', '2007-06-21 11:53:25.757', 18263, 965),
(224379, 'one not useful useful problem python', '2001-11-24 10:52:11.750', 14407, 448),
(599503, 'one not useful idea problem css', '2012-05-09 23:27:07.890', 40635, 171),
(586204, 'another bad idea problem c', '2014-11-04 12:38:45.258', 14799, 171),
(691816, 'one horrible useful issue c++', '2012-01-19 10:51:37.299', 49140, 130),
(173357, 'some horrible fix problem html', '2018-02-18 08:26:19.448', 70324, 965),
(552778, 'one bad useful problem c', '2008-01-24 04:23:47.448', 60611, 750),
(330423, 'one not useful idea question css', '2008-04-12 09:44:28.364', 20048, 965),
(608580, 'another not useful fix issue css', '2014-10-04 01:14:23.460', 13539, 757),
(396771, 'one horrible solution question html', '2004-03-22 05:34:24.299', 32163, 736),
(742967, 'one horrible useful issue java', '2004-04-23 01:22:05.736', 18263, 890),
(150134, 'some horrible fix problem python', '2011-09-25 18:57:04.965', 32163, 460),
(213104, 'some bad idea question c++', '2008-05-07 04:21:18.757', 44528, 750),
(709152, 'some not useful solution issue css', '2007-06-06 08:28:21.130', 15765, 299),
(128766, 'another horrible solution question python', '2015-05-01 12:54:07.258', 70589, 362),
(138671, 'one not useful fix problem python', '2010-08-10 01:57:35.736', 14126, 750),
(324011, 'one bad fix question css', '2003-01-01 16:19:51.750', 14799, 362),
(157405, 'one horrible solution question c++', '2011-01-18 22:29:45.736', 49819, 364),
(518950, 'another not useful fix problem c', '2009-01-30 07:54:41.258', 60814, 965),
(438645, 'some not useful fix question html', '2011-11-20 06:50:03.448', 68569, 448),
(590921, 'another bad useful issue c++', '2015-04-20 11:18:13.736', 41223, 750),
(504815, 'one horrible idea problem css', '2007-08-27 01:11:40.750', 35334, 364),
(904131, 'one bad solution issue c', '2007-01-07 23:53:20.258', 24143, 890),
(238321, 'some horrible idea question c++', '2005-04-29 21:53:47.299', 15605, 362),
(976455, 'one bad fix issue c', '2013-03-13 14:02:26.130', 70719, 299),
(287325, 'some bad solution question css', '2009-11-30 01:27:58.171', 52798, 814),
(855745, 'one horrible idea question c', '2008-04-09 14:40:37.460', 72745, 362),
(582116, 'another not useful useful problem css', '2008-04-09 20:18:27.890', 15129, 736),
(624740, 'some not useful fix issue python', '2005-03-11 04:17:58.364', 67160, 736),
(303696, 'another bad useful issue java', '2002-12-06 15:03:48.171', 35334, 460),
(805577, 'some horrible solution problem java', '2004-03-18 22:46:15.965', 67160, 757),
(809205, 'one bad useful problem python', '2006-10-08 06:33:53.171', 15129, 757),
(997488, 'one bad idea problem html', '2014-01-07 04:22:51.814', 22909, 364),
(183390, 'another not useful solution issue python', '2018-06-13 19:12:34.814', 28405, 736),
(856808, 'another not useful fix problem html', '2013-03-13 22:53:44.757', 49039, 736),
(813406, 'another not useful useful problem css', '2006-08-05 21:14:50.736', 24143, 362),
(177439, 'one horrible useful issue c', '2003-05-25 18:54:56.258', 46652, 814),
(411722, 'one not useful idea problem python', '2012-04-15 10:22:42.258', 13494, 890),
(333832, 'some horrible useful problem c++', '2001-10-29 04:17:44.757', 12297, 675),
(828759, 'another bad solution issue c++', '2006-02-21 02:45:45.757', 48926, 362),
(929302, 'some horrible useful issue html', '2009-05-04 03:52:38.890', 15765, 299),
(371119, 'another not useful solution question java', '2012-10-15 22:09:58.965', 18263, 258),
(176300, 'another bad fix question c++', '2014-04-03 12:15:22.460', 13494, 750),
(134550, 'another bad useful problem c++', '2004-02-11 11:02:28.362', 50375, 814),
(361097, 'some bad useful question c', '2014-04-10 08:03:24.460', 28318, 460),
(952653, 'another not useful idea problem java', '2013-09-04 13:35:53.448', 43579, 890),
(505442, 'one not useful fix problem css', '2009-04-05 18:09:40.362', 73254, 364),
(837382, 'another bad fix issue c', '2009-02-17 16:38:56.750', 28318, 364),
(919163, 'one horrible useful problem c++', '2017-12-10 06:32:33.130', 14126, 448),
(157032, 'another not useful idea issue html', '2012-05-01 02:02:17.258', 14799, 757),
(402821, 'some not useful idea problem html', '2006-10-11 14:57:11.757', 15605, 750),
(787632, 'some horrible useful problem c++', '2005-10-29 03:48:13.460', 50597, 299),
(964573, 'one bad useful question css', '2006-05-05 17:26:24.675', 32163, 750),
(633259, 'some horrible fix problem java', '2012-10-06 15:42:55.362', 44312, 890),
(162054, 'another horrible idea question css', '2006-10-15 23:41:14.736', 18263, 130),
(652380, 'one not useful useful problem c++', '2017-10-12 18:39:44.965', 67306, 890)