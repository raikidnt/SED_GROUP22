#include "Request.h"
#include <bits/stdc++.h>
#include <string>
#include <vector>
#include "../Bike/MotorBike.cpp"
#include "../User/Member.cpp"
#include "../Bike/MotorBike.h"

using namespace std;

string requestIDgenerate(){
   // srand(time(NULL));
   int num = rand() % 1001; //random number form 0-100
   return ("Request - "+std::to_string(num));
}


Request::Request(){};
Request::Request(string requestID, string renterID, string returnDate, string startDate, STATUS status, string bike_id, int check)
:requestID(requestID), renterID(renterID), returnDate(returnDate), status(status), startDate(startDate), bike_id(bike_id), check(check){
    renterID = IDNum;
};

void Request::setRequestID(string requestID){
    this->requestID = requestID;
}
void Request::setRenterID(string renterID){
    this->renterID = renterID;
}
void Request::setReturnDate(string returnDate){
    this->returnDate = returnDate;
}
void Request::setStartDate(string startDate){
    this->startDate = startDate;
}
void Request::setbikeID(string bike_id){
    this->bike_id = bike_id;
}
void Request::updateRequest(int check){
    this->check = check;
}

vector<std::string> splitDate(std::string &date, char splitChar){
    stringstream ss(date);
    vector<string>strarray;
    string val;
    while(getline(ss, val, splitChar)){
        strarray.push_back(val);
    }
    return strarray;
}

bool validDate(std::string &date){
    vector<string> d = splitDate(date, '/');
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


void Request::sentrequest(std::string i_renterID){
    string Bikeid;
    MotorBike bike;
    bool check = false;
    cout << "- Renting request -" << endl;
    cout << "Enter the bike ID: " << endl; 
     do {
        getline(cin , Bikeid);
    } while (Bikeid.length() == 0);

    for(int i = 0; i < Bikeid.size(); i++){
        if(bike.bikeID[i] == Bikeid[i]){
            check = true;
        }
    }
    if (check == false){
        cout << "Unidentified bike ID." << endl;
    } else{
        do {
            cout << "Enter the begin of renting period (dd/mm/yyyy):\n";
            do {
                std::getline(cin , startDate);
            } while (startDate.length() == 0);
            if (!validDate(startDate)){
                cout << "Invalid form, please try again (dd/mm/yyyy)." << endl;
            }
        } while(!validDate(startDate));

        do {
            cout << "Enter the return date (dd/mm/yyyy):\n";
            do {
                std::getline(cin , returnDate);
            } while (returnDate.length() == 0);
            if(startDate == returnDate){
                cout << "The two dates cannot be the same, please try again." << endl;
            }
            else if (!validDate(startDate)){
                cout << "Invalid form, please try again (dd/mm/yyyy)." << endl;
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
        cout << "Request has been sent." << endl;
        delete[] req;
    } 
}

void Request::checkRequest(){
    Request *req = new Request();
    int temp;
    cout << "RequestID: " << requestID << endl;
    cout << "Bike ID: " << bike_id << endl;
    cout << "Renter ID: " << renterID << endl;
    cout << "Start Date: " << startDate << endl;
    cout << "Return Date: " << returnDate << endl;
    cout << endl;
    do {
        cout << "Press 1 to accept or 0 to reject the request: ";
        cin >> temp;

        if(temp == 1){
            cout << "You have accepted the request." << endl;
            req->updateRequest(temp);
        } else if (temp == 0){
            cout << "You have rejected the request." << endl;
            req->updateRequest(temp);
        } else if (temp != 0 && temp != 1){
            cout << "Invalid choice please try again." << endl; 
        }
    }while (temp != 0 && temp != 1);
}


int Request::rentTotal(){

   
}