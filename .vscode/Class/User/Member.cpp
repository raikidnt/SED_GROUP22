#include "Member.h"  //include header
#include "User.cpp"  //include parent cpp files
#define INITAIL_BIKE_RATING 10.0
#define BIKE_FILE ".vscode/Data/Bike.txt"

std::string memberIDgenerate(){
   // srand(time(NULL));
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
Member::Member(std::string i_username = "", std::string i_password = "",
               std::string i_fullName = "", std::string i_phoneNumber = "", std::string i_location = "",
               std::string i_id_type = "", std::string i_IDNum = "", int i_credits = 0,
               std::string i_licenseID = "", std::string i_expDate = "", float i_memberRating = 0,std::string i_bikeID = "")
    : User(i_username, i_password), 
      fullName(i_fullName), phoneNumber(i_phoneNumber), memLocation(i_location),
      id_type(i_id_type), IDNum(i_IDNum), credits(i_credits),
      licenseID(i_licenseID), expDate(i_expDate), memberRating(i_memberRating),bikeID(i_bikeID)
{
   memberID = memberIDgenerate();
   if (i_bikeID != "null"){own_bike = true;}
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
   std::string model, color, engineSize,
       year, mode, price = "0",
       location, mem_rate="0",
       description, status="", duration="0";
   std::cout << "=====================================================" << std::endl;
   std::cout << "|               -Motorbike Registration-            |" << std::endl;
   std::cout << "=====================================================" << std::endl;
   std::cin.ignore();
   do{
      std::cout << "Enter Bike model:  "; //bikemodel
      std::getline(std::cin, model);
   } while(!isBikeModel(model));
   
   do{
   std::cout <<"Enter color: ";  //color  
   std::getline(std::cin, color);
   } while(!isBikecolor(color));

   do {
      std::cout << "Enter engine size: "; //engine size
      std::getline(std::cin, engineSize);
   }while(!isBikeEngineSize(engineSize));
   
   do{
      std::cout << "Enter year made: ";   //yearmade
      std::getline(std::cin, year);
   } while (!isYear(year));

   std::cout << "Enter motorbike mode: " << std::endl; //mode
   std::cout<<"1. Manual\n2. Auto\n3. Unknown" << std::endl;
   int choice = menuChoice(1,3);
   switch (choice) {
      case 1:
         mode = "Manual";
         break;
      case 2:
         mode = "Auto";
         break;
      case 3:
         mode = "Unknown";
         break;
   }
   std::cout << "Enter motorbike location: "<< std::endl;   //location
   std::cout <<"1. HN\n2. SG\n3. DN\n";
   int choice2 = menuChoice(1,3);
   switch (choice2) {
      case 1:
         location = "HN";
         break;
      case 2:
         location = "SG";
         break;
      case 3:
         location = "DN";
         break;
   }

   std::cin.ignore();
   do {
      std::cout << "Enter description of the motorbike: "; //description
      std::getline (std::cin,description);
   } while (!isBikeModel(description));

   do {
      std::cout << "Enter your price to rent: ";   //rent price
      std::getline(std::cin,price);
   } while (!isRentPrice(price));
   do {
      std::cout << "Enter Member minimum rating to rent: " ;   //min member rating
      std::getline(std::cin, mem_rate);
   } while(!isMinRating(mem_rate));

   // std::cout << "List bike to rent: " <<std::endl; //list or unlist bike
   // std::cout << "1. Yes\n2. No" << std::endl;
   // int choice3 = menuChoice(1,2);
   // switch(choice3) {
   //    case 1:
   //       status = "Available";
   //       break;
   //    case 2:
   //       status = "Unavailable";
   //       break;
   // }
   
   // std::cin.ignore();
   // if (status == "Available"){
   //    do {
   //       std::cout << "Enter rent duration: ";  //duration
   //       std::getline (std::cin,duration);
   //    } while (!isRentPrice(duration));
   // } else if (status == "Unavailable"){
   //    duration = "0";
   // }

   MotorBike *bike = new MotorBike(model, color, std::stoi(engineSize),
                                 std::stoi(year), mode, std::stoi(price),
                                 location, INITAIL_BIKE_RATING, std::stof(mem_rate),
                                 description, status, duration);
   std::fstream file;
   file.open(BIKE_FILE, std::ios::app);   //add new bike file
   file << "\n" << bike->bikeID << "|"
        << bike->model << "|"
        << bike->color << "|"
        << bike->engineSize << "|"
        << bike->yearMade << "|"
        << bike->mode << "|"
        << bike->rentPrice << "|"
        << bike->location << "|"
        << bike->bikeRating << "|"
        << bike->memberRating << "|"
        << bike->description << "|"
        << bike->status << "|"
        << bike->rentDuration;
   file.close();

   this->bikeID = bike->bikeID;  //set bike id to member
   this->own_bike = true;   //set boolean for bike ownership
   
   std::cout << "=====================================================" << std::endl;
   std::cout << "|            Motorbike Added Successfully           |" << std::endl;
   std::cout << "=====================================================" << std::endl;
   return;  
}
void Member::listBike(){
   std::string c;
   std::cout << "List bike for rent. Confirm? (Y/N) - ";
   std::getline(std::cin,c);
   // std::cin.ignore();
   if (c == "Y" || c == "y"){this->bikeOnRent = true;}
   else if (c == "N" || c == "n") {this->bikeOnRent = false;}
}
void Member::unlistBike(){
   char c;
   std::cout << "Unlist bike to rent. Confirm? (Y/N) -  ";
   std::cin >> c;
   // std::cin.ignore();
   if (c == 'Y'|| c == 'y'){this->bikeOnRent = false;}
   else if (c == 'N'||c == 'n'){this->bikeOnRent = true;}
}

bool Member::numValid(std::string input){
   if (std::stoi(input) > 57 || std::stoi(input) < 48) {
      return false;
   } else {
      return true;
   }
}
bool Member::isYear(std::string s){
   if (std::stoi(s) < 1900){
      return false;
   }
   return true;
}
bool Member::isBikeModel(std::string model){
   for (int i; i < model.length(); i++){
      // model[i] is not symbol instead of space
      if (model[i] < 'A' || model[i] > 'Z' && model[i] < 'a' || model[i] > 'z' && model[i] != ' '){
         return false;
      }
   }
   return true;
}

bool Member::isBikecolor(std::string color){
   for (int i; i < color.length(); i++){
      // color[i] is not symbol instead of space
      if (color[i] < 'A' || color[i] > 'Z' && color[i] < 'a' || color[i] > 'z' && color[i] != ' '){
         return false;
      }
   }
   return true;
}
bool Member::isBikeEngineSize(std::string engineSize){
    if (std::stoi(engineSize) < 0 ){
        return false;
    }
    return true;
}

bool Member::isMinRating(std::string rating){
    if (std::stoi(rating) < 0 || std::stoi(rating) > 10){
        return false;
    }
    return true;
}
bool Member::isRentPrice(std::string rentPrice){
   if (std::stoi(rentPrice) < 0){ return false; }
   for (int i = 0; i < rentPrice.length(); i++) {
      if (rentPrice[i] < '0' || rentPrice[i] > '9'){
         return false;
      }
   }
   return true;
}
int Member::menuChoice(int start, int end) { 
   int finalChoice;
   bool flag;
   std::string tempo;
   do{
      std::cout << "Enter your choice: ";
      std::cin >> tempo;
      if (numValid(tempo)){   //check if the input is number
         std::cout <<"Only enter number as choice! Try again!"<<std::endl;
         flag = false;
         continue;
      }
      finalChoice = std::stoi(tempo);
      if (finalChoice > end || finalChoice < start){  //check if the input is in range
         std::cout << "Enter choice in the range " << start << " - " << end << " only!" << std::endl;
         flag = false;
      }else{
         flag = true;
      }
   } while (!flag);
   return finalChoice;
};