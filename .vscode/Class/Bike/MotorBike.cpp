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
                     int i_year, MODE i_mode, int i_rentPrice, LOCATION i_location,
                     float i_bikeRating, float i_memberRating, std::string i_description,
                     STATUS i_status, std::string i_rentPeriod)

    : model(i_model), color(i_color), engineSize(i_engineSize),
      yearMade(i_year), mode(i_mode),rentPrice(i_rentPrice),location(i_location),
      bikeRating(i_bikeRating), memberRating(i_memberRating),description(i_description),  
      status(i_status), rentDuration(i_rentPeriod)
{
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
   std::cout << "- Rating: " << "\tCredit Cost: " << rentPrice << std::endl;
   std::cout << "- Description: " << description << std::endl;
}
