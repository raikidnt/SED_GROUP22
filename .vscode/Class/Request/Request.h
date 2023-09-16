#ifndef REQUEST_H
#define REQUEST_H
#include <bits/stdc++.h>
#include <string>
#include <vector>
#include "../Bike/MotorBike.h"
#include "../User/Member.h"


enum STATUS {UNAVAILABLE, AVALABLE};
class Request : public Member {
   private:
      string requestID; // sửa datatype trong uml
      std::string renterID;   //member
      std::string returnDate;
      STATUS status; //available/unavailable status
      std::string startDate;
      std::string bike_id;
      int check;
   public:
      Request();
      Request(string requestID, string renterID, string returnDate, string startDate, STATUS status, string bike_id, int check)
      :requestID(requestID), renterID(renterID), returnDate(returnDate), startDate(startDate), status(status), bike_id(bike_id), check(check){};  

      void setRequestID(string requestID);
      void setRenterID(string renterID);
      void setStartDate(string startDate);
      void setReturnDate(string returnDate);
      void setbikeID(string bike_id);
      void updateRequest(int check);

      void sentrequest(std::string i_renterID); 
      // void getTime(std::string sDate, std::string rDate);
      bool isValid(std::string &date);
      vector<std::string> splitDate(std::string &date, char splitChar);

      void checkRequest();


      int rentTotal();

      friend class Motorbike;
      

};



#endif