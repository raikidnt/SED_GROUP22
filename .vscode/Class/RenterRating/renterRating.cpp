#include "renterRating.h"
#include "renterRating.h"
// #include "../User/Member.cpp"

RenterRating::RenterRating(){};
RenterRating::RenterRating(std::string renterid, std::string ownerid,
                           int score, std::string comment)
    : renterid(renterid), ownerid(ownerid),
      score(score), comment(comment){};

// void RateRenter::setscore(int score){
//     this -> score = score;
// }

// void RateRenter::setcomment(std::string comment){
//     this -> comment = comment;
// }

// void RateRenter::rateRenter(){
//     bool check = false;
//     std::string i_renterid;
//     Member* renterID = new Member();
//     Member member;
//     std::cout << "Enter the renter ID you want to rate: " << std::endl;
//     do{
//         getline(std::cin, i_renterid);
//         if(check == false){
//             std::cout << "Unidentified renter ID." << std::endl;
//         }
//     }while(i_renterid.length() == 0 || check == false);

//     for(int i = 0; i < i_renterid.size(); i++){
//         if(member.IDNum[i] == i_renterid[i]){
//             check = true;
//         }
//     }
//     if (check == true){
//         std::cout << "Please enter the score from 0 to 10 : " << std::endl;
//     }else{
//         do{
//            std::cin >> score;

//            if(score < 0 || score > 10){
//                 std::cout << "Invalid score." << std::endl;
//            }
//         }while(score < 0 || score > 10);

//         std::cout << "Please leave a comment: ";
//         getline(std::cin, comment);
//     }

//     if(check == true){
//         RateRenter* rate = new RateRenter();
//         rate -> setscore(score);
//         rate -> setcomment(comment);
//         delete rate;
//     }

//     std::cout << "Thank you for rating!" << std::endl;
//     delete renterID;
// }