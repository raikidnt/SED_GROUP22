#ifndef UI_H
#define UI_H
#include <bits/stdc++.h>
#include "../Bike/MotorBike.h"
#include "../User/Member.h"

// #include "../User/Admin.h"
// void welcome ();
int user_choice ();
int menu (int choice); //choice for each type of user

class System {
   private:
      std::vector<Member*> memberVector;
      std::vector<MotorBike*> motorBikesVector;
   public:
      System();
      ~System();
      void beginUI();
      int loadMembers();   //get all member info into vector
      int loadBikes();  //get all bike info into vector

};
#endif   //UI_H