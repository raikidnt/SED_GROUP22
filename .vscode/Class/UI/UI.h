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
   public:
      std::vector<Member*> memberVector;
      std::vector<MotorBike*> motorBikesVector;
      System();
      ~System();
      void beginUI();
      void loadMembers();   //get all member info into vector
      int loadBikes();  //get all bike info into vector
      void showBikeList();
      void showMembersList();
};
#endif   //UI_H