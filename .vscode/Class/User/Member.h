#ifndef MEMBER_H
#define MEMBER_H

#include "User.h"
#include "../Bike/MotorBike.h"
#include <bits/stdc++.h>
std::string LOCATIONS[3] = {"HN", "SG", "DN"};
class Member : public User {
protected:
   // std::string member_username;
   // std::string member_password;
   std::string memberID;   //auto-generated
   std::string phoneNumber; 
   std::string id_type;
   std::string IDNum;
   std::string bikeID;  //remember bike by its ID
   std::string memLocation;   //location of member

   int credits;
   float memberRating;  //score
   
   bool own_bike;
public:
   std::string fullName;
   std::string licenseID;
   std::string expDate;

   Member();
   Member(std::string i_username, std::string i_password,
          std::string i_fullName, std::string i_phoneNumber, std::string i_location,
          std::string i_id_type, std::string i_IDNum, int i_credits,
          std::string i_licenseID, std::string i_expDate, float i_memberRating);

   // int MemberLogin(std::string username, std::string password);   
   // int MemberLogout();
   
   void showInfo_M();

   // void viewMotorBikes();
   // void rentMotorBikes();
   int topUp(); // add addtional money to current account
   // int addBike(MotorBike &bike);
   void addBike ();  //add entirely new bike to member
   bool numValid(std::string s);
   // int searchBike(std::string bikeID);
   // void listBike(std::string bikeID);   // list bike to be available
   // void unlistBike(std::string bikeID); // remove bike from list

   // void viewRequest(); // view coming requests from other members

   // void review(); // review renter
   // friend class MotorBike;
   friend class Admin;
   friend class System;

   friend class Request;
   friend class BikeRating;
   friend void RateBike();
   friend class RateRenter;
};
std::string memberIDgenerate();
#endif