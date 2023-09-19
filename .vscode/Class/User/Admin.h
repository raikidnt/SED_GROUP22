// #pragma once
#ifndef ADMIN_H
#define ADMIN_H
#include <bits/stdc++.h>
#include "User.h"
#include "../UI/UI.h"

class Admin :public User{
   private:
      std::string admin_username;
      std::string admin_password;
   public:
      Admin(); //default constructor
      Admin (std::string username, std::string password);

      friend class System;
      friend class MotorBike;
};


#endif //ADMIN_H