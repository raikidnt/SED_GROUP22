#include "MotorBike.h"
#include <bits/stdc++.h>
std::string bikeIDgenerate(){
   // srand(time(NULL));
   int num = rand() % 1001; //random number form 0-100
   return ("Bk-"+std::to_string(num));
}

MotorBike::MotorBike(){}
MotorBike::MotorBike(std::string i_model, std::string i_color, MODE i_mode, int i_engineSize, int i_year, int cost)
    : model(i_model), color(i_color), mode(i_mode), engineSize(i_engineSize), yearMade(i_year), creditCost(cost)
{
   bikeID = bikeIDgenerate();
}

void MotorBike::showBikeInfo(){
   std::cout << "- Model: " << model << "\tColor: " << color << "\tMode: ";
   switch(mode){
      case 0:
         std::cout << "-Unknown-" <<std::endl;
         break;
      case 1:
         std::cout << "-Automation-" <<std::endl;
         break;
      case 2:
         std::cout << "-Manual-" <<std::endl;
         break;
      default:
         std::cout << "-Invalid-" <<std::endl;
         break;
   } 
   std::cout << "- Bike ID: " << bikeID << std::endl;
   std::cout << "- Engine Size: " << engineSize << "cc"
             << "\tYear Made: " << yearMade << "\tLocation: ";
   switch (location) {
   case 1:
      std::cout << "-SG-" << std::endl;
      break;
   case 2:
      std::cout << "-HN-" << std::endl;
      break;
   default:
      std::cout << "-Invalid-" << std::endl;
      break;
   }
   std::cout << "- Rating: " << "\tCredit Cost: " << creditCost << std::endl;
   std::cout << "- Description: " << description << std::endl;
}

int loadBikeInfo(std::string ID){
   std::fstream bikeFile;
   bikeFile.open("Bike.txt", ios::out);
   if (!bikeFile.is_open()){
      cerr << "Error: Couldn't open file " << std::endl;
      return -1;
   }
   std::string temp = "";
   while (!bikeFile.eof()){
      getline(bikeFile, temp, ',');
      if (temp == ID){
         
      }
   }
}