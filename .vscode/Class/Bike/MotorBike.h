#ifndef MOTORBIKE_H
#define MOTORBIKE_H
#include <bits/stdc++.h>
enum MODE {unknown, automation, manual};
enum LOCATION{SG = 1, HN = 2};
enum STATUS {UNAVAILABLE, AVALABLE};
class MotorBike {
   private: 
      std::string bikeID;  //specification of a bike 
      std::vector <std::string> feedBacks;
      std::vector<float> AvgBikeRating;

   public:
      std::string model;
      std::string color;

      int engineSize; // size of engine (unit cc)
      int yearMade;
      
      // int initialPrice; //inital rent fee
      int pdPrice;   //perday rent fee
      
      MODE mode;  //transmission mode
      LOCATION location;   //available location
      STATUS status; //available/unavailable status
      
      std::string description;
      float minRating;
      std::string rentDuration;
      
      MotorBike();   //default constructor
      MotorBike(std::string i_model, std::string i_color, int i_engineSize, MODE i_mode, int i_year, LOCATION i_location);
      MotorBike(std::string i_model, std::string i_color, int i_engineSize,
                  MODE i_mode, int i_year, std::string i_description, /*int i_rating,*/ 
                  LOCATION i_location, STATUS i_status, /*int i_initalPrice,*/ int i_pdPrice, 
                  float i_minRating, std::string i_rentPeriod);
      
      void showBikeInfo();
         
      friend std::string bikeIDgenerate();   //generate random id for bike
      
      friend class Admin;
      friend class Member;
}; 
#endif   // BIKE_H