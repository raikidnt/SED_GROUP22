#ifndef UI_H
#define UI_H
#include <bits/stdc++.h>
#include "../Bike/MotorBike.h"
#include "../User/Member.h"
#include "../User/Admin.h"
#include <vector>
// void welcome ();
int user_choice ();
int menu (int choice); //choice for each type of user

class System {
   private: 
   public:
      System();
      void beginUI();

};
#endif   //UI_H