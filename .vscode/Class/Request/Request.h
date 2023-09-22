#ifndef REQUEST_H
#define REQUEST_H
#include <bits/stdc++.h>
// #include "../Bike/MotorBike.h"
// #include "../User/Member.h"


// enum STATUS {UNAVAILABLE, AVALABLE};
std::string STATUS[3] = {"DECLINE", "ACCEPT", "PENDING"};
class Request {
   protected:
      std::string requestID; // auto generated
      std::string renterID;   //member who rent
      std::string ownerID; //owner of the bike
      std::string startDate;
      std::string returnDate;
      std::string bike_id; //bike want to rent
      std::string status; //accept/decline/pending
      // int check;
   public:
      Request();
      Request(std::string requestID, std::string renterID,
              std::string returnDate, std::string startDate,
              std::string bike_id, std::string status);

      void setRequestID(std::string requestID);
      void setRenterID(std::string renterID);
      void setStartDate(std::string startDate);
      void setReturnDate(std::string returnDate);
      void setbikeID(std::string bike_id);
      // void updateRequest(int check);
      int getDiff(std::string start_date, std::string return_date);

      void sentrequest(std::string i_renterID); 
      // void getTime(std::string sDate, std::string rDate);
      bool validDate(std::string &date);
      std::vector<std::string> splitDate(std::string &date, char splitChar);

      // void checkRequest();

      // int rentTotal();


      friend class Motorbike;
      friend class Member;
      friend class RentHis;
      friend class RateRenter;
      friend class System;
      friend double totalPrice(double price);
};



#endif