#include <iostream>
#include <bits/stdc++.h>
#include <../Request/Request.cpp>
#include <RentHistory.h>



RentHis::RentHis(){};
RentHis::RentHis(double price, std::string historyID, std::string bikeID, std::string renter_id) : price(price), historyID(historyID), bikeID(bikeID), renter_id(renter_id){

    this -> historyID = requestID;
    this -> renter_id = renterID;
};

void Request::setReturnDate(std::string returnDate){
    this->returnDate = returnDate;
}
void Request::setStartDate(std::string startDate){
    this->startDate = startDate;
}

void RentHis::setPrice(double price){
    this -> price = price;
}




void totalPrice(Request& total){

    RentHis* Price = new RentHis();
    std::string startdate;
    std::string returndate;

    double totalprice = total.getDiff(startdate, returndate)* 2;

    Price -> setPrice(totalprice);
}

