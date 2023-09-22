#ifndef RENT_HISTORY_H
#define RENT_HISTORY_H
#include <bits/stdc++.h>

class RentHis {
    private:
        int price;

        std::string historyID;
        std::string bikeID;

        std::string renter_id;
        std::string owner_id;
        
        std::string status; //Renting/Finished

        std::string bikeComment;
        std::string memberComment;
        float bikeRating;
        float memberRating;
    public:
        RentHis();
        RentHis(std::string i_historyID, int i_price, std::string i_bikeID,
                std::string i_renter_id, std::string i_owner,
                std::string i_status
                // std::string i_bikeComment, float i_bikeRating,
                // std::string i_memberComment, float i_memberRating
                );
        friend class Request;
        friend class Member;
};

#endif