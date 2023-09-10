// #pragma once
#ifndef ADMIN_H
#define ADMIN_H
#include <bits/stdc++.h>
#include "User.h"
class Admin :public User{
   private:
      std::string admin_username = "admin";
      std::string admin_password = "123abc";
   public:
      Admin(); //default constructor

      bool login(std::string username, std::string password);
      bool logout();
      void viewAllMembers();  //view all member in the system
      void viewAllMotorBikes();   //view all motorbike in the system
};


#endif //ADMIN_H