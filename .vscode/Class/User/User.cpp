#include "User.h"
#include <string>
User::User(){};   //default constructor

User::User (std::string n,std::string p){
   userName = n;
   password = p;
}

int User::UserLogin(std::string n, std::string p){
   if (n == userName && p == password){
      std::cout << "Login Successful!" << std::endl;
      return 0;
   }
   else {
      std::cout << "Login Failed!" << std::endl;
      return 0;
   }
}
int User::UserLogout (){
   
}
