#include <stdlib.h>
#include <iostream>
/*
 Include directly the different
 headers from cppconn/ and mysql_driver.h + mysql_util.h
 (and mysql_connection.h). This will reduce your build time!
*/
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
using namespace std;

sql::Driver *driver;
sql::Connection *con;
sql::Statement *stmt;
sql::ResultSet *res;
sql::PreparedStatement  *prep_stmt;

void addLabel();
void addAlbum();
void addArtist();
void addManager();
void addAlbumSales();
void findArtistbyID();
void findLabel();
void findManager();
void findAlbum();
void showArtists();
void showAlbums();
void showLabels();
void showAlbumSales();
void showManagers();
void findSpecific();
void deleteCertification();
void deleteAlbum();
void RIAA_certchange();
void updateArtists();
int main(void){
  driver = get_driver_instance();
  con = driver->connect("tcp://127.0.0.1:3306", "root", "");
  con->setSchema("MUSIC");
  int opt = 0;
  while (opt != 6) {
     cout << endl;
     cout << "Do you want to " << endl;
     cout << "1. Add Data?" << endl; // insert
     cout << "2. Find Data?" << endl; // find
     cout << "3. Show Data?" << endl; 
     cout << "4. Delete Data?" << endl; // Delete
     cout << "5. Update Data?" << endl; //Update
     cout << "6. Exit" << endl << endl;
     
     cout << "Choice : ";
     cin >> opt;
     int opt2 = 0;

     switch(opt) {
                //CASE TO ADD 
		case 1: 
                while (opt2 !=6)        {
                        cout << "1. Add a Label" << endl;
                        cout << "2. Add an album" << endl; 
                        cout << "3. Add an artist" << endl;
                        cout << "4. Add a manager" << endl;
                        cout << "5. Add album sales" << endl;
                        cout << "6. Exit" << endl << endl;
                        cout << "Choice: ";
                        cin >> opt2;
                        switch(opt2)
                        {
                                case 1:
                                    addLabel();
                                case 2: 
                                        addAlbum();
                                break;

                                case 3: 
                                        addArtist();
                                break;

                                case 4: 
                                        addManager();
                                break;

                                case 5: 
                                        addAlbumSales();
                                break;
                        }
                }
		break;
                //CASE TO FIND
                case 2: 
                while (opt2 !=5)        {
                        cout << "1. Find artist" << endl;
                        cout << "2. Find label" << endl;
                        cout << "3. Find managers" << endl;
                        cout << "4. Find albums " << endl;
                        cout << "5. Exit" << endl << endl;
                        cout << "Choice: ";
                        cin >> opt2;

                        switch(opt2)
                        {
                                case 1: 
                                        findArtistbyID();
                                break;
                                case 2: 
                                        findLabel();
                                break;
                                case 3: 
                                        findManager();
                                break;
                                case 4: 
                                        findAlbum();
                                break;
                        }
                }
                break;
                //CASE TO SHOW
		case 3: 
                while (opt2 != 6) {
                        cout << "1. Show all artists" << endl;
                        cout << "2. Show all albums" << endl;
                        cout << "3. Show all labels" << endl;
                        cout << "4. Show all album sales" << endl;
                        cout << "5. Show all managers" << endl;
                        cout << "6. Exit" << endl << endl;

                        cout << "Choice : ";
                        cin >> opt2;

                        switch(opt2)
                        {
                                case 1: 
                                        showArtists();
                                break;

                                case 2: 
                                        showAlbums();
                                break;

                                case 3: 
                                        showLabels();
                                break;

                                case 4: 
                                        showAlbumSales();
                                break;

                                case 5:
                                        showManagers();
                                break;
                        }
                }
		break;
    // Case to delete
        case 4:
          while (opt2 !=3){
                          cout << "1. Delete a sale by RIAA Certification" << endl;
                          cout << "2. Delete an album by Genre" << endl; 
                          cout << "3. Exit" << endl << endl;
                          cout << "Choice: ";
                          cin >> opt2;

                          switch(opt2){
                            case 1:
                              deleteCertification();
                            break;
                            case 2:
                              deleteAlbum();
                            break;

                            
                          }
                          }
        break;
        //Update Data
        case 5:
        while (opt2!= 3){
                cout << "1. Would you like to update Update where total_units are less than 1,000,000 to 1,250,750, and RIAA_Certification equal to Platinum?" << endl;
                cout << "2. Update artists to Label 1 where the start date is between 1986 and 2000" << endl;
                cout << "3. Exit" <<endl;
                cin >> opt2;
                switch(opt2){
                        case 1:
                                RIAA_certchange();
                                break;
                        case 2:
                                updateArtists();
                                break;

                }
        }
        break;
       
  
     
 }
  }
}
void RIAA_certchange(){
  prep_stmt = con->prepareStatement("UPDATE SALES SET Total_Units = 1250750, RIAA_Certification='Platinum' "\
                                    "WHERE Total_Units < 1000000;");
  prep_stmt->executeQuery();
}
void updateArtists(){
  prep_stmt = con->prepareStatement("UPDATE ARTISTS SET Label_ID = 101 " \
                                    "WHERE Date_Started > '1986-01-01' AND Date_Started < '2000-01-01'");
  prep_stmt->executeQuery();
}
void addLabel(){
  string label_name;
  string owner_fname;
  string owner_lname;
  string state_location;
  string date_established;
  string phone_number;
  string email;
  cout << "Enter the label name: ";
  cin >> label_name;

  cout << "Enter the owner's first name: ";
  cin >> owner_fname;

  cout << "Enter the owner's last name: ";
  cin >> owner_lname;

  cout << "Enter the location(City,State): ";
  cin >> state_location;

  cout <<"Enter the date_established(YYYY-MM-DD): ";
  cin >> date_established;

  cout << "Enter a phone number: ";
  cin >> phone_number;

  cout << "Enter an email: ";
  cin >> email;
  prep_stmt = con->prepareStatement("INSERT INTO LABELS(Label_Name, Owner_FName, Owner_LName,State_Location, Date_Established, Phone_Number, Email) " \
                                    "VALUES (?, ?, ?, ?, ?, ?, ?)");
  prep_stmt->setString(1, label_name);
  prep_stmt->setString(2, owner_fname);
  prep_stmt->setString(3, owner_lname);
  prep_stmt->setString(4, state_location);
  prep_stmt->setString(5, date_established);
  prep_stmt->setString(6, phone_number);
  prep_stmt->setString(7, email);
  res=prep_stmt->executeQuery();
  while (res->next()) {
                        cout << res->getString("Label_Name") << " ";
                        cout << res->getString("Owner_FName") << " ";
                        cout << res->getString("Owner_LName") << " ";
                        cout << res->getString("State_Location") << " ";
                        cout << res->getString("Date_Established") << " ";
                        cout << res->getString("Phone_Number") << " ";
                        cout << res->getString("Email") << endl;
                }
}
void addAlbum(){

}
void deleteCertification(){
  string certification;
  cout << "Enter a certification: ";
  cin >> certification;
  prep_stmt = con->prepareStatement("DELETE FROM SALES WHERE RIAA_Certification=?");
  prep_stmt->setString(1, certification);
  res=prep_stmt->executeQuery();
  while (res->next()){
    cout << res->getString("RIAA_Certification") << endl;
  }
}
void deleteAlbum(){
  string gen;
  cout << "Enter a a date (YYYY-MM-DD): ";
  cin >> gen;
  prep_stmt = con->prepareStatement("DELETE FROM MANAGERS WHERE Date_Started < ?");
  prep_stmt->setString(1, gen);
  res=prep_stmt->executeQuery();
  while (res->next()){
    cout << res->getString("Date_Established") << endl;
  }
}

void addArtist(){
  string artist_name;
  string f_name;
  string l_name;
  string date_started;
  string label_id;
  cout << "Enter an artist name: ";
  cin >> artist_name;

  cout << "Enter a first name: ";
  cin >> f_name;

  cout << "Enter a last name: ";
  cin >> l_name;

  cout << "Enter the date started (YYYY-MM-DD): ";
  cin >> date_started;

  cout <<"Enter a label ID: ";
  cin >> label_id;

  prep_stmt = con->prepareStatement("INSERT INTO ARTISTS(Artist_Name, F_Name, L_Name,Date_Started, Label_ID) " \
                                    "VALUES (?, ?, ?, ?, ?)");
  prep_stmt->setString(1, artist_name);
  prep_stmt->setString(2, f_name);
  prep_stmt->setString(3, l_name);
  prep_stmt->setString(4, date_started);
  prep_stmt->setString(5, label_id);
  res=prep_stmt->executeQuery();
  while (res->next()) {
                        cout << res->getString("Artist_ID") << " ";
                        cout << res->getString("F_Name") << " ";
                        cout << res->getString("L_Name") << " ";
                        cout << res->getString("Date_Started") << " ";
                        cout << res->getString("Label_ID") << endl; 
                }

}
void addManager(){
  string f_name;
  string l_name;
  string date_started;
  string phone_number;
  string email;
  string artist_id;
  cout << "Enter a first name: ";
  cin >> f_name;

  cout << "Enter a last name: ";
  cin >> l_name;

  cout << "Enter the date started (YYYY-MM-DD): ";
  cin >> date_started;

  cout << "Enter a phone number: ";
  cin >> phone_number;

  cout <<"Enter email: ";
  cin >> email;

  cout <<"Enter an artist ID: ";
  cin >> artist_id;

  prep_stmt = con->prepareStatement("INSERT INTO MANAGERS(F_Name, L_Name,Date_Started, Phone_number, Email, Artist_ID) " \
                                    "VALUES (?, ?, ?, ?, ?, ?)");
  prep_stmt->setString(1, f_name);
  prep_stmt->setString(2, l_name);
  prep_stmt->setString(3, date_started);
  prep_stmt->setString(4, phone_number);
  prep_stmt->setString(5, email);
  prep_stmt->setString(6, artist_id);
  res=prep_stmt->executeQuery();
  while (res->next()) {
                        cout << res->getString("F_Name") << " ";
                        cout << res->getString("L_Name") << " ";
                        cout << res->getString("Date_Started") << " ";
                        cout << res->getString("Phone_number") << " ";
                        cout << res->getString("Email") << " "; 
                        cout << res->getString("Artist_ID") << endl;
                }

}
void addAlbumSales(){

}
void findArtistbyID(){
     int opt;
     int id = 0;
     while (opt!=4){
        cout << "How would you like to find the artist(s)?: " << endl;
        cout << "1. By ID" << endl;
        cout << "2. By Label ID" << endl;
        cout << "3. By Manager ID" << endl;
        cout << "4. Exit" << endl;
        cin >> opt;
        switch(opt){
                case 1:
                    cout << "Enter the artist's ID: ";
                    cin >> id;
                    prep_stmt = con->prepareStatement("SELECT * FROM ARTISTS WHERE ARTIST_ID = ?");
                    prep_stmt->setInt(1, id);
                    res = prep_stmt->executeQuery();
                    while (res->next()) {
                        cout << res->getString("Artist_ID") << " ";
                        cout << res->getString("Artist_Name") << " ";
                        cout << res->getString("F_Name") << " ";
                        cout << res->getString("L_Name") << " ";
                        cout << res->getString("Date_Started") << " ";
                        cout << res->getString("Label_ID") << endl;
                }
                break;
                case 2:
                    cout << "Enter the Label ID: ";
                    cin >> id;
                    prep_stmt = con->prepareStatement("SELECT ARTISTS.Artist_ID, ARTISTS.Artist_Name, ARTISTS.F_Name, ARTISTS.L_Name, ARTISTS.Date_Started, LABELS.Label_Name " \
                                                        "FROM ARTISTS JOIN LABELS " \
                                                        "ON ARTISTS.Label_ID=LABELS.Label_ID " \
                                                        "WHERE LABELS.Label_ID=?");
                    prep_stmt->setInt(1, id);
                    res = prep_stmt->executeQuery();
                    while (res->next()) {
                        cout << res->getInt("Artist_ID") << " ";
                        cout << res->getString("Artist_Name") << " ";
                        cout << res->getString("F_Name") << " ";
                        cout << res->getString("L_Name") << " ";
                        cout << res->getString("Date_Started") << " ";
                        cout << res->getString("Label_Name") << endl;
                }
                break;
                case 3:
                    cout << "Enter the Manager ID: ";
                    cin >> id;
                    prep_stmt = con->prepareStatement("SELECT ARTISTS.Artist_ID, ARTISTS.Artist_Name, ARTISTS.F_Name, ARTISTS.L_Name, ARTISTS.Date_Started, ARTISTS.Label_ID, MANAGERS.F_Name, MANAGERS.L_Name " \
                                                        "FROM ARTISTS JOIN MANAGERS " \
                                                        "ON ARTISTS.Artist_ID=MANAGERS.Artist_ID " \
                                                        "WHERE MANAGERS.Manager_ID=?");
                    prep_stmt->setInt(1, id);
                    res = prep_stmt->executeQuery();
                    while(res->next()){
                        cout << res->getInt("Artist_ID") << " ";
                        cout << res->getString("Artist_Name") << " ";
                        cout << res->getString("F_Name") << " ";
                        cout << res->getString("L_Name") << " ";
                        cout << res->getString("Date_Started") << " ";
                        cout << res->getString("Label_ID") << " ";
                        cout << res->getString("F_Name") << " ";
                        cout << res->getString("L_Name") << endl;
                    }
                    break;
        }
     }
}
void findLabel(){
    int opt;
    int id = 0;
    while(opt !=2){
    cout << "How would you like to find a Label?: " << endl;
    cout << "1. by ID" << endl;
    cout << "2. Exit" << endl;
    cin >> opt;
    switch(opt){
      case 1:
        cout << "Enter the Label ID: ";
        cin >> id; 
        prep_stmt = con->prepareStatement("SELECT * FROM LABELS WHERE LABEL_ID = ?");
        prep_stmt->setInt(1, id);
        res = prep_stmt->executeQuery();
        while (res->next()) {
          cout << res->getString("Label_ID") << " ";
          cout << res->getString("Label_Name") << " ";
          cout << res->getString("Owner_FName") << " ";
          cout << res->getString("Owner_LName") << " ";
          cout << res->getString("State_Location") << " ";
          cout << res->getString("Date_Established") << " ";
          cout << res->getString("Phone_Number") << " ";
          cout << res->getString("Email") << endl; 
        }
        break;
    }
    }
}
void findManager(){ 
    int opt;
    int id = 0;
    while(opt !=3){
    cout << "How would you like to find a manager?: " << endl;
    cout << "1. by ID" << endl;
    cout << "2. by Artist" << endl;
    cout << "3. Exit" << endl; 
    cin >> opt;
    switch(opt){
        case 1: 
         cout << "Enter the Manager ID : ";
         cin >> id;
         prep_stmt = con->prepareStatement("SELECT * FROM MANAGERS WHERE MANAGER_ID = ?");
         prep_stmt->setInt(1, id);
         res = prep_stmt->executeQuery();
         while (res->next()) {
          cout << res->getString("MANAGER_ID") << " ";
          cout << res->getString("F_Name") << " ";
          cout << res->getString("L_Name") << " ";
          cout << res->getString("Date_Started") << " ";
          cout << res->getString("Phone_Number") << " ";
          cout << res->getString("Email") << " ";
          cout << res->getString("ARTIST_ID") << endl; 
        }
        break;
        case 2:
         cout << "Enter the Artist ID : ";
         cin >> id;
         prep_stmt = con->prepareStatement("SELECT MANAGERS.MANAGER_ID, MANAGERS.F_Name, MANAGERS.L_Name, MANAGERS.Date_Started, MANAGERS.Phone_Number, MANAGERS.Email, ARTISTS.Artist_Name " \
                                          "FROM MANAGERS JOIN ARTISTS " \
                                          "ON MANAGERS.Artist_ID = ARTISTS.Artist_ID " \
                                          "WHERE MANAGERS.Artist_ID = ?");
         prep_stmt->setInt(1, id);
         res = prep_stmt->executeQuery();
         while (res->next()) {
          cout << res->getInt("MANAGER_ID") << " ";
          cout << res->getString("F_Name") << " ";
          cout << res->getString("L_Name") << " ";
          cout << res->getString("Date_Started") << " ";
          cout << res->getString("Phone_Number") << " ";
          cout << res->getString("Email") << " ";
          cout << res->getString("Artist_Name") << endl; 
         }
        break;
    }

    }
}
void findAlbum(){
     int opt;
     int id = 0;
     while (opt!=5){
        cout << "How would you like to find the album?: " << endl;
        cout << "1. By ID" << endl;
        cout << "2. By Label ID" << endl;
        cout << "3. By Artist ID" << endl;
        cout << "4. By Sales ID" << endl;
        cout << "5. Exit" << endl;
        cin >> opt;
        switch(opt){
                case 1:
                        cout << "Enter the Album ID : ";
                        cin >> id;
                        prep_stmt = con->prepareStatement("SELECT * FROM ALBUMS WHERE Album_ID = ?");
                        prep_stmt->setInt(1, id);
                        res = prep_stmt->executeQuery();
                        while (res->next()) {
                        cout << res->getString("Album_ID") << " ";
                        cout << res->getString("Album_Name") << " ";
                        cout << res->getString("Release_Date") << " ";
                        cout << res->getString("Genre") << " ";
                        cout << res->getString("Duration") << " ";
                        cout << res->getString("Artist_ID") << " ";
                        cout << res->getString("Label_ID") << endl; 
                }
                break;
                case 2:
                        cout << "Enter the Label ID: ";
                        cin >> id;
                        prep_stmt = con->prepareStatement("SELECT ALBUMS.Album_ID, ALBUMS.Album_Name, ALBUMS.Release_Date, ALBUMS.Genre, ALBUMS.Duration, ALBUMS.Artist_ID, LABELS.Label_Name " \
                                                        "FROM ALBUMS JOIN LABELS on ALBUMS.Label_ID = LABELS.Label_ID " \
                                                        "WHERE LABELS.Label_ID = ?");
                        prep_stmt->setInt(1, id);
                        res = prep_stmt->executeQuery();
                        while (res->next()) {
                        cout << res->getInt("Album_ID") << " ";
                        cout << res->getString("Album_Name") << " ";
                        cout << res->getString("Release_Date") << " ";
                        cout << res->getString("Genre") << " ";
                        cout << res->getString("Duration") << " ";
                        cout << res->getString("Artist_ID") << " ";
                        cout << res->getString("Label_Name") << endl; 
                }
                break;
                case 3:
                        cout << "Enter the Artist ID: ";
                        cin >> id;
                        prep_stmt = con->prepareStatement("SELECT ALBUMS.Album_ID, ALBUMS.Album_Name, ALBUMS.Release_Date, ALBUMS.Genre, ALBUMS.Duration, ALBUMS.Artist_ID, ARTISTS.Artist_Name " \
                                                          "FROM ALBUMS JOIN ARTISTS on ALBUMS.Artist_ID = ARTISTS.Artist_ID "\
                                                          "WHERE ALBUMS.Artist_ID = ?");
                        prep_stmt->setInt(1, id);
                        res = prep_stmt->executeQuery();
                        while (res->next()) {
                        cout << res->getInt("Album_ID") << " ";
                        cout << res->getString("Album_Name") << " ";
                        cout << res->getString("Release_Date") << " ";
                        cout << res->getString("Genre") << " ";
                        cout << res->getString("Duration") << " ";
                        cout << res->getString("Artist_ID") << " ";
                        cout << res->getString("Artist_Name") << endl; 
                }
                break;
                case 4:
                        cout << "Enter the Sales ID: ";
                        cin >> id;
                        prep_stmt = con->prepareStatement("SELECT ALBUMS.Album_ID, ALBUMS.Album_Name, ALBUMS.Release_Date, ALBUMS.Genre, ALBUMS.Duration, ALBUMS.Artist_ID, SALES.Units_Sold, SALES.Digital_streams, SALES.Total_Units, SALES.RIAA_Certification, SALES.Last_Updated " \
                                                          "FROM ALBUMS JOIN SALES on ALBUMS.Album_ID = SALES.Album_ID "\
                                                          "WHERE SALES.Sales_ID = ?");
                        prep_stmt->setInt(1, id);
                        res = prep_stmt->executeQuery();
                        while (res->next()) {
                        cout << res->getInt("Album_ID") << " ";
                        cout << res->getString("Album_Name") << " ";
                        cout << res->getString("Release_Date") << " ";
                        cout << res->getString("Genre") << " ";
                        cout << res->getString("Duration") << " ";
                        cout << res->getString("Artist_ID") << " ";
                        cout << res->getString("Units_Sold") << " ";
                        cout << res->getString("Digital_streams") << " ";
                        cout << res->getString("Total_Units") << " ";
                        cout << res->getString("RIAA_Certification") << " ";
                        cout << res->getString("Last_Updated") << endl; 
                        }
                        break;
        }   
     }
}


void showArtists(){
        stmt = con->createStatement();
        res = stmt->executeQuery("SELECT * from ARTISTS");
        while (res->next()) {
          cout << res->getString("Artist_ID") << " ";
          cout << res->getString("Artist_Name") << " ";
          cout << res->getString("F_Name") << " ";
          cout << res->getString("L_Name") << " ";
          cout << res->getString("Date_Started") << " ";
          cout << res->getString("Label_ID") << endl;    
        } 
}
void showAlbums(){
        stmt = con->createStatement();
        res = stmt->executeQuery("SELECT * from ALBUMS");
        while (res->next()) {
          cout << res->getString("Album_ID") << " ";
          cout << res->getString("Album_Name") << " ";
          cout << res->getString("Release_Date") << " ";
          cout << res->getString("Genre") << " ";
          cout << res->getString("Duration") << " ";
          cout << res->getString("Artist_ID") << " ";
          cout << res->getString("Label_ID") << endl;    
        } 
}
void showLabels(){
        stmt = con->createStatement();
        res = stmt->executeQuery("SELECT * from LABELS");
        while (res->next()) {
          cout << res->getString("Label_ID") << " ";
          cout << res->getString("Label_Name") << " ";
          cout << res->getString("Owner_FName") << " ";
          cout << res->getString("Owner_LName") << " ";
          cout << res->getString("State_Location") << " ";
          cout << res->getString("Date_Established") << " ";
          cout << res->getString("Phone_Number") << " ";
          cout << res->getString("Email") << endl;    
        }   
}
void showAlbumSales(){
        stmt = con->createStatement();
        res = stmt->executeQuery("SELECT * from SALES");
        while (res->next()) {
          cout << res->getString("Sales_ID") << " ";
          cout << res->getString("Units_Sold") << " ";
          cout << res->getString("Digital_streams") << " ";
          cout << res->getString("Total_Units") << " ";
          cout << res->getString("RIAA_Certification") << " ";
          cout << res->getString("Last_Updated") << " ";
          cout << res->getString("Album_ID") << endl;    
        }      
}
void showManagers(){
        stmt = con->createStatement();
        res = stmt->executeQuery("SELECT * from MANAGERS");
        while (res->next()) {
          cout << res->getString("MANAGER_ID") << " ";
          cout << res->getString("F_Name") << " ";
          cout << res->getString("L_Name") << " ";
          cout << res->getString("Date_Started") << " ";
          cout << res->getString("Phone_Number") << " ";
          cout << res->getString("Email") << " ";
          cout << res->getString("ARTIST_ID") << endl;
         }       
}
