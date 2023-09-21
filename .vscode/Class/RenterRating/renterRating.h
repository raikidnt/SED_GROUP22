#ifndef RENTER_RATING_H
#define RENTER_RATING_H

#include <bits/stdc++.h>
// #include <../RenterRating/renterRating.cpp>
// #include <../User/Member.h>


class RenterRating{
   protected:
      std::string renterid;  
      std::string ownerid;
      std::string comment;
      int score;
   public:  
      RenterRating();
      RenterRating(std::string renterid, std::string ownerid,
                                 int score, std::string comment);

      // void RateRenter::setscore(int score);
      // void RateRenter::rateRenter();
      // void RateRenter::setcomment(std::string comment);

      friend class Member;
      friend class System;
};


#endif