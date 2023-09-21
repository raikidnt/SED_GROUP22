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
   std::string memLocation;   //location of member

   std::string bikeID;  //remember bike by its ID
   
   int credits;
   float memberRating;  //score
   bool bikeOnRent; //to determine if the bike is available to rent or not
   bool own_bike;
public:
   std::string fullName;
   std::string licenseID;
   std::string expDate;

   Member();
   // Member(std::string i_username, std::string i_password,
   //        std::string i_fullName, std::string i_phoneNumber, std::string i_location,
   //        std::string i_id_type, std::string i_IDNum, int i_credits,
   //        std::string i_licenseID, std::string i_expDate, float i_memberRating);
   Member(std::string i_username, std::string i_password,
          std::string i_fullName, std::string i_phoneNumber, std::string i_location,
          std::string i_id_type, std::string i_IDNum, int i_credits,
          std::string i_licenseID, std::string i_expDate, float i_memberRating,std::string i_bikeID);

   // int MemberLogin(std::string username, std::string password);   
   // int MemberLogout();
   
   void showInfo_M();

   // void viewMotorBikes();
   // void rentMotorBikes();
   int topUp(); // add addtional money to current account
   // int addBike(MotorBike &bike);
   void addBike ();  //add entirely new bike to member

   void listBike();  //set status to available and other parameters
   void unlistBike();   //set status to unavailable and other parameters

   void sendRequest();
   void viewRequest();  //view all request 
   void acceptRequest();
   void declineRequest();
   
   void viewHistory(); //view all history rentings
   int menuChoice(int start, int end);
   // int searchBike(std::string bikeID);
   // void listBike(std::string bikeID);   // list bike to be available
   // void unlistBike(std::string bikeID); // remove bike from list

   // void viewRequest(); // view coming requests from other members

   // void review(); // review renter
   // friend class MotorBike;
   bool numValid(std::string s);
   bool isYear(std::string s);
   bool isBikeModel(std::string model);
   bool isBikecolor(std::string color);
   bool isBikeEngineSize(std::string engineSize);
   bool isMinRating(std::string rating);
   bool isRentPrice(std::string rentPrice);


   friend class Admin;
   friend class System;

   friend class Request;
   friend class BikeRating;
   friend void RateBike();
   friend class RateRenter;
};
std::string memberIDgenerate();
#endif