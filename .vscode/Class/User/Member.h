#ifndef MEMBER_H
#define MEMBER_H
#include <bits/stdc++.h>

#include "User.h"
#include "../Bike/MotorBike.h"
#include "../Request/Request.h"
#include "../RentHistory/RentHistory.h"
std::string LOCATIONS[3] = {"HN", "SG", "DN"};

class Member : public User {
private:
   std::string memberID;   //auto-generated
   std::string phoneNumber; 
   std::string id_type;
   std::string IDNum;
   std::string memLocation;   //location of member

   std::string bikeID;  //remember bike by its ID
   
   int credits;
   float memberRating;  //score
   bool bikeOnRent; //to determine if the bike is available to rent or not
   bool own_bike = false;  //default
   
   std::vector <Request*> requestVector;
   std::vector <RentHis*> RentHisVect;
public:
   std::string fullName;
   std::string licenseID;
   std::string expDate;

   Member();
   // Member(std::string i_username, std::string i_password,
   //        std::string i_fullName, std::string i_phoneNumber, std::string i_location,
   //        std::string i_id_type, std::string i_IDNum, int i_credits,
   //        std::string i_licenseID, std::string i_expDate, float i_memberRating);
   Member(std::string i_username, std::string i_password, std::string i_memID,
          std::string i_fullName, std::string i_phoneNumber, std::string i_location,
          std::string i_id_type, std::string i_IDNum, int i_credits,
          std::string i_licenseID, std::string i_expDate, float i_memberRating,std::string i_bikeID);

   // int MemberLogin(std::string username, std::string password);   
   // int MemberLogout();
   
   void showInfo_M();

   // void viewMotorBikes();
   // void rentMotorBikes();
   void topUp(); // add addtional money to current account
   // int addBike(MotorBike &bike);
   // void addBike ();  //add entirely new bike to member

   std::string listBike();  //set status to available and other parameters
   std::string unlistBike();   //set status to unavailable and other parameters

   void sendRequest(std::string ownerbikeID, int price);
   void loadRequest();
   void loadHistory();
   void viewRequest();  //view request belong to member
   void acceptRequest(int choice);
   // void declineRequest();
   int cost(std::string startday,std::string endday);
   void viewBikeHistory();
   void viewMemberHistory();

   void saveRequesttoFile();
   int menuChoice(int start, int end);
   int menuChoice2 (int start, int end, std::vector<int>track);
   // int searchBike(std::string bikeID);
   bool ischar(std::string s);
   bool isNum(std::string s);
   bool numValid(std::string input);
   // void viewRequest(); // view coming requests from other members

   // void review(); // review renter
   // friend class MotorBike;
   // bool numValid(std::string s);
   // bool isYear(std::string s);
   // bool isBikeModel(std::string model);
   // bool isBikecolor(std::string color);
   // bool isBikeEngineSize(std::string engineSize);
   // bool isMinRating(std::string rating);
   // bool isRentPrice(std::string rentPrice);


   friend class Admin;
   friend class System;

   friend class Request;
   friend class BikeRating;
   friend void RateBike();
   friend class RateRenter;
};
std::string memberIDgenerate();
bool isDateFormat(std::string s);
bool isDateGood(std::string start,std::string end);

#endif