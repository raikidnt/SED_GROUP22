#include "Member.h"  //include header
#include "User.cpp"  //include parent cpp files
#define INITAIL_BIKE_RATING 10.0
#define BIKE_FILE ".vscode/Data/Bike.txt"
#define REQUEST_FILE ".vscode/Data/Request.txt"
#include "../Request/Request.cpp"

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
}

void Member::viewRequest(){
   int index = 0;
   int order= 1;
   std::vector<int>track;
   int choice,choice2;
   std::cout << "All requests" << std::endl;
   std::cout << std::left << std::setw(10) << "-Index- "
             << std::left << std::setw(15) << "-RequestID-"
             << std::left << std::setw(15) << "-Start date-"
             << std::left << std::setw(20) << "-Return date-"
             << std::left << std::setw(15) << "-Bike ID-"
             << std::left << std::setw(15) << "-Status-"
             << std::endl;
   for (Request *rqst : requestVector) {
      if (this->bikeID == rqst->bike_id){ //if this member bike is equal to the request bike then show info
         std::cout << std::left << std::setw(10) << index
               << std::left << std::setw(15) << rqst->requestID
               << std::left << std::setw(15) << rqst->startDate
               << std::left << std::setw(20) << rqst->returnDate
               << std::left << std::setw(15) << rqst->bike_id
               << std::left << std::setw(15) << rqst->status
               << std::endl;
      order++; //for show only
      }
      index++;
      track.push_back(index); //remember which bike at which index is show on list
   }
   std::cout << "Menu:  " << std::endl;
   std::cout << "1. Select request " << std::endl;
   std::cout << "2. Back to Member menu " << std::endl;
   choice = menuChoice(1,2);
   switch (choice) {
   case 1:
      std::cin.ignore();
      choice2 = menuChoice2(1, order, track);      //index of the request in vector
      
      
      // acceptRequest(choice2); //set status of the request

      break;
   case 2:
      break;
   }
}

std::string Member::listBike(){
   std::string c;
   do{
      std::cout << "List bike for rent (Y/N): " ;
      std::getline (std::cin,c);
   } while (!ischar(c));
   return c;
}
std::string Member::unlistBike(){
   std::string c;
   do{
      std::cout << "List bike for rent (Y/N): " ;
      std::getline (std::cin,c);
   } while (!ischar(c));
   return c;
}

bool Member::ischar(std::string s){
   std::regex reg ("^[ynYN ]+$"); //only char and num
   std::string str;
   str = stringCut(s);
   if (!std::regex_match(s, reg)){ return false; }
   
   return true;
   
}
void Member::topUp(){
   std::string newcredits;
   do{   
      std::cout << "Enter the amount of credits: ";
      std::getline(std::cin, newcredits);
   } while(!isNum(newcredits));
   
   std::string pass;
   std::cout << "Enter password: ";
   std::getline(std::cin, pass);
   if (this->password == pass){
      this->credits += std::stoi(newcredits);
   }
}
bool Member::isNum(std::string s) { // first 0, 10 char, all num
   for (int i = 0; i < s.length(); i++) {
      if (s[i] < '0' || s[i] > '9')
         return false;
   }
   return true;
}
void Member::loadRequest(){    
   requestVector.clear();    
   std::string line;    
   std::ifstream requestFile{REQUEST_FILE};     
   // requestFile.open(REQUEST_FILE, std::ios::in);    
   if(!requestFile.is_open()){       
      std::cerr << "Couldn't open 'Request.txt'" << std::endl;    
   }    
   while (std::getline(requestFile, line)){             
      std::vector<std::string> dataList;       
      dataList = splitString (line, '|');
      Request *request = new Request(dataList[0], dataList[1], dataList[2],
                                     dataList[3], dataList[4], dataList[5]); // add attributes
   requestVector.push_back(request);    
   }    
   requestFile.close();   
   std::cout <<"Load successful" << std::endl;
}
void Member::sendRequest(std::string ownerbikeID){
   requestVector.clear();
   std::cout << "before"<<requestVector.size() <<std::endl;

   std::string requestID, renterID, 
   startdate, returndate, status = "PENDING";
   renterID = this->memberID;   
   do {
      do {
         std::cout << "Enter start day to rent: ";
         std::getline(std::cin, startdate);
      } while (!isDateFormat(startdate));
      do {
         std::cout << "Enter day of return : ";
         std::getline(std::cin, returndate);
      } while (!isDateFormat(returndate));
   } while(!isDateGood(startdate,returndate));

   Request *rqst = new Request(requestID, renterID, 
                               returndate, startdate,
                               ownerbikeID, status);
   requestVector.push_back(rqst);
   std::cout << requestVector.size() <<std::endl;
   std::cout << "=====================================================" << std::endl;
   std::cout << "|            Request Send Successfully             |" << std::endl;
   std::cout << "=====================================================" << std::endl;

}
void Member::saveRequesttoFile(){
   std::ofstream requestFile{REQUEST_FILE};
   if (!requestFile){
      std::cerr << "Couldn't open file " << REQUEST_FILE << std::endl;
      return;
   }
   for (int i = 0; i < requestVector.size(); i++) {
      
      requestFile << requestVector[i]->requestID << "|"
                  << requestVector[i]->renterID << "|"
                  << requestVector[i]->returnDate << "|"
                  << requestVector[i]->startDate << "|"
                  << requestVector[i]->status << "|"
                  << requestVector[i]->bike_id << "|"
                  << "\n";
   }
   requestFile.close();
   // std::cout << "save done" << std::endl;
}
bool isDateGood(std::string start,std::string end){
   std::string sdate = start.substr(0,2);
   std::string smonth = start.substr(3,2);
   std::string syear = start.substr(6,4);
   
   std::string edate = end.substr(0,2);
   std::string emonth = end.substr(3,2);
   std::string eyear = end.substr(6,4);
   if ((std::stoi(eyear) - std::stoi(syear)) < 0) { return false; }
   if ((std::stoi(emonth) - std::stoi(smonth)) < 0) { return false; }
   if ((std::stoi(edate) - std::stoi(sdate)) < 0) { return false; }
   return true;
}
bool isDateFormat(std::string s){ //dd/mm/yyyy
   std::string date = s.substr(0,2);
   std::string month = s.substr(3,2);
   std::string year = s.substr(6,4);
   for (int i = 0; i < s.length(); i++) {
      if (i == 2 || i ==5){
         if (s[i] != '/'  ){
            std::cout << "Invalid date. Must follow format DD/MM/YYYY" << std::endl;
            return false;
         }
      }
   }
   if (std::stoi(date) < 0 || std::stoi(date) > 31) { // 1-30:valid
      std::cout << "Invalid date (1-30)" <<std::endl;
      return false;
   }
   if (std::stoi(month) < 0 || std::stoi(month) > 13) { // 1-12:valid
      std::cout << "Invalid month (1-12)" <<std::endl;
      return false;
   } 
   else if (std::stoi(year) < 2023){  // not greater 2023 = expired
      std::cout << "Invalid year (> 2023)" <<std::endl;
      return false;
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
int Member::menuChoice2(int start, int end,std::vector<int> vect) { 
   int finalChoice;
   bool flag;
   std::string tempo;
   do{
      std::cout << "Enter your bike choice: ";
      std::cin >> tempo;
      if (numValid(tempo)){   //check if the input is number
         std::cout <<"Only enter number as choice! Try again!"<<std::endl;
         flag = false;
         continue;
      }
      finalChoice = std::stoi(tempo);
      for (int i = 0; i < vect.size(); i++) {
         if (finalChoice > (vect.size() + 1) || finalChoice < 0) {
            std::cout << "Enter choice in the range " << start << " - " << end << " only!" << std::endl;
            flag = false;
         }
         else
         {
            flag = true;
         }
      }
   } while (!flag);
   return vect[finalChoice];
};

bool Member::numValid(std::string input){
   if (std::stoi(input) > 57 || std::stoi(input) < 48) {
      return false;
   } else {
      return true;
   }
}
void Member::acceptRequest(int choice2){
   int choice;
   std::cout << "Choose action:\t1. Accept\t2. Decline\n";
   choice = menuChoice(1,2);
   switch(choice){
      case 1:
         requestVector[choice2]->status = "Accepted";
         break;
      case 2:
         requestVector[choice2]->status = "Declined";
   }
}