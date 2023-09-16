#include "UI.h"
#include <iostream>
#include "../Bike/MotorBike.cpp"
#include "..\User\Member.cpp"

#define BikeFile "../Class/Data/Bike.txt"
#define MemberFile "../Class/Data/Member.txt"

System::System (){}; //default constructor
System::~System(){   //destructor
   // delete memberVector;
}
void System::beginUI (){
   std::cout << "====== EEET2482/COSC2082 ASSIGNMENT ======" << "\n";
   std::cout << "====== MOTORBIKE RENTAL APPLICATION ======" << "\n";

   std::cout << "Instructor: Dr. Ling Huo Chong" << "\n";
   std::cout << "Group: 22" << std::endl;

   std::cout << " s3818247, Nhat Nguyen" << "\n";
   std::cout << " s3977947, Thanh Do" << "\n";
   std::cout << " s3979896, Huan Nguyen" << "\n";
   std::cout << " s3938194, Quan Ngo" << "\n";
}

int user_choice (){
   int choice = 0;
   std::cout << "Use the app as:" << std::endl;
   std::cout << "1. Guest\t2. Member\t3.Admin" << std::endl;
   std::cout << "Enter your choice: ";
   std::cin >> choice;
   return choice;
}
//----------------------------------------------------------------//
int menu (int choice){ //choice for each type of user
   int menu_choice = 0;
   std::cout << "This is your menu:\n";
   switch (choice){
      case 1:  //Guest
         std::cout << "1. Exit!\n";
         std::cout << "2. View motorbike\n";
         std::cout << "3. Sign up\n";
         std::cout << "Enter your choice: "; 
         std::cin >> menu_choice;
         break;
      case 2:  //Member 
         std::cout << "1. Exit!" <<std::endl;
         std::cout << "2. View your personal information\n";
         std::cout << "3. Rent motobike\n";
         std::cout << "Enter your choice: "; 
         std::cin >> menu_choice;
         break;
      case 3:  //Admin
         std::cout << "1. Exit\n";
         std::cout << "2. View all members info\n";
         std::cout << "Enter your choice: "; 
         std::cin >> menu_choice;
         break;
      default:
         menu_choice = 0;
         break;
   }
   return menu_choice;
}
std::vector <std::string> splitString(std::string &str, char &delimiter){
   std::vector <std::string> result;
   std::istringstream is(str);
   std::string item;
   while (std::getline(is,item, delimiter)){
      result.push_back(item);
   }
   return result;
}  

int System::loadBikes(){
   std::fstream bikeFile;
   bikeFile.open(BikeFile, std::ios::in);
   MODE mode;
   LOCATION location;
   STATUS status;
   if (!bikeFile) {
      std::cerr << "Couldn't open file " <<std::endl;
      return -1;
   }
   std::string dataLine;
   char delim ='|';

   while(std::getline(bikeFile,dataLine)) {
      std::vector<std::string> dataList;
      dataList = splitString (dataLine,delim);
      for (int i = 0; i < dataList.size(); i++) {
         if(dataList[i] == "unknown") {mode = unknown;}
         else if(dataList[i] == "automation"){mode = automation;}
         else if(dataList[i] == "manual"){mode = manual;}

         if(dataList[i] == "SG"){location = SG;}
         else if(dataList[i] == "HN"){location = HN;}

         if(dataList[i] == "AVAILABLE") {status = AVAILABLE;}
         else if (dataList[i] == "UNAVAILABLE"){status = UNAVAILABLE;}   
      }
      
      MotorBike *bike = new MotorBike(dataList[1], dataList[2], std::stoi(dataList[3]),
                                      std::stoi(dataList[4]), mode, std::stoi(dataList[6]),
                                      location,std::stof(dataList[8]),std::stof(dataList[9]),
                                      dataList[10],status,dataList[12]); // need attributes
      motorBikesVector.push_back(bike);
   }
   bikeFile.close();
   return 0;
}

int System::loadMembers(){
   std::fstream memberFile;
   memberFile.open(MemberFile, std::ios::in);
   if(!memberFile){
      std::cerr<< "Couldn't open MemberFile!"<<std::endl;
      return -1;
   }
   std::string line;
   char delim = '|';

   while (std::getline(memberFile, line)){
      std::vector<std::string> dataList;
      dataList = splitString (line,delim);
      IDTYPE type;
      for (int i = 0; i < dataList.size(); i++) {
         if (dataList[i] == "CITIZEN_ID"){type = CITIZEN_ID;}
         else if (dataList[i] == "PASSPORT"){type = PASSPORT;}
      }

      Member *member = new Member(dataList[3], std::stoi(dataList[4]),
                                  type, std::stoi(dataList[6]), std::stoi(dataList[7]),
                                  std::stoi(dataList[8]), dataList[9], std::stof(dataList[10])); // add attributes
      memberVector.push_back(member);
   }
   memberFile.close();
   return 0;   
}