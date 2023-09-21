#include "MotorBike.h"

std::string bikeIDgenerate(){
   srand(time(NULL));
   int num = rand() % 1001; //random number form 0-100
   return ("Bk-"+std::to_string(num));
}

MotorBike::MotorBike(){}
// MotorBike::MotorBike(std::string i_model, std::string i_color,
//                      int i_engineSize, std::string i_mode,
//                      int i_year, std::string i_location)
//     : model(i_model), color(i_color),
//       engineSize(i_engineSize), mode(i_mode),
//       yearMade(i_year), location(i_location)
// {
//    bikeID = bikeIDgenerate();
// };

MotorBike::MotorBike(std::string i_bikeID, std::string i_model, std::string i_color, int i_engineSize,
          int i_year, std::string i_mode, int i_rentPrice,
          std::string i_location, float i_bikeRating, float i_memberRating,
          std::string i_description, std::string i_status, std::string i_rentPeriod)
    : bikeID(i_bikeID),model(i_model), color(i_color), engineSize(i_engineSize),
      yearMade(i_year), mode(i_mode),rentPrice(i_rentPrice),location(i_location),
      bikeRating(i_bikeRating), memberRating(i_memberRating),description(i_description),  
      status(i_status), rentDuration(i_rentPeriod)
{
   // bikeID = bikeIDgenerate();
};

void MotorBike::showBikeInfo(){
   std::cout << "- Model: " << model << "\tColor: " << color << "\tMode: " << mode <<std::endl;
   std::cout << "- Bike_ID: " << bikeID << std::endl;
   std::cout << "- Engine Size: " << engineSize << " cc"
             << "\tYear Made: " << yearMade << "\t\tLocation: " << location << std::endl;
   std::cout << "- Rating: " << "\tCredit Cost: " << rentPrice << std::endl;
   std::cout << "- Description: " << description << std::endl;
   std::cout << "================================================"<< std::endl;
}
