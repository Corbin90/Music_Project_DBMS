# Music_Project_DBMS
DO NOT CHANGE ANYTHING ON THE music_database.sql FILE!
How to run the program:
1) Once the terminal is open, type mysql
2) Run source music_datebase.sql;

Queries to add to C++ code for input:
Prompt Structure for main menu:
1) Show
2) Find
3) Add
4) Exit program

Show:
1) Artists: select * from ARTISTS;
2) Albums: select * from ALBUMS;
3) LABELS: select * from LABELS;
4) MANAGERS: select * from MANAGERS;
5) Album sales: select * from SALES;

Find:
1) Artists by Label id: select ARTISTS.Artist_Name, ARTISTS.Date_Started, LABELS.Label_Name from ARTISTS join LABELS on ARTISTS.Label_ID = LABELS.Label_ID where ARTISTS.Label_ID = (input for ID goes here);
2) Find albums by artist id: select ALBUMS.Album_Name, ALBUMS.Release_Date, ALBUMS.Genre, ALBUMS.Duration, ARTISTS.Artist_Name from ALBUMS join ARTISTS on ARTISTS.Artist_ID = ALBUMS.Artist_ID where ALBUMS.Artist_ID = (input for ID goes here);
3) Find manager by artist id: select MANAGERS.F_Name, MANAGERS.L_Name, MANAGERS.Date_Started, MANAGERS.Phone_number, MANAGERS.Email, ARTISTS.Artist_Name from MANAGERS join ARTISTS on MANAGERS.Artist_ID = ARTISTS.Artist_ID where MANAGERS.Artist_ID = (input for ID goes here);
4) Find albums by RIAA certification: select ALBUMS.Album_Name, ALBUMS.Release_Date, ALBUMS.Genre, ALBUMS.Duration, SALES.Total_Units, SALES.RIAA_Certification from ALBUMS join 
SALES on ALBUMS.Album_ID = SALES.Album_ID where SALES.RIAA_Certification = 'Gold';

Add:
1) Album: insert into ALBUMS(Album_Name, Release_Date, Genre, Duration, Artist_ID, Label_ID) values(inputs go here);
2) Managers: insert into MANAGERS(F_Name, L_Name, Date_Started, Phone_number, Email, Artist_ID) values(inputs go here);
3) Artists: insert into ARTISTS(Artist_Name, F_Name, L_Name, Date_Started, Label_ID) values(inputs go here);
4) Sales: insert into SALES(Units_Sold, Digital_Streams, Total_Units, RIAA_Certification, Last_Updated, Album_ID) values(inputs go here);
