#include "bikeRating.h"

std::string BikeRatingIDgenerate(){
   // srand(time(NULL));
   int num = rand() % 1001; //random number form 0-100
   return ("Bkrt - " + std::to_string(num));
}

BikeRating::BikeRating(){}

BikeRating::BikeRating(int i_score, std::string i_comment) : score(i_score), comment(i_comment) {}
// void BikeRating::setRateBikeID(std::string rateBikeID){
//     this->rateBikeID = rateBikeID;
// }
// void BikeRating::setScore(int score){
//     this->score = score;
// }
// void BikeRating::setComment(std::string comment){
//     this->comment = comment;
// }

// void BikeRating::RateBike(){
//     Member *renterID = new Member();
//     BikeRating *b_RateBike = new BikeRating();
//     MotorBike bike;
//     bool check = false;
//     int score;
//     std::string comment1;
//     b_RateBike->setRateBikeID(BikeRatingIDgenerate());
//     std::cout << "- Bike Rating ID: " << rateBikeID << std::endl;
//     std::cout << "Your Member ID: " << renterID->IDNum << std::endl;

//     std::string a_bikeID;
//     std::cout << "Please enter your bike ID: ";
//     do {
//         getline(std::cin , a_bikeID);

//             if (check == false){
//             std::cout << "Unidentified bike ID." << std::endl;
//         }
//     } while (a_bikeID.length() == 0 || check == false);

//     for(int i = 0; i < a_bikeID.size(); i++){
//         if(bike.bikeID[i] == a_bikeID[i]){
//             check = true;
//         }
//     }
//     if (check == true){
//         std::cout << "Please rate your bike (1-10): ";
//         do{
//             std::cin >> score;
//             if (score < 0 || score > 10){
//                 std::cout << "Invalid value, please try again." << std::endl;
//             }
//         } while (score < 0 || score > 10);
//         std::cout << std::endl;
//         std::cout << "Please leave a comment: ";
//         getline(std::cin, comment1);
//     }
//     if (check == true){
//         b_RateBike->setScore(score);
//         b_RateBike->setComment(comment1);
//     }
//     std::cout << "Thank you for your rating !" << std::endl;
//     delete renterID;
//     delete b_RateBike;
// }
