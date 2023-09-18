#include "UI.h"
#include "../Bike/MotorBike.cpp"
#include "../User/Member.cpp"
#include "../User/Admin.cpp"
#define BikeFile "../Class/Data/Bike.txt"
#define MEMBERFILE ".vscode/Data/Member.txt"

System::System (){}; //default constructor
System::~System(){   //destructor
   // delete memberVector;
}
void System::mainMenu (){
   std::cout << "====== EEET2482/COSC2082 ASSIGNMENT ======" << "\n";
   std::cout << "====== MOTORBIKE RENTAL APPLICATION ======" << "\n";

   std::cout << "Instructor: Dr. Ling Huo Chong" << "\n";
   std::cout << "Group: 22" << std::endl;

   std::cout << "\ts3818247, Nhat Nguyen" << "\n";
   std::cout << "\ts3977947, Thanh Do" << "\n";
   std::cout << "\ts3979896, Huan Nguyen" << "\n";
   std::cout << "\ts3938194, Quan Ngo" << "\n";
   std::cout << "===========================================" << std::endl;

   std::cout << "Use the app as:" << std::endl;
   std::cout << "1. Guest\t2. Member\t3.Admin" << std::endl;
   
   int choice = menuChoice(1,3);
   switch (choice){
      case 1:
         guestMenu();
         break;
      case 2:
         loginMemberMenu();
         break;
      case 3:
         loginAdminMenu();
         break;
      case 4:
         //save everything to txt file
         break;
   }

}

void System::guestMenu(){
   std::cout << "===========================================" << std::endl;
   std::cout << "               -Guest Menu-                " << std::endl;
   std::cout << "1. View motorbike\n";
   std::cout << "2. Sign up\n";
   std::cout << "3. Back to main menu\n";
   std::cout << "Enter your choice: ";
   
   int choice = menuChoice(1,3);
   switch (choice){
      case 1:
         // showBikeList(); //for guest
         break;
      case 2:
         //registerMember();
         break;
      case 3:
         mainMenu();
         break;

   }
}

void System::loginMemberMenu(){   //before login
   std::string username, password;
   std::cout << "===========================================" << std::endl;
   std::cout << "                -Member Menu-              " << std::endl;
   std::cout << "1. Login as member\n";
   std::cout << "2. Back to main menu" << std::endl;
   
   int choice;
   choice = menuChoice(1,2);
   
   switch (choice) {
   case 1:
      std::cout << "Enter Member Username: ";
      std::cin >> username;
      std::cin.ignore(0,' ');
      std::cout << "Enter Member Password: ";
      std::cin >> password;
      if (loginMember(username, password)) { //if true -> login successfully
         memberMenu();
         break;
      }
   case 2:
      mainMenu();
      break;
   }
}
void System::loginAdminMenu(){
   std::string username, password;
   std::cout << "===========================================" << std::endl;
   std::cout << "                -Admin Menu-               " << std::endl;
   std::cout << "1. Log in" <<std::endl;
   std::cout << "2. Back to main menu" << std::endl;
   
   int choice;
   choice = menuChoice(1,2);
   
   switch (choice) {
   case 1:
      std::cout << "Enter Admin Username: ";
      std::cin >> username;
      std::cin.ignore(0,' ');
      std::cout << "Enter Admin Password: ";
      std::cin >> password;
      if (loginAdmin(username, password)) {
         adminMenu();
         break;
      }
   case 2:
      mainMenu(); 
      break;
   }
   
}
void System::memberMenu() {  //after login successful


}
void System::adminMenu(){  //after login successful
   std::cout << "===========================================" << std::endl;
   std::cout << "              -Admin Menu-                 " << std::endl;
   std::cout << "1. View all members" <<std::endl; 
   std::cout << "2. View all motorbikes" <<std::endl;
   std::cout << "3. Back to main menu" <<std::endl;
}


std::vector <std::string> splitString(std::string &str, char delimiter){
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
   // MODE mode;
   // LOCATION location;
   // STATUS status;
   if (!bikeFile) {
      std::cerr << "Couldn't open file " <<std::endl;
      return -1;
   }
   std::string dataLine;
   char delim ='|';

   while(std::getline(bikeFile,dataLine)) {
      std::vector<std::string> dataList;
      dataList = splitString (dataLine,delim);

      MotorBike *bike = new MotorBike(dataList[1], dataList[2], std::stoi(dataList[3]),
                                      std::stoi(dataList[4]), dataList[5], std::stoi(dataList[6]),
                                      dataList[7], std::stof(dataList[8]), std::stof(dataList[9]),
                                      dataList[10], dataList[11], dataList[12]); // need attributes
      motorBikesVector.push_back(bike);
   }
   bikeFile.close();
   return 0;
}

void System::loadMembers(){
   memberVector.clear();
   std::string line;
   
   std::ifstream memberFile{MEMBERFILE}; 
   // memberFile.open(MEMBERFILE, std::ios::in);
   if(!memberFile.is_open()){
      std::cerr << "Couldn't open 'Member.txt'" << std::endl;
   }
   while (std::getline(memberFile, line)){      
      std::vector<std::string> dataList;
      dataList = splitString (line, '|');
      
      Member *member = new Member(dataList[3], dataList[4],
                                  dataList[5], dataList[6], std::stoi(dataList[7]),
                                  dataList[8], dataList[9], std::stof(dataList[10])); // add attributes
      memberVector.push_back(member);
   }
   memberFile.close();  
}
void System::adminViewMembers(){
   int index = 0;
   std::cout << "Member in the system: "<<std::endl;
   std::cout << std::left << std::setw(10) << "-Index- "
             << std::left << std::setw(15) << "-Member_ID-" 
             << std::left << std::setw(15) << "-Full Name-"
             << std::endl;
   for (auto mem : memberVector) {
      std::cout << std::left << std::setw(13) << index
                << std::left << std::setw(13) << mem->memberID
                << std::left << std::setw(15) << mem->fullName << std::endl;
      index++;
   }

}


int System::menuChoice(int start, int end) { 
   int finalChoice;
   bool flag = true;
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
      }
   } while (!flag);
   return finalChoice;
};
int System::loginMember(std::string username, std::string password){
    // function to login
    return 0;
};
int System::loginAdmin(std::string username, std::string password){
   return 1;
}

bool System::numValid(std::string input){
   if (std::stoi(input) > 57 || std::stoi(input) < 48) {
      return false;
   } else {
      return true;
   }
}

bool System::phoneNumValid(std::string phoneNumber){

};
