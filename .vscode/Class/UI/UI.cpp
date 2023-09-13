#include "UI.h"
#include <iostream>
#include "../Bike/MotorBike.cpp"

void welcome (){
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

std::vector<MotorBike> initialize (std::vector <MotorBike> &motorBikes){
   std::fstream bikeFile;
   bikeFile.open("../Data/Bike.txt", ios:: in);
   if(!bikeFile){
      cerr << "couldnt open file" << std::endl;
      return;
   }
   MotorBike temp;

   std::string blank;
   while (!bikeFile.eof()){
      
      getline(bikeFile,blank,'|');  //ID
      getline(bikeFile,temp.model,'|');   //model
      getline(bikeFile,temp.color,'|');   //color
      
      getline(bikeFile,blank,'|');  //engine size
      temp.engineSize = stoi(blank);

      getline(bikeFile,blank,'|');  //yearMade
      temp.yearMade = stoi(blank);

      //transmission mode::need


      getline(bikeFile,blank,'|'); //cost
      temp.pdPrice = stoi(blank);

      // getline(bikeFile,blank,'|');  //location
      // temp.location = stoi(blank);

      //Bikerating::need

      getline(bikeFile,blank,'|');  //min mem rating
      temp.minRating = stof(blank);
      
      getline(bikeFile,temp.description,'|');   //description
      

      
      motorBikes.push_back(temp);
   }

}