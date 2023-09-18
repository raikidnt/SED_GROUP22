#ifndef MOTORBIKE_H
#define MOTORBIKE_H
#include <bits/stdc++.h>


class MotorBike {
   protected: 
      std::string bikeID;  //specification of a bike 
      std::vector <std::string> feedBacks;
      float bikeRating;

   public:
      std::string model;
      std::string color;

      int engineSize; // size of engine (unit cc)
      int yearMade;
      
      int rentPrice;   //perday rent fee
      std::string mode;
      std::string location;
      std::string status;
      
      std::string description;
      float memberRating;
      std::string rentDuration;
      
      MotorBike();   //default constructor
      MotorBike(std::string i_model, std::string i_color, int i_engineSize, std::string i_mode, int i_year, std::string i_location);

      MotorBike(std::string i_model, std::string i_color, int i_engineSize,
                int i_year, std::string i_mode, int i_rentPrice, 
                std::string i_location, float i_bikeRating, float i_memberRating, 
                std::string i_description, std::string i_status, std::string i_rentPeriod);

      void showBikeInfo();
         
      friend std::string bikeIDgenerate();   //generate random id for bike
      friend class Request;
      friend class Admin;
      friend class Member;
      friend class BikeRating;
}; 
#endif   // BIKE_H