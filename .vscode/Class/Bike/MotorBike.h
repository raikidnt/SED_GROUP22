#ifndef MOTORBIKE_H
#define MOTORBIKE_H
#include <bits/stdc++.h>
#include ".vscode\Class\User\Admin.h"
class MotorBike {
   private: 
      std::string bikeID;  //specification of a bike 
      std::vector <std::string> feedBacks;
      std::vector<int> bikeRating;

   public:
      std::string model;
      std::string color;
      int engineSize; // size of engine (unit cc)
      int yearMade;
      int creditCost; //credit need to rent the motorbike

      enum {unknown, automation, manual} mode;
      std::string description;
      enum {SG = 1, HN = 2} location;

      MotorBike();
      MotorBike(std::string i_model,std::string i_color,int i_engineSize, int i_year, int cost);

      int loadBikeInfo();
      void showBikeInfo(std::string i_bikeID);  //show info of bike that match ID
      
      friend class Admin;
}; 
#endif   // BIKE_H