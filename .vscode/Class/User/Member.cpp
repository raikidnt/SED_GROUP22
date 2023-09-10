#include "Member.h"  
#include <bits/stdc++.h>
#include "User.cpp"  //include parent cpp files

Member::Member(){};  //default constructor
Member::Member(std::string i_fullName, int i_phoneNumber,
               IDTYPE i_idType, int i_IDNum, std::string i_licenseID,
               std::string i_liscenceExpDate, int i_credits){
   fullName = i_fullName;
   phoneNumber = i_phoneNumber;
   id = i_idType;
   IDNum = i_IDNum;
   LicenseID = i_licenseID;
   expDate = i_liscenceExpDate;
   credits = i_credits;
};

void Member::showInfo_M(){
   std::cout << "- Name: \t" << fullName << " \tPhone#: " << phoneNumber << std::endl;
   std::cout << "- ID Type: \t";
   switch (id) {
      case 0:
         std::cout << "CCCD";
         break;
      case 1:
         std::cout << "CMND";
         break;
      case 3:
         std::cout << "Passport";
         break;
      default:
         std::cout << "Invalid";
         break;
   }
   std::cout << "\tID#: " << IDNum << std::endl;
   std::cout << "- Driver license #: " << LicenseID << "\t ExpDate: " << expDate << std::endl;
   std::cout << "- Credits: " << credits << std::endl;
   std::cout << "================================================================" << std::endl;
   // if (own_bike) {   //check if owner have motorBike
   //    MotorBike::showInfo_B(bikeID);
   // } else {
   //    std::cout << "Bike not found!" << std::endl;
   // }
}
int Member::addBike(MotorBike &bike){
   
}