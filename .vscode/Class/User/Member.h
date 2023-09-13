#ifndef MEMBER_H
#define MEMBER_H

#include "User.h"
#include "../Bike/MotorBike.h"
#include <bits/stdc++.h>

enum IDTYPE {CCCD, CMND, PASSPORT};

class Member : public User {
private:
   std::string memberID;   //auto-generated
   int phoneNumber;  
   IDTYPE id_type;
   int IDNum;
   int credits;
   bool own_bike;
   std::string bikeID;  //remember bike by its ID
   std::vector <float> avgMemberRating;
public:
   std::string fullName;
   float rating;
   std::string licenseID;
   std::string expDate;

   Member();
   Member(std::string i_fullName, int i_phoneNumber,
          IDTYPE i_id_type, int i_IDNum, std::string i_licenseID,
          std::string i_expDate, int i_credits);
   // int MemberLogin(std::string username, std::string password);
   // int MemberLogout();
   
   void showInfo_M();

   // void viewMotorBikes();
   // void rentMotorBikes();
   int topUp(); // add addtional money to current account
   int addBike(MotorBike &bikes);
   // int searchBike(std::string bikeID);
   // void listBike();   // list bike to be available
   // void unlistBike(); // remove bike from list

   // void viewRequest(); // view coming requests from other members

   // void review(); // review renter
   // friend class MotorBike;
   friend class Admin;
};

#endif