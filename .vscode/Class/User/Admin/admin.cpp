#include "Admin.h"

Admin::Admin(){}; // default constructor

bool Admin::login(){
   std::string username;
   std::string password;
   std::cout << "Enter admin username: ";
   std::cin >> username;
   std::cin.ignore(0,' ');
   std::cout << "Enter admin password: ";
   std::cin >> password;
   if (username == admin_username && password == admin_password){
      return 0;
   } else {
      return 1;
   }
};


#include <bits/stdc++.h>
using namespace std;

class Admin: public User {

};
