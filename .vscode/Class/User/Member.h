#ifndef MEMBER_H
#define MEMBER_H
#include <bits/stdc++.h>
// #include ".vscode\Class\User\User.h"
// #include ".vscode\Class\Bike\MotorBike.h"
enum IDTYPE {CCCD, CMND, PASSPORT};
class Member : public User {
private:
   std::string memberID;   //auto-generated
   int phoneNumber;
   IDTYPE id_type;
   int IDNum;
   std::string LicenseID;
   std::string expDate;
   int credits;
   bool own_bike;
   std::string bikeID;  //remember bike by its ID

public:
   std::string fullName;
   int rating;

   Member();
   Member(std::string i_fullName, int i_phoneNumber,
          IDTYPE i_idType, int i_IDNum, std::string i_licenseID,
          std::string i_liscenceExpDate, int i_credits);
   // int MemberLogin();
   // int MemberLogout();
   
   void showInfo_M();

   // void viewMotorBikes();
   // void rentMotorBikes();
   // int topUp(); // add addtional money to current account
   int addBike(MotorBike &bikes);

   // void listBike();   // list bike to be available
   // void unlistBike(); // remove bike from list

   // void viewRequest(); // view coming requests from other members

   // void review(); // review renter
   // friend class MotorBike;
   friend class Admin;
};

#endif