# Music_Project_DBMS
How to run the program:
1) Once the terminal is open, type mysql
2) Run source music_datebase.sql;

Queries to add to C++ code for input:
Show:
-Artists: select * from ARTISTS;
-Albums: select * from ALBUMS;
-LABELS: select * from LABELS;
-MANAGERS: select * from MANAGERS;
-Album sales: select * from SALES;

Find:
-Artists by Label id: select ARTISTS.Artist_Name, ARTISTS.Date_Started, LABELS.Label_Name from ARTISTS join LABELS on ARTISTS.Label_ID = LABELS.Label_ID where ARTISTS.Label_ID = (input for ID goes here);
-Find albums by artist id: select ALBUMS.Album_Name, ALBUMS.Release_Date, ALBUMS.Genre, ALBUMS.Duration, ARTISTS.Artist_Name from ALBUMS join ARTISTS on ARTISTS.Artist_ID = ALBUMS.Artist_ID where ALBUMS.Artist_ID = (input for ID goes here);
Find manager by artist id: select MANAGERS.F_Name, MANAGERS.L_Name, MANAGERS.Date_Started, MANAGERS.Phone_number, MANAGERS.Email, ARTISTS.Artist_Name from MANAGERS join ARTISTS on MANAGERS.Artist_ID = ARTISTS.Artist_ID where MANAGERS.Artist_ID = (input for ID goes here);
Find albums by RIAA certification: select ALBUMS.Album_Name, ALBUMS.Release_Date, ALBUMS.Genre, ALBUMS.Duration, SALES.Total_Units, SALES.RIAA_Certification from ALBUMS join 
SALES on ALBUMS.Album_ID = SALES.Album_ID where SALES.RIAA_Certification = 'Gold';

Add:
-Album: insert into ALBUMS(Album_Name, Release_Date, Genre, Duration, Artist_ID, Label_ID) values(inputs go here);
-Managers: insert into MANAGERS(F_Name, L_Name, Date_Started, Phone_number, Email, Artist_ID) values(inputs go here);
-Artists: insert into ARTISTS(Artist_Name, F_Name, L_Name, Date_Started, Label_ID) values(inputs go here);
-Sales: insert into SALES(Units_Sold, Digital_Streams, Total_Units, RIAA_Certification, Last_Updated, Album_ID) values(inputs go here);
