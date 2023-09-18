#include "Member.h"  //include header
#include <bits/stdc++.h>
#include "User.cpp"  //include parent cpp files
// #include "../Bike/MotorBike.cpp"//include cpp file of bike class\#include "../Bike/MotorBike.h"

std::string memberIDgenerate(){
   // srand(time(NULL));
   int num = rand() % 1001; //random number form 0-100
   return ("M-"+std::to_string(num));
}

Member::Member(){} //default constructor

Member::Member(std::string i_fullName = "", std::string i_phoneNumber = "",
               std::string i_id_type = "", std::string i_IDNum = "", int i_credits = 0,
               std::string i_licenseID = "", std::string i_expDate = "", float i_memberRating = 0)
    : fullName(i_fullName), phoneNumber(i_phoneNumber),
      id_type(i_id_type), IDNum(i_IDNum), credits(i_credits),
      licenseID(i_licenseID), expDate(i_expDate), memberRating(i_memberRating)
{
   memberID = memberIDgenerate();
}

void Member::showInfo_M(){
   std::cout << "- Name: \t" << fullName << " \tPhone#: " << phoneNumber << std::endl;
   std::cout << "- ID Type: \t" << id_type << "\tID#: " << IDNum << std::endl;
   std::cout << "- DRV-License#: " << licenseID << "\t ExpDate: " << expDate << std::endl;
   std::cout << "- Rating: " << memberRating << "\tCredits: " << credits << std::endl;
   std::cout << "================================================================" << std::endl;
   //show own bike???
}
// int Member::MemberLogin(std::string usename, std::string password) {
   // User::UserLogin(username,password);
   // return 0;
// }
// int Member::addBike(MotorBike &bike) {
//    this->bikeID = bike.bikeID;   //remember the id of the bike
//    own_bike = true;  
//    return 0;
// }
