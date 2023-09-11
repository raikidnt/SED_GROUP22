#include "Member.h"  //include header
#include <bits/stdc++.h>
#include "User.cpp"  //include parent cpp files
#include "../Bike/MotorBike.cpp"//include cpp file of bike class\#include "../Bike/MotorBike.h"
Member::Member(){} //default constructor

Member::Member(std::string i_fullName, int i_phoneNumber, IDTYPE i_id_type, int i_IDNum, std::string i_licenseID, std::string i_expDate, float i_rating, int i_credits)
    : fullName(i_fullName), phoneNumber(i_phoneNumber), id_type(i_id_type), IDNum(i_IDNum), licenseID(i_licenseID), expDate(i_expDate), rating(i_rating), credits(i_credits) {}

void Member::showInfo_M(){
   std::cout << "- Name: \t" << fullName << " \tPhone#: 0" << phoneNumber << std::endl;
   std::cout << "- ID Type: \t";
   switch (id_type) {
      case 0:
         std::cout << "CCCD";
         break;
      case 1:
         std::cout << "CMND";
         break;
      case 2:
         std::cout << "PASSPORT";
         break;
      default:
         std::cout << "Invalid";
         break;
   }
   std::cout << "\tID#: " << IDNum << std::endl;
   std::cout << "- DRV-License#: " << licenseID << "\t ExpDate: " << expDate << std::endl;
   std::cout << "- Rating: " << rating << "\tCredits: " << credits << std::endl;
   std::cout << "================================================================" << std::endl;
   if (own_bike) {   //check if owner have motorBike
      // MotorBike::showBikeInfo(bikeID);
      // MotorBike a;
      // a.showBikeInfo(bikeID);
      std::cout << "Own bikes: " << std::endl;
   } else {
      std::cout << "Bike not found!" << std::endl;
   }
}
int Member::addBike(MotorBike &bike) {
   this->bikeID = bike.bikeID;   //remember the id of the bike
   own_bike = true;  
   return 0;
}

// int Member::searchBike (std::string bikeID){
//    std::fstream fileBike;
//    fileBike.open("Bike.txt", std::ios::in);
//    if (!fileBike){
//       std::cerr << "Error: Couldn't open file" << std::endl;
//       return -1;
//    }
//    std::string tempo;
//    while (!fileBike.eof()){
//       fileBike >> tempo;
//       if (tempo == bikeID){
//          cout << "Bike found" << std::endl;
//          break;
//       }
//    }
// }