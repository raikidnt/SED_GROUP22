#ifndef MEMBER_H
#define MEMBER_H

#include "User.h"
#include "../Bike/MotorBike.h"
#include <bits/stdc++.h>

enum IDTYPE {CITIZEN_ID, PASSPORT};

class Member : public User {
private:
   std::string memberID;   //auto-generated
   int phoneNumber;  
   IDTYPE id_type;
   int IDNum;
   int credits;
   bool own_bike;
   std::string bikeID;  //remember bike by its ID
   float memberRating;
public:
   std::string fullName;
   int licenseID;
   std::string expDate;

   Member();
   Member(std::string i_fullName, int i_phoneNumber,
          IDTYPE i_id_type, int i_IDNum,  int i_credits,
          int i_licenseID, std::string i_expDate,float i_memberRating);
   // int MemberLogin(std::string username, std::string password);   
   // int MemberLogout();
   
   void showInfo_M();

   // void viewMotorBikes();
   // void rentMotorBikes();
   int topUp(); // add addtional money to current account
   int addBike(MotorBike &bikes);
   // int searchBike(std::string bikeID);
   // void listBike(std::string bikeID);   // list bike to be available
   // void unlistBike(std::string bikeID); // remove bike from list

   // void viewRequest(); // view coming requests from other members

   // void review(); // review renter
   // friend class MotorBike;
   friend class Admin;
};

#endif