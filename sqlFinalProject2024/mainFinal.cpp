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


int main(void){

driver = get_driver_instance();
con = driver->connect("tcp://127.0.0.1:3306", "root", "");
con->setSchema("MUSIC");




int opt = 6;
 
 while (opt != 4) {
     
     cout << endl;
     cout << "Do you want to " << endl;
     cout << "1. Add Data?" << endl;
     cout << "2. Find Data?" << endl;
     cout << "3. Show Data?" << endl;
     cout << "4. Exit" << endl << endl;
     
     cout << "Choice : ";
     cin >> opt;
     
     int opt2 = 0;

     switch(opt) {
                //CASE TO ADD 
		case 1: 
                while (opt2 !=5)        {
                        cout << "1. Add an album" << endl; 
                        cout << "2. Add an artist" << endl;
                        cout << "3. Add a manager" << endl;
                        cout << "4. Add album sales" << endl;
                        cout << "5. Exit" << endl << endl;

                        cout << "Choice : ";
                        cin >> opt2;

                        switch(opt2)
                        {
                                case 1: 
                                        addAlbum();
                                break;

                                case 2: 
                                        addArtist();
                                break;

                                case 3: 
                                        addManager();
                                break;

                                case 4: 
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

                        cout << "Choice : ";
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
     }
 }
 




}



void addAlbum(){

}
void addArtist(){

}
void addManager(){

}
void addAlbumSales(){

}
void findArtistbyID(){
        
}
void findLabel(){
        
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
         prep_stmt = con->prepareStatement("SELECT * FROM MANAGERS WHERE ARTIST_ID = ?");
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

    }





    }
}
void findAlbum(){
        
}
void showArtists(){
        
}
void showAlbums(){
        
}
void showLabels(){
        
}
void showAlbumSales(){

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
