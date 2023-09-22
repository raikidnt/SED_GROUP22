#include "RentHistory.h"

std::string historyIDgenerate(){
   srand(time(NULL));
   int num = rand() % 1001; //random number form 0-100
   return ("H-"+std::to_string(num));
}

RentHis::RentHis(){};
RentHis::RentHis(std::string i_historyID, int i_price, std::string i_bikeID,
                 std::string i_renter_id, std::string i_owner,
                 std::string i_status
                //  std::string i_bikeComment, float i_bikeRating,
                //  std::string i_memberComment, float i_memberRating
                 )
    : historyID(i_historyID), price(i_price), bikeID(i_bikeID),
      renter_id(i_renter_id), owner_id(i_owner),
      status(i_status)
    //   bikeComment(i_bikeComment), bikeRating(i_bikeRating),
    //   memberComment(i_memberComment), memberRating(i_memberRating)
{
    if (i_status  == "Renting"){    //new renting
        i_historyID = historyIDgenerate();
    }
};