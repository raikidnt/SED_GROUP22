#include "Member.h"  //include header
#include "User.cpp"  //include parent cpp files
#define INITAIL_BIKE_RATING 10.0
#define BIKE_FILE ".vscode/Data/Bike.txt"

std::string memberIDgenerate(){
   srand(time(NULL));
   int num = rand() % 1001; //random number form 0-100
   return ("Mb-"+std::to_string(num));
}

Member::Member(){} //default constructor

// Member::Member(std::string i_username = "", std::string i_password = "",
//                std::string i_fullName = "", std::string i_phoneNumber = "", std::string i_location = "",
//                std::string i_id_type = "", std::string i_IDNum = "", int i_credits = 0,
//                std::string i_licenseID = "", std::string i_expDate = "", float i_memberRating = 0)
//     : User(i_username, i_password), 
//       fullName(i_fullName), phoneNumber(i_phoneNumber), memLocation(i_location),
//       id_type(i_id_type), IDNum(i_IDNum), credits(i_credits),
//       licenseID(i_licenseID), expDate(i_expDate), memberRating(i_memberRating)
// {
//    memberID = memberIDgenerate();
// }
Member::Member(std::string i_username = "", std::string i_password = "", std::string i_memID="",
               std::string i_fullName = "", std::string i_phoneNumber = "", std::string i_location = "",
               std::string i_id_type = "", std::string i_IDNum = "", int i_credits = 0,
               std::string i_licenseID = "", std::string i_expDate = "", float i_memberRating = 0,std::string i_bikeID = "")
    : User(i_username, i_password), memberID(i_memID),
      fullName(i_fullName), phoneNumber(i_phoneNumber), memLocation(i_location),
      id_type(i_id_type), IDNum(i_IDNum), credits(i_credits),
      licenseID(i_licenseID), expDate(i_expDate), memberRating(i_memberRating),bikeID(i_bikeID)
{
   // memberID = memberIDgenerate();
   if (i_bikeID != "null"){own_bike = true;}
}

void Member::showInfo_M(){
   std::cout << "- Name: \t" << fullName << " \tPhone#: " << phoneNumber << std::endl;
   std::cout << "- ID Type: \t" << id_type << "\tID#: " << IDNum << std::endl;
   std::cout << "- DRV-License#: " << licenseID << "\t ExpDate: " << expDate << std::endl;
   std::cout << "- Rating: " << memberRating << "\tCredits: " << credits << std::endl;
   std::cout << "- Own bike " << own_bike << "\tBike ID " << bikeID << std::endl;
   std::cout << "================================================================" << std::endl;
   //show own bike???
}

