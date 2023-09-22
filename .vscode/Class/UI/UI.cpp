#include "UI.h"
#include "../Bike/MotorBike.cpp"
#include "../User/Member.cpp"
#include "../User/Admin.cpp"
// #include "../Request/Request.cpp"

#define BIKE_FILE ".vscode/Data/Bike.txt"
#define MEMBER_FILE ".vscode/Data/Member.txt"
#define ADMIN_FILE ".vscode/Data/Admin.txt"
#define MEMBER_RATING_FILE ".vscode/Data/MemberRating.txt"
#define BIKE_RATING_FILE ".vscode/Data/BikeRating.txt"
#define REQUEST_FILE ".vscode/Data/Request.txt"

#define INITIAL_RATING 10.0
#define INITIAL_CREDIT 20

System::System (){}; //default constructor
System::~System(){   //destructor
   // delete memberVector;
}
void System::mainMenu (){
   std::cout << "=============== EEET2482/COSC2082 ASSIGNMENT ===============" << "\n";
   std::cout << "=============== MOTORBIKE RENTAL APPLICATION ===============" << "\n";

   std::cout << "Instructor: Dr. Ling Huo Chong" << "\n";
   std::cout << "Group: 22" << std::endl;

   std::cout << "\t\t s3818247, Nhat Nguyen" << "\n";
   std::cout << "\t\t s3977947, Thanh Do" << "\n";
   std::cout << "\t\t s3979896, Huan Nguyen" << "\n";
   std::cout << "\t\t s3938194, Quan Ngo" << "\n";
   std::cout << "===========================================================" << std::endl;

   std::cout << "Use the app as:" << std::endl;
   std::cout << "1. Guest\t2. Member\t3. Admin\t4. Exit" << std::endl;
   loadMembers();
   loadBikes();
   loadAdmin();


   int choice = menuChoice(1,4);
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
         saveBiketoFile();
         saveMembertoFile();
         //save everything to txt file
         break;
   }

}

void System::guestMenu(){
   std::cout << "===========================================" << std::endl;
   std::cout << "|               -Guest Menu-              |" << std::endl;
   std::cout << "===========================================" << std::endl;
   loadMembers();
   loadBikes();
   loadAdmin();
   std::cout << "1. View motorbike\n";
   std::cout << "2. Sign up\n";
   std::cout << "3. Exit the program\n";

   int choice = menuChoice(1,3);
   switch (choice){
      case 1:
         guestViewBike();
         break;
      case 2:
         guestRegister();
         break;
      case 3:
         // mainMenu();
         saveMembertoFile();
         saveBiketoFile();
         break;
   }
}
void System::loginMemberMenu(){   //before login
   std::string username, password;
   std::cout << "===========================================" << std::endl;
   std::cout << "|               -Member Menu-             |" << std::endl;
   std::cout << "===========================================" << std::endl;

   std::cout << "1. Member Login\n";
   std::cout << "2. Back to main menu" << std::endl;
   loadMembers();
   // loadBikes();
   // loadAdmin();
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
         std::cout << "Login successfully" << std::endl;
         memberMenu();
         break;
      } else {
         std::cout << "Login Failed! Wrong username or password." << std::endl;
      }
   case 2:
      mainMenu();
      break;
   }
}
void System::loginAdminMenu(){
   std::string username, password;
   std::cout << "===========================================" << std::endl;
   std::cout << "|               -Admin Menu-              |" << std::endl;
   std::cout << "===========================================" << std::endl;

   std::cout << "1. Admin Login" <<std::endl;
   std::cout << "2. Back to main menu" << std::endl;
   std::cout << "===========================================" << std::endl;
   // loadMembers();
   // loadBikes();
   loadAdmin();
   int choice;
   choice = menuChoice(1,2);
   switch (choice) {
   case 1:
      loadAdmin();   
      std::cout << "Enter Admin Username: ";
      std::cin >> username;
      std::cin.ignore(0,' ');
      std::cout << "Enter Admin Password: ";
      std::cin >> password;
      if (loginAdmin(username,password)) {
         std::cout << "Login successfully!" <<std::endl;
         adminMenu();
         break;
      } else {
         std::cout << "Login failed! Wrong username or password!" <<std::endl;
      }
   case 2:
      mainMenu(); 
      break;
   }
   
}

bool System::loginMember(std::string &username, std::string &password){
   std::string bkID;
   for (Member *mem :memberVector){
      if (mem->username == username && mem->password == password) {
         current_member = mem;   //point at the current member
         // bkID = current_member->bikeID; 
         // for (auto &bk : motorBikesVector) {
         //    if (bk->bikeID == bkID) {
         //       current_motorBikes = bk;   //point at bike if member have bike
         //       std::cout << "Found bike"<<std::endl;
            // } 
            // else {
               // std::cout << "Bike not Found" <<std::endl;
               // current_motorBikes = nullptr;
            // }
         // }
         // current_member->showInfo_M();
         // current_motorBikes->showBikeInfo();
         return true;
      }
 
   }
   return false;
};
bool System::loginAdmin(std::string username, std::string password){
   if (this->admin->username == username && this->admin->password == password) {
      return true;
   } else {
      return false;
   }
}

void System::memberMenu() {  //after member login successful
   int choice;
   std::cout << "===========================================" << std::endl;
   std::cout << "|              -Member Menu-               |" << std::endl;
   std::cout << "===========================================" << std::endl;

   std::cout << "1. Rent Motorbikes" << std::endl; //view bike to rent
   std::cout << "2. Add motorbike" << std::endl;   // addbike to member
   std::cout << "3. View Request" << std::endl; //view upcoming requests
   std::cout << "4. View History" << std::endl; //view history of bike or member
   std::cout << "5. Logout" << std::endl;
   loadMembers();
   loadBikes();
   loadAdmin();
   current_member->loadRequest();   //load all reueqst belong to member
   choice = menuChoice(1,5);
   switch (choice) {
   case 1: //rent bike
      rentMenu();
      // memberMenu();
      break;
   case 2:  
      addBike();  //add new bike to vector
      // memberMenu();
      break;
   case 3://view request
      current_member->loadRequest();   //load all reueqst belong to member
      current_member->viewRequest();
      memberMenu();
      break;
   case 4:
      viewHistory();
      memberMenu();
      break;
   case 5: 
      //save all info and logout
      // saveBikeRatingtoFile();
      // saveMemberRatingtoFile();
      saveMembertoFile();
      saveBiketoFile();

      break;
   }
}
void System::adminMenu(){  //after admin login successful
   std::cout << "===========================================" << std::endl;
   std::cout << "|                -Admin Menu-             |" << std::endl;
   std::cout << "===========================================" << std::endl;

   std::cout << "1. View all members" <<std::endl; 
   std::cout << "2. View all motorbikes" <<std::endl;
   std::cout << "3. Logout" << std::endl;
   loadMembers();
   loadBikes();
   // loadAdmin();
   int choice = menuChoice(1,3);
   switch (choice) {
   case 1:
      adminViewMembers();   
      break;
   case 2:
      adminViewBike();
      break;
   case 3:
      saveBiketoFile();
      saveMembertoFile();
      break;
   }
}

// void System::listBike(){
//    for (int i = 0; i < motorBikesVector.size(); i++) {
//       if (motorBikesVector[i]->bikeID == current_member->bikeID){
//          motorBikesVector[i]->status = "Available";
//       } 
//    }   
// }
// void System:: unlistBike(){
//    for (int i = 0; i < motorBikesVector.size(); i++) {
//       if (motorBikesVector[i]->bikeID == current_member->bikeID){
//          motorBikesVector[i]->status = "Unavailable";
//       } 
//    }
// }
void System::loadBikes(){
   motorBikesVector.clear();
   std::ifstream bikeFile{BIKE_FILE};

   // bikeFile.open(BIKE_FILE, std::ios::in);
   if (!bikeFile.is_open()) {
      std::cerr << "Couldn't open 'Bike.txt' " << std::endl;
   }
   std::string dataLine;

   while(std::getline(bikeFile,dataLine)) {
      std::vector<std::string> dataList;
      dataList = splitString (dataLine,'|');
      MotorBike *bike = new MotorBike(dataList[0],dataList[1], dataList[2], std::stoi(dataList[3]),
                                      std::stoi(dataList[4]), dataList[5], std::stoi(dataList[6]),
                                      dataList[7], std::stof(dataList[8]), std::stof(dataList[9]),
                                      dataList[10], dataList[11], dataList[12]);
      motorBikesVector.push_back(bike);
   }
   bikeFile.close();
   std::cout << "Bike file loaded" << std::endl;
}
void System::loadMembers(){
   memberVector.clear();
   std::string line;
   
   std::ifstream memberFile{MEMBER_FILE}; 
   if(!memberFile.is_open()){
      std::cerr << "Couldn't open 'Member.txt'" << std::endl;
   }
   while (std::getline(memberFile, line)){      
      std::vector<std::string> dataList;
      dataList = splitString (line, '|');

      Member *member = new Member(dataList[0], dataList[1], dataList[2],
                                  dataList[3], dataList[4], dataList[5],
                                  dataList[6], dataList[7], std::stoi(dataList[8]),
                                  dataList[9], dataList[10], std::stof(dataList[11]),
                                  dataList[12]); // add attributes
      memberVector.push_back(member);
   }
   memberFile.close();  
   std::cout << "Member file loaded" << std::endl;
}
void System::loadAdmin(){
   std::ifstream adminFile{ADMIN_FILE};
   if (!adminFile) {
      std::cerr << "Cant open file Admin" << std::endl;
   }
   std::string line;
   getline(adminFile,line);
   
   std:: vector <std::string> dataList = splitString(line,'|');
   
   std::string username = dataList[0];
   std::string password = dataList[1];
   // std::cout << username << " " << password<< std::endl;
   
   this->admin = new Admin(username, password);
   // std::cout << this->admin. << std::endl;
   adminFile.close();
}

void System::adminViewMembers(){
   int index = 1;
   // loadMembers();
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
   std::cout << std::endl;
   std::cout << "1. View member details" << std::endl;
   std::cout << "2. Back to admin menu" << std::endl;
   int choice = menuChoice(1,2);
   switch (choice){
      case 1:
         index = 1;
         std::cout << std::left << std::setw(10) << "-Index- "
                   << std::left << std::setw(15) << "-Member_ID-"
                   << std::left << std::setw(15) << "-Username-"
                   << std::left << std::setw(15) << "-Password-"
                   << std::left << std::setw(15) << "-Full Name-"
                   << std::left << std::setw(15) << "-Phone Number-"
                   << std::left << std::setw(15) << "-ID_Type-"
                   << std::left << std::setw(15) << "-ID_Number-"
                   << std::left << std::setw(15) << "-Credits-"
                   << std::left << std::setw(15) << "-Rating-" << std::endl;
         for (auto mem : memberVector) {
         std::cout << std::left << std::setw(10) << index
                   << std::left << std::setw(15) << mem->memberID
                   << std::left << std::setw(15) << mem->username
                   << std::left << std::setw(15) << mem->password
                   << std::left << std::setw(15) << mem->fullName
                   << std::left << std::setw(15) << mem->phoneNumber
                   << std::left << std::setw(15) << mem->id_type
                   << std::left << std::setw(15) << mem->IDNum
                   << std::left << std::setw(15) << mem->credits
                   << std::left << std::setw(15) << mem->memberRating << std::endl;
         index++;
         }
         std::cout << "Total members: " << memberVector.size()<< std::endl;
         std::cout << "Return to admin menu "<< std::endl;
         adminMenu();
      break;
      case 2:
         adminMenu();
         break;
   }
}
void System::adminViewBike(){
   int index = 1;
   loadBikes();  
   std::cout << "Motorbikes in the System" <<std::endl;
   std::cout << std::left << std::setw(10) << "-Index- "
             << std::left << std::setw(15) << "-Bike_ID-" 
             << std::left << std::setw(15) << "-Model-"
             << std::endl;
   for (auto bike : motorBikesVector) {
      std::cout << std::left << std::setw(12) << index
                << std::left << std::setw(13) << bike->bikeID
                << std::left << std::setw(15) << bike->model << std::endl;
      index++;
   }
   std::cout << std::endl;
   std::cout << "1. View motorbikes detail"  << std::endl;
   std::cout << "2. Back to admin menu" << std::endl;
   int choice = menuChoice(1,2);
   switch (choice){
      case 1:
         index = 1;
         std::cout << std::left << std::setw(10) << "-Index- "
                   << std::left << std::setw(15) << "-Bike ID-"
                   << std::left << std::setw(15) << "-Model-"
                   << std::left << std::setw(15) << "-Color-"
                   << std::left << std::setw(15) << "-Year Made-"
                   << std::left << std::setw(15) << "-Mode-"
                   << std::left << std::setw(15) << "-Location-"
                   << std::left << std::setw(15) << "-Credits-"
                   << std::left << std::setw(15) << "-Bike Rating-"
                   << std::left << std::setw(15) << "-Member Rating-"
                   << std::left << std::setw(25) << "-Descripton-"
                   << std::endl;
         for(auto bike: motorBikesVector){
            std::cout << std::left << std::setw(10) << index
                   << std::left << std::setw(15) << bike->bikeID
                   << std::left << std::setw(15) << bike->model
                   << std::left << std::setw(20) << bike->color
                   << std::left << std::setw(15) << bike->yearMade
                   << std::left << std::setw(15) << bike->mode
                   << std::left << std::setw(15) << bike->location
                   << std::left << std::setw(15) << bike->rentPrice
                   << std::left << std::setw(15) << bike->bikeRating
                   << std::left << std::setw(15) << bike->memberRating
                   << std::left << std::setw(25) << bike->description
                   << std::endl;
            index++;
         }
         std::cout << "Total Motorbikes: " << motorBikesVector.size() << std::endl;
         std::cout << "Return to admin menu "<< std::endl;
         adminMenu();
         break;
      case 2:
         adminMenu();
         break;
   }

}

int System::menuChoice(int start, int end) { 
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
int System::menuChoice2(int start, int end,std::vector<int> vect) { 
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
         if (finalChoice > end || finalChoice < start) {
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

void System::guestViewBike(){
   int index = 1;
   // loadBikes();  
   std::cout << "Motorbikes in the System" <<std::endl;
   std::cout << std::left << std::setw(10) << "-Index- "
             << std::left << std::setw(15) << "-Model-"
             << std::left << std::setw(15) << "-Color-"
             << std::left << std::setw(20) << "-Engine Size-"
             << std::left << std::setw(15) << "-Year Made-"
             << std::left << std::setw(15) << "-Mode-"
             << std::left << std::setw(15) << "-Location-"
             << std::left << std::setw(15) << "-Rent Price-"
             << std::endl;
   for (auto bike : motorBikesVector) {
      std::cout << std::left << std::setw(10) << index
                << std::left << std::setw(15) << bike->model
                << std::left << std::setw(15) << bike->color
                << std::left << std::setw(20) << bike->engineSize
                << std::left << std::setw(15) << bike->yearMade
                << std::left << std::setw(15) << bike->mode
                << std::left << std::setw(15) << bike->location
                << std::left << std::setw(15) << bike->rentPrice
                << std::endl;
      index++;
   }
   int choice;
   std::cout << "Continue" << std::endl;
   std::cout << "1. Return to Guest Menu" << std::endl;
   std::cout << "2. Exit the Program" << std::endl;
   choice = menuChoice(1,2);
   switch (choice) {
   case 1:
      guestMenu();
      break;
   case 2:   
      break;
   }
}
void System::guestRegister(){
   int subChoice, choice;
   std::string username, password, fullname, phoneNum, ID, ID_type;
   std::string licenseID, expDate,location;
   std::cout << "=====================================================" << std::endl;
   std::cout << "|                -Member Registration-              |" << std::endl;
   std::cout << "=====================================================" << std::endl;

   std::cin.ignore();
   do {
      std::cout << "Format: min length 6, no whitespace\n";
      std::cout <<"Enter username: ";  //username
      std::getline(std::cin, username);
      std::cout << "-------------------------------------\n";
   } while (!isUsername(username));

   do {
      std::cout << "Format: at least 1 uppercase, 1 number, 1 special characters, "<<std::endl; //
      std::cout << "Enter password: "; //password
      std::getline(std::cin, password);
      std::cout << "-------------------------------------\n";
   } while (!isPassword(password));

   do{
      std::cout << "Enter first and last name: "; // fullname
      std::getline(std::cin, fullname);
      std::cout << "-------------------------------------\n";
   } while (!isFullname(fullname));

   do {
      std::cout <<"Format: 10 numbers, stat with 0\n";
      std::cout <<"Enter phone number: "; //phone number
      std::getline(std::cin, phoneNum);  
      std::cout << "-------------------------------------\n";
   } while (!isPhoneNum(phoneNum));
   
   std::cout  << "Choose your location:\n1. Hanoi\n2. Saigon\n3. Danang\n";
   subChoice = menuChoice(1,3);
   switch (subChoice) {
   case 1:
      location = LOCATIONS[0];
      std::cin.ignore();
      break;
   case 2:
      location = LOCATIONS[1];
      std::cin.ignore();
      break;
   case 3:
      location = LOCATIONS[2];
      std::cin.ignore();
      break;    
   }
   
   std::cout << "Choose your ID type: "<<std::endl;
   std::cout <<"1. CITIZEN_ID\n2. PASSPORT\n"; //ID types
   choice = menuChoice(1,2);
   std::cout << "-------------------------------------\n";
   switch(choice){
      case 1:
         ID_type = "CITIZEN_ID";
         std::cin.ignore();
         do{
            std::cout << "Format: 10 numbers" <<std::endl;
            std::cout << "Enter your Citizen ID: ";
            std::getline(std::cin,ID);
            std::cout << "-------------------------------------\n";
         } while (!isIDValid(ID, 1));
         break;
      case 2:
         ID_type = "PASSPORT";
         std::cin.ignore();
         do {
            std::cout << "Format: 8 numbers"<<std::endl;
            std::cout << "Enter your Passport ID: ";
            std::getline(std::cin,ID);
            std::cout << "-------------------------------------\n";

         } while (!isIDValid(ID,2));
         break;
   }
   
   do {
      std::cout << "Format: 12 numbers" << std::endl;
      std::cout << "Enter Driver License number: "; // liscense number
      std::getline(std::cin, licenseID);
      std::cout << "-------------------------------------\n";
   } while (!isLicence(licenseID));
   
   do {
      std::cout <<"Enter liscense expiration date (DD/MM/YYYY): "; //liscense date
      std::getline(std::cin, expDate);
      std::cout << "-------------------------------------\n";
   } while (!isDateFormat(expDate));
   std::string bikeID = "null";
   std::string memID = memberIDgenerate();
   Member *newMember = new Member(username, password, memID,
                                  fullname, phoneNum, location,
                                  ID_type, ID, INITIAL_CREDIT,
                                  licenseID, expDate, INITIAL_RATING,bikeID);
   memberVector.push_back(newMember);
   saveMembertoFile();  
   std::cout << "=====================================================" << std::endl;
   std::cout << "|            Member registered successfully         |" << std::endl;
   std::cout << "=====================================================" << std::endl;

   std::cout << "1. Back to Guest Menu" << std::endl;
   std::cout << "2. Exit the program" << std::endl;
   int choice2 = menuChoice(1,2);
   switch (choice2) {
   case 1:
      guestMenu();
      break;
   case 2:
      saveMembertoFile();  
      break;
   }
}

bool System::numValid(std::string input){
   if (std::stoi(input) > 57 || std::stoi(input) < 48) {
      return false;
   } else {
      return true;
   }
}
bool System::isPhoneNum(std::string s) { // first 0, 10 char, all num
   if (s.length() != 10)
      return false;
   if (s[0] != '0')
      return false;
   for (int i = 0; i < s.length(); i++) {
      if (s[i] < '0' || s[i] > '9')
         return false;
   }
   return true;
}
bool System::isPassword(std::string s){    // min length 8 char, no space
   //min length of 8 - 15, one uppercase, one number, one special character
   std::regex reg ("^(?=.*[a-z])(?=.*[A-Z])(?=.*[0-9])(?=.*[@$!%*?&])[A-Za-z0-9@$!%*?&]{8,15}$");
   s = stringCut(s);
   if (std::regex_match(s, reg)){
      return true;
   } else {
      return false;
   }
}
bool System::isUsername(std::string s){  //no symbol, white space, min length 6
    if(s.length() < 6) return false;   //min length > 6
    // no symbol and space
    for (int i = 0; i < s.length(); i++){ //mp whitespace
        if (s[i] == ' ') return false;
        if(s[i] >32 && s[i] < 48) return false;
    }
    return true;
}
bool System::isFullname(std::string s){  //no symbol, number,
   std::regex reg ("^[a-zA-Z ]+$"); //only allow letter uppercase and lowercase
   s = stringCut(s);
   if (!std::regex_match(s, reg)){ return false; } 
   return true;    
}
bool System::isDateFormat(std::string s){ //dd/mm/yyyy
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
bool System::isLicence(std::string s){ //
   if(s.length() != 12) return false;  //minlength is 12
   std::regex reg ("^[0-9 ]+$"); //only allow number
   s = stringCut(s);
   if (!regex_match(s,reg)){
      return false;
   } else {
      return true;
   }
}
bool System::isIDValid(std::string s, int num){
   std::regex reg ("^[0-9 ]+$"); //only allow number
   std::string str;
   str = stringCut(s);
   if (num == 1){
      if(s.length() != 10) return false;
      if(!regex_match(str,reg))return false;
   } else if(num == 2){
      if(s.length() != 8) return false;
      if(!regex_match(str,reg))return false;
   }
   return true;
}

void System::saveMembertoFile(){
      std::ofstream memberFile{MEMBER_FILE};
      if (!memberFile){
         std::cerr << "Couldn't open file " << std::endl;
         return;
      }
      for(auto& member : memberVector){
         memberFile << member->username << "|"
                    << member->password << "|"
                    << member->memberID << "|"
                    << member->fullName << "|"
                    << member->phoneNumber << "|"
                    << member->memLocation << "|"
                    << member->id_type << "|"
                    << member->IDNum << "|"
                    << member->credits << "|"
                    << member->licenseID << "|"
                    << member->expDate << "|"
                    << member->memberRating;
         if (current_member != nullptr){
            if (member->memberID == current_member->memberID){
               if (current_member->own_bike == true){
                  memberFile << "|" << current_member->bikeID;
               }
            }
            else {
               memberFile << "|" << member->bikeID;
            }
         }
         else {
            memberFile << "|" << member->bikeID;
         }
         memberFile << "\n";
   }
   memberFile.close();
   std::cout << "Member file saved successfully!" << std::endl;

}
void System::saveBiketoFile(){
   std::ofstream bikeFile{BIKE_FILE};
   if (!bikeFile) {
         std::cerr << "Couldn't open file " << BIKE_FILE << std::endl;
         return;
   }
   // for(auto& bike: motorBikesVector){
   for (int i = 0; i < motorBikesVector.size(); i++) {
      bikeFile << motorBikesVector[i]->bikeID << "|"
               << motorBikesVector[i]->model << "|"
               << motorBikesVector[i]->color << "|"
               << motorBikesVector[i]->engineSize << "|"
               << motorBikesVector[i]->yearMade << "|"
               << motorBikesVector[i]->mode << "|"
               << motorBikesVector[i]->rentPrice << "|"
               << motorBikesVector[i]->location << "|"
               << motorBikesVector[i]->bikeRating << "|"
               << motorBikesVector[i]->memberRating << "|"
               << motorBikesVector[i]->description << "|"
               << motorBikesVector[i]->status << "|"
               << motorBikesVector[i]->rentDuration
               << "\n";
   }
   bikeFile.close();
   std::cout << "Motobike file saved successfully!" << std::endl; 
}
/*void System::loadBikeRatings(){
   std::string line;
   std::ifstream file{BIKE_RATING_FILE};
   if(!file){
      std::cerr << "Couldn't open file " << std::endl;
   }
   while (std::getline(file, line)){      
      std::vector<std::string> dataList;
      dataList = splitString (line, '|');
      BikeRating *newBkRating = new BikeRating(std::stoi(dataList[2]),
                                               dataList[3]);
      bikeRatingVector.push_back(newBkRating);
   }
   file.close();  
}*/
/*void System::loadMemberRatings(){
   std::string line;
   std::ifstream file{MEMBER_RATING_FILE};
   if(!file){
      std::cerr << "Couldn't open file " << std::endl;
   }
   while (std::getline(file, line)){      
      std::vector<std::string> dataList;
      dataList = splitString (line, '|');
      // RenterRating *newRtRating = new RenterRating(dataList[0], dataList[1],
      //                                              std::stoi(dataList[2]), dataList[3]);
      // renterRatingVector.push_back(newRtRating);
   }
   file.close(); 
}*/


void System::loadRequest(){    
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
                                     dataList[3], dataList[4], 
                                     dataList[5]); // add attributes
   requestVector.push_back(request);    
   }   
   requestFile.close();   
}


void System::saveBikeRatingtoFile(){
   std::ofstream file{BIKE_RATING_FILE};
   if(!file){
      std::cerr <<"Couldnt open file " << std::endl;
   }
   for (int i = 0; i < bikeRatingVector.size(); i++) {
      file << bikeRatingVector[i]->ratebikeID << "|"
           << bikeRatingVector[i]->score << "|"
           << bikeRatingVector[i]->comment << "|"
           << "\n";
   }
   file.close();
}
void System::saveMemberRatingtoFile(){
   std::ofstream file{MEMBER_RATING_FILE};
   if(!file){
      std::cerr <<"Couldnt open file " << std::endl;
   }
   for (int i = 0; i < renterRatingVector.size(); i++) {
      file << renterRatingVector[i]->renterid << "|"
           << renterRatingVector[i]->ownerid << "|"
           << renterRatingVector[i]->score << "|"
           << renterRatingVector[i]->comment << "|"
           << "\n";
   }
   file.close();
}

void System::rentMenu(){
   int index = 0;
   int order= 0;
   std::vector<int>track;
   int choice,choice2;
   std::cout << "Motorbikes available" <<std::endl;
   std::cout << std::left << std::setw(10) << "-Index- "
             << std::left << std::setw(15) << "-Model-"
             << std::left << std::setw(15) << "-Color-"
             << std::left << std::setw(20) << "-Engine Size-"
             << std::left << std::setw(15) << "-Year Made-"
             << std::left << std::setw(15) << "-Mode-"
             << std::left << std::setw(15) << "-Location-"
             << std::left << std::setw(15) << "-Rent Price-"
             << std::endl;
   for (auto bike : motorBikesVector) {
      if ((bike->location == current_member->memLocation)        // fit location
          && (bike->memberRating < current_member->memberRating) // above min rating
          && (bike->bikeID != current_member->bikeID)) { // not list current member bike
            std::cout << std::left << std::setw(10) << order
                      << std::left << std::setw(15) << bike->model
                      << std::left << std::setw(15) << bike->color
                      << std::left << std::setw(20) << bike->engineSize
                      << std::left << std::setw(15) << bike->yearMade
                      << std::left << std::setw(15) << bike->mode
                      << std::left << std::setw(15) << bike->location
                      << std::left << std::setw(15) << bike->rentPrice
                      << std::endl;
      order++; //for show only
      track.push_back(index); //remember which bike at which index is show on list
      }
      index++;
   }

   std::cout << "Menu:  " << std::endl;
   std::cout << "1. Select bike to rent " << std::endl;
   std::cout << "2. Back to Member menu " << std::endl;
   choice = menuChoice(1,2);
   switch (choice) {
   case 1:
      // std::cin.ignore();
      choice2 = menuChoice2(0,order,track);
      for (MotorBike *bk : motorBikesVector){
         if (bk->bikeID == motorBikesVector[choice2]->bikeID){
            std::cin.ignore();
            std::cout << "bike ID = "<< bk->bikeID << std::endl;
            std::cout << "rent price = "<< bk->rentPrice << std::endl;
            current_member->sendRequest(bk->bikeID, bk->rentPrice);
            current_member->saveRequesttoFile();
            
            for (int i = 0; i < memberVector.size(); i++) {
               if(current_member->memberID == memberVector[i]->memberID){
                  memberVector[i] = current_member;   //update to vector
               }
            }
            saveMembertoFile();  //update to file
         }
      }
      break;
   case 2:
      memberMenu();
      break;
   }
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
std::string stringCut(std::string s){
   std::string result;
   for (char c :s){
      if (c == ' '){
         continue;
      } else{
         result += c;
      }
   }
   return result;
}
void System::addBike(){
   std::string model, color, engineSize, year,
               mode, price = "0", location, mem_rate = "0",
               description, status = "", duration = "0";
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
   std::cout <<"1. Hanoi\n2. HoChiMinh\n3. Danang\n";
   int choice2 = menuChoice(1,3);
   switch (choice2) {
      case 1:
         location = "Hanoi";
         break;
      case 2:
         location = "HoChiMinh";
         break;
      case 3:
         location = "DaNang";
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
   
   std::string c = current_member->listBike();
   
   if (c == "Y" || c == "y"){status = "Available";}
   else if (c == "N" ||c == "n"){status = "Unavailable";}

   std::string newbikeID = bikeIDgenerate();
   
   current_member->bikeID = newbikeID;
   current_member->own_bike = true;
   // std::cout << "bike ID" << current_member->bikeID << std::endl;
   MotorBike *bike = new MotorBike(newbikeID, model, color, std::stoi(engineSize),
                                 std::stoi(year), mode, std::stoi(price),
                                 location, INITAIL_BIKE_RATING, std::stof(mem_rate),
                                 description, status, duration);
   
   motorBikesVector.push_back(bike);
   saveBiketoFile();
   std::cout << "=====================================================" << std::endl;
   std::cout << "|            Motorbike Added Successfully           |" << std::endl;
   std::cout << "=====================================================" << std::endl;
   
   std::cout << "1. Back to Member Menu" << std::endl;
   std::cout << "2. Exit the program" << std::endl;
   int choice3 = menuChoice(1,2);
   switch (choice3) {
   case 1:
      memberMenu();
      break;
   case 2:
      saveBiketoFile();
      saveMembertoFile(); 
      break;
   }
}

bool System::isYear(std::string s){
   std::regex reg ("^[0-9 ]+$"); //only allow number
   std::string str;
   str = stringCut(s);
   if(!regex_match(str,reg)){return false;}  //only num
   if (s.length() != 4) {return false;}   //length of 4
   return true;
}
bool System::isBikeModel(std::string s){ 
   std::regex reg ("^[a-zA-Z0-9 ]+$"); //only char and num
   s = stringCut(s);
   if (!std::regex_match(s, reg)){ return false; }
   return true;
}
bool System::isBikecolor(std::string s){
   std::regex reg ("^[a-zA-Z ]+$"); //only characters
   std::string str;
   str = stringCut(s);
   if(!regex_match(str,reg)){return false;}    
   
   return true;
}
bool System::isBikeEngineSize(std::string s){   //only num, >0
   std::regex reg ("^[0-9 ]+$"); //only allow number
   std::string str;
   str = stringCut(s);
   if(!regex_match(str,reg)){return false;}  //only num
   if (std::stoi(s) <= 0) {return false;}
   for (int i = 0; i < s.length(); i++) {
      if (s[i] == ' ') {return false;}  //no whitespace
   }
   
   return true;
}
bool System::isMinRating(std::string s){  //only num, 1-10
   std::regex reg ("^[0-9. ]+$"); //only allow number
   std::string str;
   str = stringCut(s);
   if(!regex_match(str,reg)){return false;}  //only num
   if (std::stof(s) < 0 || std::stof(s) > 10){ return false; } //1-10
   for (int i = 0; i < s.length(); i++) {
      if (s[i] == ' ') {return false;}  //no whitespace
   }
   return true;
}
bool System::isRentPrice(std::string s){  //only num, no space 
   std::regex reg ("^[0-9 ]+$"); //only allow number
   std::string str;
   str = stringCut(s);
   if(!regex_match(str,reg)){return false;}  //only num
   for (int i = 0; i < s.length(); i++) {
      if (s[i] == ' ') {return false;}  //no whitespace
   }
   return true;
}
bool System::ischar(std::string s){
   std::regex reg ("^[ynYN ]+$"); //only char and num
   std::string str;
   str = stringCut(s);
   if (!std::regex_match(s, reg)){ return false; }
   
   return true;
   
}


void System::rentBike(){
   // std::string requestID, renterID, startdate, returndate, status="", bikeID;
   // requestID = requestIDgenerate();

   // renterID = current_member->memberID;
   // bikeID = current_member->bikeID;
   // do {
   //    do {
   //       std::cout << "Enter start day to rent: ";
   //       std::getline(std::cin, startdate);
   //    } while (!isDateFormat(startdate));
   //    do {
   //       std::cout << "Enter day of return : ";
   //       std::getline(std::cin, returndate);
   //    } while (!isDateFormat(returndate));
   // } while(!isDateGood(startdate,returndate));

   // Request *rqst = new Request(requestID, renterID,
   //                             returndate, startdate,
   //                             bikeID, status);
   // requestVector.push_back(rqst);
}

void System::viewHistory(){ //view who rent the bike before
   std::cout << "Choose:"<< std::endl;
   std::cout << "1. History of own bike" << std::endl;
   std::cout << "2. History of members" << std::endl;
   int choice = menuChoice(1,2);
   switch (choice){
      case 1:
         current_member->viewBikeHistory();
         break;
      case 2:
         current_member->viewMemberHistory();
         break;
   }
}


// bool isDateGood(std::string start,std::string end){
//    std::string sdate = start.substr(0,2);
//    std::string smonth = start.substr(3,2);
//    std::string syear = start.substr(6,4);
   
//    std::string edate = end.substr(0,2);
//    std::string emonth = end.substr(3,2);
//    std::string eyear = end.substr(6,4);
//    if ((std::stoi(eyear) - std::stoi(syear)) < 0) { return false; }
//    if ((std::stoi(emonth) - std::stoi(smonth)) < 0) { return false; }
//    if ((std::stoi(edate) - std::stoi(sdate)) < 0) { return false; }
//    return true;

// }
