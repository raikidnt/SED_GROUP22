#ifndef UI_H
#define UI_H
#include <bits/stdc++.h>
#include "../Bike/MotorBike.h"
#include "../User/Member.h"
#include "../User/Admin.h"
#include "../bikeRating/bikeRating.h"
#include "../renterRating/renterRating.h"
#include "../Request/Request.h"
class System {
   private:
      std::vector<Member*> memberVector;
      std::vector<MotorBike*> motorBikesVector;

      std::vector <BikeRating*> bikeRatingVector;
      std::vector <RenterRating*> renterRatingVector;
      std::vector <Request*> requestVector;
      Admin *admin;
      MotorBike *current_motorBikes = nullptr;
      Member *current_member = nullptr;
   public:
      System();
      ~System();

      void mainMenu();  

      void guestMenu(); //guest menu   
      void loginMemberMenu(); 
      void loginAdminMenu();
            
      bool loginMember(std::string &username,std::string &password);   // function to login
      bool loginAdmin(std::string username,std::string password); // log in as a admin

      void memberMenu(); //after login as member
      void adminMenu();  //after login as admin

      void loadMembers();   //get all member info into vector
      void loadBikes();  //get all bike info into vector
      void loadAdmin(); //get admin to system
      
      // void loadBikeRatings();    //get all bike ratings into vector
      // void loadMemberRatings();  //get all member ratings into vector
      // void loadRequests(); //get all requests into vector

      void adminViewBike();
      void adminViewMembers();

      int menuChoice(int start, int end); //check for valid input (only number within range)

      bool numValid(std::string input);   //check for input a number

      void guestViewBike();
      void guestRegister();
      void listBikeMenu();
      void unlistBikeMenu();
      bool isPhoneNum(std::string s);  // first 0, 10 char, all num

      bool isPassword(std::string s);    // min length 8 char, no space

      bool isUsername(std::string s);  //no symbol, space, min length 6

      bool isFullname(std::string s); //no symbol, number, 

      bool isDateFormat(std::string s); //DD/MM/YYYY

      bool isLicence(std::string s); // 12 number, no space or symbol

      bool isIDValid(std::string s,int num); //

      void saveMembertoFile();
      void saveBiketoFile();

      void saveBikeRatingtoFile();
      void saveMemberRatingtoFile();

      void rentMenu(); //show bike base on current member location and rating
      friend class Member;
};

std::vector <std::string> splitString(std::string &str, char delimiter);
std::string stringCut(std::string s);
#endif   //UI_H