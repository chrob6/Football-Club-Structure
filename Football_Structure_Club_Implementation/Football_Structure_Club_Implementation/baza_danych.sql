CREATE DATABASE IF NOT EXISTS fc;
DROP SCHEMA IF EXISTS fc;
CREATE SCHEMA fc COLLATE = utf8_general_ci;
USE fc;


CREATE TABLE candidate (
  ID_user INT (11) UNSIGNED NOT NULL AUTO_INCREMENT,
  first_name varchar(50) NOT NULL,
  last_name varchar(50) NOT NULL,
  age INT(3) NOT NULL,
  time_playing INT(3) NOT NULL,
  club varchar(50) NOT NULL,
  position varchar(50) NOT NULL,
  PRIMARY KEY (ID_user)
);


INSERT INTO candidate
VALUES (
        default,
        'Zbigniew',
        'Korwinowski',
        18,
		5,
		'RKS Garbarnia',
		'Sweeper'
       );

INSERT INTO candidate
VALUES (
        default,
        'Mateusz',
        'Kawa',
        20,
        7,
	    'Polonia',
	    'Defensive midfield'
       );


CREATE TABLE player (
  ID_user INT (11) UNSIGNED NOT NULL AUTO_INCREMENT,
  first_name varchar(50) NOT NULL,
  last_name varchar(50) NOT NULL,
  age int(10) NOT NULL,
  salary INT(3) NOT NULL,
  goals INT(3) NOT NULL,
  min_played INT(3) NOT NULL,
  position varchar(50) NOT NULL,
  PRIMARY KEY (ID_user)
);

INSERT INTO player
VALUES (
        default,
        'Antoni',
        'Piotrkowski',
        19,
        2100,
        0,
        0,
        'Goalkeeper'
       );

INSERT INTO player
VALUES (
        default,
        'Tomasz',
        'Palka',
        20,
        2100,
        0,
        0,
        'Wing-back'
       );


CREATE TABLE timetable_med (
  ID_timetable_med INT (11) UNSIGNED NOT NULL AUTO_INCREMENT,
  w_day varchar(50) NOT NULL,
  lasting_minutes INT(3) NOT NULL,
  hour TIME(0) NOT NULL,
  PRIMARY KEY (ID_timetable)
);

INSERT INTO timetable
VALUES (
        default,
        'Monday',
        90,
        '08:00:00'
       );

CREATE TABLE timetable_phy (
  ID_timetable_phy INT (11) UNSIGNED NOT NULL AUTO_INCREMENT,
  w_day varchar(50) NOT NULL,
  lasting_minutes INT(3) NOT NULL,
  hour TIME(0) NOT NULL,
  PRIMARY KEY (ID_timetable)
);

INSERT INTO timetable_phy
VALUES (
        default,
        'Monday',
        90,
        '09:00:00'
       );



DROP USER 'fc'@'localhost';
FLUSH PRIVILEGES;
CREATE USER 'fc'@'localhost' IDENTIFIED BY 'fc';
GRANT ALL PRIVILEGES ON fc.* TO fc@localhost;
FLUSH PRIVILEGES;

