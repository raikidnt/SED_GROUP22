#pragma once
#ifndef ADMIN
#define ADMIN
#include <string>
#include <iostream>
// #include "Admin.cpp"
class Admin {
   private:
      std::string admin_username = "admin";
      std::string admin_password = "123abc";
   public:
      Admin();
      bool login(std::string username, std::string password);
      void logout();
      void viewAllMembers();  //view all member in the system
      void viewAllMotorBike();   //view all motorbike in the system
};


#endif