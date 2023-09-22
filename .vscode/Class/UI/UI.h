#ifndef UI_H
#define UI_H
#include <bits/stdc++.h>
#include "../Bike/MotorBike.h"
#include "../User/Member.h"
#include "../User/Admin.h"
#include "../bikeRating/bikeRating.h"
#include "../renterRating/renterRating.h"
// #include "../Request/Request.h"
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
      
      
      //dataloading function
      void loadMembers();   //get all member info into vector
      void loadBikes();  //get all bike info into vector
      void loadAdmin(); //get admin to system
      void loadRequest(); //get all requests into vector
      void loadBikeRatings();    //get all bike ratings into vector
      void loadMemberRatings();  //get all member ratings into vector
      //admin function
      void adminViewBike();
      void adminViewMembers();
      //guest function
      void guestViewBike();
      void guestRegister();
      //member function
      void addBike(); //add bike to system
      void rentBike(); //
      void viewBikeHistory(); // history of bike
      void viewRentHistory();//history of member
      

      int menuChoice(int start, int end); //check for valid input (only number within range)
      int menuChoice2(int start, int end, std::vector<int>);
      bool numValid(std::string input);   //check for input a number

      
      void listBikeMenu();
      void unlistBikeMenu();
      
      bool isPhoneNum(std::string s);  // first 0, 10 char, all num
      bool isPassword(std::string s);    // min length 8 char, no space
      bool isUsername(std::string s);  //no symbol, space, min length 6
      bool isFullname(std::string s); //no symbol, number, 
      bool isDateFormat(std::string s); //DD/MM/YYYY
      bool isLicence(std::string s); // 12 number, no space or symbol
      bool isIDValid(std::string s,int num); //

      bool isYear(std::string s);   //only num, 4 digits, > 1900
      bool isBikeModel(std::string s);    //limit to certain characters
      bool isBikecolor(std::string s);    //no num, only char
      bool isBikeEngineSize(std::string s);  //only num, > 0
      bool isMinRating(std::string s); //only num, 1-10
      bool isRentPrice(std::string S); //only num, no char
      bool ischar(std::string s);   

      // bool isDateGood(std::string start, std::string end);
      
      void saveMembertoFile();
      void saveBiketoFile();
      // void saveRequesttoFile();
      void saveBikeRatingtoFile();
      void saveMemberRatingtoFile();

      void rentMenu(); //show bike base on current member location and rating
      friend class Member;
};

std::vector <std::string> splitString(std::string &str, char delimiter);
std::string stringCut(std::string s);
#endif   //UI_H