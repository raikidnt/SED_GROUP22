#ifndef BIKE_RATING_H
#define BIKE_RATING_H
#include <bits/stdc++.h>
#include "../Bike/MotorBike.h"
#include "../User/Member.h"

class BikeRating {
   protected:
      std::string rateBikeID; //auto generated
      std::string comment;
      int score;
   public:
      BikeRating();
      BikeRating(int score, std::string comment);

      void RateBike();
      void setRateBikeID(std::string rateBikeID);
      void setScore(int score);
      void setComment(std::string comment);

      friend std::string BikeRatingIDgenerate();
};


#endif