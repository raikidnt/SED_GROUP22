#ifndef REQUEST_H
#define REQUEST_H
#include <bits/stdc++.h>

class Request {
   private:
      int requestID;
      std::string renterID;   //member
      std::string returnDate;
   public:
      Request();  

      void request(std::string i_renterID); 

      int rentTotal();


};

#endif