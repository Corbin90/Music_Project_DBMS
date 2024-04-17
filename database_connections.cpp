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



int main(void){

   int opt = 6;
 
 while (opt != 5) {
     
     cout << endl;
     cout << "1. Add Data" << endl;
     cout << "2. Find Data" << endl;
     cout << "3. View Specific Data" << endl;
     cout << "4. View All Data" << endl;
     cout << "5. Exit" << endl << endl;
     
     cout << "Choice : ";
     cin >> opt;
     
     switch(opt) {
        
				 case 1: cout << "case 1 works" << endl;
				         break;

         case 2: cout << "case 2 works" << endl;
                 break;

				case 3: cout << "case 3 works" << endl;
				         break;
             
         case 4: cout << "case 4 works" << endl;
                 break;
             
             
     }
 }
 




}
