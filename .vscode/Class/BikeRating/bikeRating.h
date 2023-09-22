#ifndef BIKE_RATING_H
#define BIKE_RATING_H
#include <bits/stdc++.h>
std::string BikeRatingIDgenerate();

class BikeRating {
   protected:
      std::string ratebikeID; //auto generated
      std::string comment;
      int score;
   public:
      BikeRating();
      BikeRating(std::string comment, int score);

      // void RateBike();
      // void setRateBikeID(std::string rateBikeID);
      // void setScore(int score);
      // void setComment(std::string comment);
      friend class System;
};


#endif