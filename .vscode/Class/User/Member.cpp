#include "Member.h"  //include header
#include "User.cpp"  //include parent cpp files

std::string memberIDgenerate(){
   // srand(time(NULL));
   int num = rand() % 1001; //random number form 0-100
   return ("Mb-"+std::to_string(num));
}

Member::Member(){} //default constructor

Member::Member(std::string i_username = "", std::string i_password = "",
               std::string i_fullName = "", std::string i_phoneNumber = "", std::string i_location = "",
               std::string i_id_type = "", std::string i_IDNum = "", int i_credits = 0,
               std::string i_licenseID = "", std::string i_expDate = "", float i_memberRating = 0)
    : User(i_username, i_password), 
      fullName(i_fullName), phoneNumber(i_phoneNumber), memLocation(i_location),
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

void Member::addBike(){
   std::string model, color, mode,enginerSize, year,location;

   std::cout << "Enter Bike model:  " << std::endl;
   std::getline(std::cin, model);

   std::cout <<"Enter color: " << std::endl;
   std::getline(std::cin, color);
   
   do {
      std::cout << "Enter engine size: " << std::endl;
      std::getline(std::cin, enginerSize);
   }while(!numValid(enginerSize));
   
   std::cout << "Enter year made: " << std::endl;
   
   
   std::getline(std::cin, year);

   std::cout<<"Enter mode " << std::endl;
   std::getline(std::cin, mode);
   
   //location
   
   //price to rent
}
bool Member::numValid(std::string input){
   if (std::stoi(input) > 57 || std::stoi(input) < 48) {
      return false;
   } else {
      return true;
   }
}
bool isYear(std::string s){
   
}