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
   std::cin >> choice;
   return choice;
}

