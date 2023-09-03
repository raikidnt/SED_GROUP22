#include "Admin.h"
#include <string>
#include <iostream>

Admin::Admin(){}; // default constructor

bool Admin::login(){
   std::string username;
   std::string password;
   std::cout << "Enter admin username: " << std::endl;
   std::cin >> username;
   std::cin.ignore(' ');
   std::cout << "Enter admin password: " << std::endl;
   std::cin >> password;
   if (username == admin_username && password == admin_password){
      return 0;
   } else {
      return 1;
   }
};
