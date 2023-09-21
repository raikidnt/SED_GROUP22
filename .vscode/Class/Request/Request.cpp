#include "Request.h"
// #include <bits/stdc++.h>
// #include <string>
// #include <vector>
// #include "../Bike/MotorBike.cpp"
// #include "../User/Member.cpp"
// #include "../Bike/MotorBike.h"

std::string requestIDgenerate(){
   // srand(time(NULL));
   int num = rand() % 1001; //random number form 0-1000
   return ("Rqst - " + std::to_string(num));
};

Request::Request(){};
Request::Request(std::string requestID, std::string renterID,
                 std::string returnDate, std::string startDate,
                 STATUS status, std::string bike_id, int check)
    : requestID(requestID), renterID(renterID),
      returnDate(returnDate), status(status),
      startDate(startDate), bike_id(bike_id), check(check)
{
    // renterID = IDNum; 
};

void Request::setRequestID(std::string requestID){
    this->requestID = requestID;
}
void Request::setRenterID(std::string renterID){
    this->renterID = renterID;
}
void Request::setReturnDate(std::string returnDate){
    this->returnDate = returnDate;
}
void Request::setStartDate(std::string startDate){
    this->startDate = startDate;
}
void Request::setbikeID(std::string bike_id){
    this->bike_id = bike_id;
}
void Request::updateRequest(int check){
    this->check = check;
}

std::vector<std::string> splitDate(std::string &date, char splitChar){
    std::stringstream ss(date);
    std::vector<std::string>strarray;
    std::string val;
    while(getline(ss, val, splitChar)){
        strarray.push_back(val);
    }
    return strarray;
}

bool validDate(std::string &date){
    std::vector<std::string> d = splitDate(date, '/');
    int day, month, year;
    day = std::stoi(d[0]);
    month = std::stoi(d[1]);
    year = std::stoi(d[2]);

    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 0) {
        return false;
    }
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        return false;
    }
    if (month == 2) {
        int leapYear = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
        if ((!leapYear && day > 28) || (leapYear && day > 29)) {
            return false;
        }
    }

    return true;
}

int getDiff(std::string start_date, std::string return_date){

    std::vector<std::string> split1 = splitDate(start_date, '/');
    std::vector<std::string> split2 = splitDate(return_date, '/');
    int d1, m1, y1, d2, m2, y2;

    d1 = std::stoi(split1[0]);
    m1 = std::stoi(split1[1]);
    y1 = std::stoi(split1[2]);
    d2 = std::stoi(split2[0]);
    m2 = std::stoi(split2[1]);
    y2 = std::stoi(split2[2]);

    const int Days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (m1 <= 2) {
        y1--;
    }
    int ly1 = y1 / 4 - y1 / 100 + y1 / 400;
    if (m2 <= 2) {
        y2--;
    }
    int ly2 = y2 / 4 - y2 / 100 + y2 / 400;
    long int count1 = y1 * 365 + d1;
    for (int i = 0; i < m1 - 1; i++) {
        count1 += Days[i];
    }
    count1 += ly1;
    long int count2 = y2 * 365 + d2;
    for (int i = 0; i < m2 - 1; i++) {
        count2 += Days[i];
    }
    count2 += ly2;

    int diffdays = count2 - count1;
    return diffdays;
}

void Request::sentrequest(std::string i_renterID){
    std::string Bikeid;
    MotorBike bike;
    bool check = false;
    std::cout << "- Renting request -" << std::endl;
    std::cout << "Enter the bike ID: " << std::endl; 
     do {
        getline(std::cin , Bikeid);
    } while (Bikeid.length() == 0);

    for(int i = 0; i < Bikeid.size(); i++){
        if(bike.bikeID[i] == Bikeid[i]){
            check = true;
        }
    }
    if (check == false){
        std::cout << "Unidentified bike ID." << std::endl;
    } else{
        do {
            std::cout << "Enter the begin of renting period (dd/mm/yyyy):\n";
            do {
                getline(std::cin , startDate);
            } while (startDate.length() == 0);
            if (!validDate(startDate)){
                std::cout << "Invalid form, please try again (dd/mm/yyyy)." << std::endl;
            }
        } while(!validDate(startDate));

        do {
            std::cout << "Enter the return date (dd/mm/yyyy):\n";
            do {
                getline(std::cin , returnDate);
            } while (returnDate.length() == 0);
            if(startDate == returnDate){
                std::cout << "The two dates cannot be the same, please try again." << std::endl;
            }
            else if (!validDate(startDate)){
                std::cout << "Invalid form, please try again (dd/mm/yyyy)." << std::endl;
            }
        }while(startDate == returnDate || !validDate(startDate));

    }
    if(check == true){
        Request *req = new Request();
        req->setbikeID(Bikeid);
        req->setRenterID(i_renterID);
        req->setStartDate(startDate);
        req->setReturnDate(returnDate);
        req->setRequestID(requestIDgenerate());
        req->getDiff(startDate, returnDate);
        std::cout << "Request has been sent." << std::endl;
        delete[] req;
    } 
}






    
void Request::checkRequest(){
    Request *req = new Request();
    int temp;
    std::cout << "RequestID: " << requestID << std::endl;
    std::cout << "Bike ID: " << bike_id << std::endl;
    std::cout<< "Renter ID: " << renterID << std::endl;
    std::cout << "Start Date: " << startDate << std::endl;
    std::cout<< "Return Date: " << returnDate << std::endl;
    std::cout<< std::endl;
    do {
        std::cout<< "Press 1 to accept or 0 to reject the request: ";
        std::cin >> temp;

        if(temp == 1){
           std::cout<< "You have accepted the request." << std::endl;
            req->updateRequest(temp);
        } else if (temp == 0){
           std::cout<< "You have rejected the request." << std::endl;
        } else if (temp != 0 && temp != 1){
            std::cout << "Invalid choice please try again." << std::endl; 
        }
    }while (temp != 0 && temp != 1);
}


int Request::rentTotal(){

   
}