#include "UI.h"
#include <iostream>
void welcome (){
   std::cout << "====== EEET2482/COSC2082 ASSIGNMENT ======" << "\n";
   std::cout << "====== MOTORBIKE RENTAL APPLICATION ======" << "\n";

   std::cout << "Instructor: Dr. Ling Huo Chong" << "\n";
   std::cout << "Group: 22" << std::endl;

   std::cout << "\ts3818247,\t Nhat Nguyen" << "\n";
   std::cout << "\ts3977947,\t Thanh Do" << "\n";
   std::cout << "\ts3979896,\t Huan Nguyen" << "\n";
   std::cout << "\ts3938194,\t Quan Ngo" << "\n";
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
