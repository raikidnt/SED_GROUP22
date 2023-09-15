#include "MotorBike.h"

std::string bikeIDgenerate(){
   // srand(time(NULL));
   int num = rand() % 1001; //random number form 0-100
   return ("Bk-"+std::to_string(num));
}

MotorBike::MotorBike(){}
MotorBike::MotorBike(std::string i_model, std::string i_color, int i_engineSize, MODE i_mode, int i_year, LOCATION i_location)
:model(i_model), color (i_color),engineSize(i_engineSize), mode(i_mode), yearMade(i_year), location (i_location){};

MotorBike::MotorBike(std::string i_model, std::string i_color, int i_engineSize,
          MODE i_mode, int i_year, std::string i_description, /*int i_rating,*/
          LOCATION i_location, STATUS i_status, /*int i_initalPrice,*/ int i_pdPrice,
          float i_minRating, std::string i_rentDuration)
          :model(i_model), color(i_color), engineSize(i_engineSize), mode(i_mode), 
          yearMade(i_year),description(i_description),location(i_location), status(i_status),
          /*initialPrice(i_initalPrice),*/ pdPrice(i_pdPrice), minRating(i_location), rentDuration(i_rentDuration) {
            bikeID = bikeIDgenerate(); 
          };

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
   std::cout << "- Rating: " << "\tCredit Cost: " << pdPrice << std::endl;
   std::cout << "- Description: " << description << std::endl;
}
