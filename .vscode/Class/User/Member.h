#ifndef MEMBER_H
#define MEMBER_H
#include <bits/stdc++.h>

class Member {
   private:
      std::string memberID;

      int phoneNumber;
      enum {CCCD,CMND,PASPORT} IDTYPE;
      int IDNum;
      
      std::string drvLicenseID;
      std::string expDate;

      int availCredits;
      bool own_bike;
      std::string bikeID; 
   public:
      std::string fullName;
      int rating;
      Member();
      Member(std::string i_fullName, int i_phoneNumber,
             IDTYPE &i_idType, int i_IDNum, std::string i_licenseID, 
             std::string i_liscenceExpDate, int i_credits);
      int MemberLogin();
      int MemberLogout();

      void viewMotorBikes();
      void rentMotorBikes();
      int topUp();   //add addtional money to current account
      int addBike(); 

      void listBike();  //list bike to be available
      void unlistBike();   //remove bike from list

      void viewRequest();  //view coming requests from other members

      void review(); //review renter

}


#endif