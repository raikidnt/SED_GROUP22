#ifndef REQUEST_H
#define REQUEST_H
#include <bits/stdc++.h>
#include <string>
#include <vector>
#include "../Bike/MotorBike.h"
#include "../User/Member.h"


enum STATUS {UNAVAILABLE, AVALABLE};
class Request : public Member {
   protected:
      std::string requestID; // sửa datatype trong uml
      std::string renterID;   //member
      std::string returnDate;
      STATUS status; //available/unavailable status
      std::string startDate;
      std::string bike_id;
      int check;
   public:
      Request::Request();
      Request::Request(std::string requestID, std::string renterID, std::string returnDate, std::string startDate, STATUS status, std::string bike_id, int check)
      :requestID(requestID), renterID(renterID), returnDate(returnDate), startDate(startDate), status(status), bike_id(bike_id), check(check){};  

      void setRequestID(std::string requestID);
      void setRenterID(std::string renterID);
      void setStartDate(std::string startDate);
      void setReturnDate(std::string returnDate);
      void setbikeID(std::string bike_id);
      void updateRequest(int check);
      int getDiff(std::string start_date, std::string return_date);

      void sentrequest(std::string i_renterID); 
      // void getTime(std::string sDate, std::string rDate);
      bool isValid(std::string &date);
      std::vector<std::string> splitDate(std::string &date, char splitChar);

      void checkRequest();


      int rentTotal();

      friend class Motorbike;
      friend class Member;
      friend class RentHis;
      friend double totalPrice(double price);

};



#endif