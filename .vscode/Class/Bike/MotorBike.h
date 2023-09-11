#ifndef MOTORBIKE_H
#define MOTORBIKE_H
#include <bits/stdc++.h>
enum MODE {unknown, automation, manual};
enum LOCATION{SG = 1, HN = 2};
      
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
      MODE mode;
      LOCATION location;
      std::string description;
      
      MotorBike();   //default constructor
      MotorBike(std::string i_model, std::string i_color, MODE i_mode, int i_engineSize, int i_year, int cost);

      void showBikeInfo();
      
      
      friend int loadBikeInfo(std::string ID);
   
      friend std::string bikeIDgenerate();
      
      friend class Admin;
      friend class Member;
}; 
#endif   // BIKE_H