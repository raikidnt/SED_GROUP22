#ifndef UI_H
#define UI_H
#include <iostream>
#include "../Bike/MotorBike.h"
void welcome ();
int user_choice ();
int menu (int choice); //choice for each type of user

std::vector<MotorBike> initialize(std::vector <MotorBike> &motorBikes);

#endif   //UI_H