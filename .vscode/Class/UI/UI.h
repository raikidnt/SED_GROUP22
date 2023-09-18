#ifndef UI_H
#define UI_H
#include <bits/stdc++.h>
#include "../Bike/MotorBike.h"
#include "../User/Member.h"
#include "../User/Admin.h"

class System {
   private:
   public:
      std::vector<Member*> memberVector;
      std::vector<MotorBike*> motorBikesVector;
      Admin *admin;
      MotorBike *current_motorBikes;
      Member *current_member = nullptr;
      System();
      ~System();

      void mainMenu();  

      void guestMenu(); //guest menu   
      void loginMemberMenu(); 
      void loginAdminMenu();
            
      int loginMember(std::string username,std::string password);   // function to login
      int loginAdmin(std::string username,std::string password); //log in as a admin

      void memberMenu(); //after login as member
      void adminMenu();  //after login as admin

      void loadMembers();   //get all member info into vector
      int loadBikes();  //get all bike info into vector
      
      void adminViewBike();
      void adminViewMembers();

      int menuChoice(int start, int end); //check for valid input (only number within range)

      bool numValid(std::string input);   //check for input a number
      bool phoneNumValid(std::string phoneNumber);

      // void mainMenu();
};
std::vector <std::string> splitString(std::string &str, char delimiter);

#endif   //UI_H