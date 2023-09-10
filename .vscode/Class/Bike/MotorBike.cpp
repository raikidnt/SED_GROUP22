#include "MotorBike.h"
#include <bits/stdc++.h>

MotorBike::MotorBike(){}
MotorBike::MotorBike(std::string i_model, std::string i_color, int i_engineSize, int i_year, int cost)
    : model(i_model), color(i_color), engineSize(i_engineSize), yearMade(i_year), creditCost(cost) {}

void MotorBike::showBikeInfo(std::string i_bikeID){
   std::cout << "Model: " << model << std::endl;
   std::cout << "Color: " << color << std::endl;
   std::cout << "Engine Size: " << engineSize << std::endl;
   std::cout << "Year Made: " << yearMade << std::endl;
   std::cout << "Credit Cost: " << creditCost << std::endl;
   
   if (mode == 1) {
      std::cout << "Mode: Automation" << std::endl;
   } else if (mode == 2) {
      std::cout << "Mode: Manual" << std::endl;
   } else if (mode == 0) {
      std::cout << "Mode: Unknown" << std::endl;
   }
   std::cout << "Description: " << description << std::endl;
   
   if (location == 1) {
      std::cout << "Location: Saigon " << std::endl;
   } else if (location == 2) {
      std::cout << "Location: Hanoi" << std::endl;
   } else {
      std::cout << "Location: Unknown" << std::endl;
   }
}

