#ifndef RENT_HISTORY_H
#define RENT_HISTORY_H
#include <bits/stdc++.h>
#include <../Request/Request.h>


class RentHis : public Request{

    private:

        double price;
        std::string historyID;
        std::string bikeID;
        std::string renter_id;
        Request::returnDate;
        Request::startDate;

    public:

        RentHis::RentHis();
        RentHis::RentHis(double price, std::string historyID, std::string bikeID, std::string renter_id) : price(price), historyID(historyID), bikeID(bikeID), renter_id(renter_id){};


        void setPrice(double price);
        void totalPrice(Request& total);
        friend int getDiff(std::string start_date, std::string return_date);
        friend class Request;
};




















#endif