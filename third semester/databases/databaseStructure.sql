CREATE DATABASE StackOverflow
GO
use StackOverflow
GO
drop table if exists Communities
drop table if exists Comments
drop table if exists Badges
drop table if exists Users
drop table if exists Answers
drop table if exists Awards
drop table if exists Tags
drop table if exists Topics
drop table if exists Questions
drop table if exists QuestionsTags

CREATE TABLE Communities(
	COMID INT PRIMARY KEY,
	Name VARCHAR(50) NOT NULL,
	Description VARCHAR(100))

CREATE TABLE Badges(
	BID INT PRIMARY KEY,
	Title VARCHAR(50) NOT NULL,
	Rank INT DEFAULT 0)

CREATE TABLE Users(
	UID INT PRIMARY KEY,
	Name VARCHAR(50),
	Username VARCHAR(25),
	Email VARCHAR(25) NOT NULL,
	COMID INT FOREIGN KEY REFERENCES Communities(COMID))

CREATE TABLE Awards(
	BID INT FOREIGN KEY REFERENCES Badges(BID),
	UID INT FOREIGN KEY REFERENCES Users(UID),
	CONSTRAINT pk_Awards PRIMARY KEY (BID, UID))

CREATE TABLE Topics(
	TopicID INT PRIMARY KEY,
	Name VARCHAR(100) NOT NULL,
	Description VARCHAR(200))

CREATE TABLE Questions(
	QID INT PRIMARY KEY,
	Title VARCHAR(50) NOT NULL,
	Content VARCHAR(200) NOT NULL,
	DateAdded DATETIME DEFAULT getdate(),
	UID INT FOREIGN KEY REFERENCES Users(UID),
	TopicID INT FOREIGN KEY REFERENCES Topics(TopicID))

	
CREATE TABLE Answers(
	AID INT PRIMARY KEY,
	Content VARCHAR(250) NOT NULL,
	DateAdded DATETIME DEFAULT getdate(),
	UID INT FOREIGN KEY REFERENCES Users(UID),
	QID INT FOREIGN KEY REFERENCES Questions(QID))
	

CREATE TABLE Comments(
	CID INT PRIMARY KEY,
	Content VARCHAR(200) NOT NULL,
	DateAdded DATETIME DEFAULT getdate(),
	AID INT FOREIGN KEY REFERENCES Answers(AID),
	UID INT FOREIGN KEY REFERENCES Users(UID))


CREATE TABLE Tags(
	TID INT PRIMARY KEY,
	Name VARCHAR(20))


CREATE TABLE QuestionsTags(
	QID INT FOREIGN KEY REFERENCES Questions(QID),
	TID INT FOREIGN KEY REFERENCES Tags(TID),
	CONSTRAINT pk_QuestionsTags PRIMARY KEY (QID, TID))
