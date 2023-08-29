#pragma once
#include <bits/stdc++.h>
// #ifdef BIKE_H
// #define BIKE_H

class Bike {
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

      enum mode{unknown = 0,automation = 1, manual = 2 } mode;
      std::string description;
      enum { SG = 1, HN = 2} location;

      Bike(){};
      Bike(std::string i_model,std::string i_color,int i_engineSize, int i_year, int cost){}

      void showInfo(){}
      void list(){}     //to list available models
      void unlist(){}   // to unlist unwanted bike
};
// #endif   // BIKE_H