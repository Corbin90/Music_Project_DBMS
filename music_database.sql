-- Labels table 101
drop table if exists LABELS;
create table LABELS(
  Label_ID int not null AUTO_INCREMENT,
  Label_Name varchar(50),
  Owner_FName varchar(50),
  Owner_LName varchar(50),
  State_Location varchar(2),
  Date_Established date,
  Phone_Number varchar(10),
  Email varchar(75),
  primary key(Label_ID)
);

-- Artists table 201
drop table if exists ARTISTS;
create table ARTISTS (
  Artist_ID int not null,
  Artist_Name varchar(50),
  F_Name varchar(50),
  L_Name varchar(50),
  Date_Started date,
  Label_ID int not null AUTO_INCREMENT,
  primary key(Artist_ID),
  FOREIGN KEY (Label_ID) REFERENCES ARTISTS(Label_ID)
);

-- Manager table 401
drop table if exists MANAGERS;
create table MANAGERS(
  Manager_ID int not null,
  F_Name varchar(50),
  L_Name varchar(50),
  Date_Started date,
  Phone_number varchar(12),
  Email varchar(75),
  Artist_ID int not null,
  primary key(Manager_ID),
  FOREIGN KEY (Artist_ID) REFERENCES ARTISTS(Artist_ID)
);

-- Album table 301
drop table if exists ALBUMS;  
create table ALBUMS (
  Album_ID int not null AUTO_INCREMENT,
  Album_Name varchar(50),
  Release_Date date,
  Genre varchar(20),
  Duration time, 
  RIA_Certification varchar(25),
  Artist_ID int not null,
  Label_ID int not null,
  primary key(Album_ID),
  FOREIGN KEY (Artist_ID) REFERENCES ARTISTS(Artist_ID),
  FOREIGN KEY (Label_ID) REFERENCES LABELS(Label_ID)
);

-- Sales table 501
drop table if exists SALES;
create table SALES (
  Sales_ID int not null AUTO_INCREMENT,
  Units_Sold int,
  Digital_streams int,
  Total_Sales float(100,2),
  Genre_Name varchar(15),
  Album_ID int not null,
  primary key(Sales_ID),
  FOREIGN KEY (Album_ID) REFERENCES ALBUMS(Album_ID)
);

-- Adding data into the Labels table
insert into LABELS values(101, 'Sellout Records', 'Kamryn', 'Marin','Los Angeles, CA', '1985-03-12', '323-232-3232','selloutrecords0@sellout.com');
insert into LABELS(Label_Name, Owner_FName, Owner_LName,State_Location, Date_Established, Phone_Number, Email) values('RAHARCH Records', 'Raphael', 'Ali', 'New York, NY', '1960-12-3', '212-121-2121','raharchrecords@raharch.com'),
('Syncopated Sounds', 'River', 'Carrillo', 'Boise, ID','1978-06-28','208-208-2082', 'constipatedsounds@sync.com'),
('Sonic Studios', 'Titan', 'Marsh', 'Atlanta, GA', '1990-08-25','404-404-4040', 'sonicfaststu@sonic.com'),
('Same Beat Different Mood', 'Rahsaan', 'Corbin', 'Philadelphia, PA','2001-05-02','267-989-0000','differentbeatsamemood@mood.com'),
('Gyatt Records', 'Jonathan','Ramjattan', 'Orlando, FL','2002-01-30','321-000-9876','Gyattahaveit@gyattrecords.com');


-- Adding data into the Artists table
insert into ARTISTS values(201, 'Drakes','Drew','Shaffer','1985-03-15', 101),
                    (206, 'MC RAH', 'Rahsaan', 'Corbin', '1960-12-04', 102),
                    (211, 'Iron Man', 'Tony', 'Starks', '1978-06-19', 103),
                    (216, 'Gigi Granite', 'Brooke', 'Good', '1990-08-26',104),
                    (221, 'Phoenix', 'Lyric', 'Holloway', '2001-05-03',105),
                    (226, 'Luke Skywalker', 'Mathew', 'Higgins', '2002-01-31',106);


-- Adding data into the Managers table
insert into MANAGERS values(401,'Saba', 'Wright', '1985-03-15', '404-242-4924', 'sabawrigght@atl.com', 201),
                    (406, 'Samia', 'Morris', '1960-12-04', '988-242-2442','samiamorris@atl.com',206),
                    (411, 'Emmy', 'Sharp', '1978-06-19', '246-242-4562','emmysharp@atl.com',211),
                    (416, 'Zach', 'Sharp', '1990-08-26', '310-537-3592','zachsharp@atl.com', 216),
                    (421, 'Reina', 'Scott', '2001-05-03', '563-675-4423','reinascott@atl.com', 221),
                    (426, 'Matthew', 'Walker','2002-01-31', '285-642-6474', 'matthewwalker@atl.com', 226);


-- Adding data into the Albums table
insert into ALBUMS values(301,'N.Y Mental State', '2021-04-09', 'Hip Hop','0:55:32', 'Gold', 201,101);
insert into ALBUMS(Album_Name,Release_Date,Genre,Duration, RIA_Certification, Artist_ID, Label_ID) values('Back At The Barnyard', '1956-02-21', 'Country','01:04:23', 'Gold',206,102),
('Love Making Music', '1995-02-14', 'R&B','00:52:44', 'Gold',211, 103),
('Dance Dance Dance Dance', '2005-05-23', 'Pop','00:39:21', 'Gold', 216,104),
('A Tribe Called Jazz', '2000-06-19', 'Jazz','00:45:22', 'Gold',221, 105),
('Roll & Rock Vol. 1', '2001-07-04', 'Rock & Roll','00:53:07', 'Gold',226, 106);

-- Adding data into the Sales table
insert into SALES value(501, 500000, 60000000, 2000000.45, 'Hip Hop', 301);
insert into SALES(Units_Sold, Digital_streams, Total_Sales, Genre_Name, Album_ID) values(250000, 5000, 1023.87, 'Country', 302),
(150750, 4000, 987.76, 'R&B', 303),
(2500000, 6700, 8983.87, 'Pop', 304),
(650000,5900, 4984.84, 'Jazz', 305),
(750000, 9000, 5093.50, 'Rock & Roll', 306);
