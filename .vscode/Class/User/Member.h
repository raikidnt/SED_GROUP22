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
   Request *currentRequest;
   std::vector <RentHis*> RentHisVect;
public:
   std::string fullName;
   std::string licenseID;
   std::string expDate;

   Member();
   Member(std::string i_username, std::string i_password, std::string i_memID,
          std::string i_fullName, std::string i_phoneNumber, std::string i_location,
          std::string i_id_type, std::string i_IDNum, int i_credits,
          std::string i_licenseID, std::string i_expDate, float i_memberRating,std::string i_bikeID);

   void showInfo_M();

   void topUp(); // add addtional money to current account

   std::string listBike();  //set status to available and other parameters
   std::string unlistBike();   //set status to unavailable and other parameters

   void sendRequest(std::string ownerbikeID, int price);
   void loadRequest();
   void loadHistory();
   void viewRequest();  //view request belong to member
   void acceptRequest(int choice);
   void viewBikeHistory();
   void viewMemberHistory();
   void addRequesttoFile();

   void saveRequesttoFile();
   int menuChoice(int start, int end);
   int menuChoice2 (int start, int end, std::vector<int>track);
   bool ischar(std::string s);
   bool isNum(std::string s);
   bool numValid(std::string input);

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
   friend class RateRenter;
};
std::string memberIDgenerate();
bool isDateFormat(std::string s);
bool isDateGood(std::string start,std::string end);

#endif