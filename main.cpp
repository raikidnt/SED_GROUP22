<<<<<<< HEAD
#include <iostream>
#include <fstream>
#include ".vscode\Class\User\Member.cpp"
#include ".vscode\Class\UI\UI.cpp"
#include ".vscode\Class\Bike\Motorbike.cpp"
=======
#include <bits/stdc++.h>
#include <string>
// #include ".vscode\Class\User\Member.cpp"
// #include ".vscode\Class\UI\UI.cpp"
#include ".vscode/Class/User/Admin.cpp"   
#include ".vscode/Class/User/User.cpp"   
#include <string>
>>>>>>> c0f1d76a0c0ee6fb3f36a908d7c87f63bd61eff8
using namespace std;
int main(int argc, char *argv[]) {
   // welcome();
   // MotorBike mk1 ("Futures Neo", "Black", manual,  125,  2022, 6);
   // Member mb1("Nhat Nguyen", 865608476, CCCD , 00112233,"9959334",  "30/12/2023", 10);
   // mb1.showInfo_M();
   // mb1.addBike(mk1);
   // mb1.showInfo_M();
   
   // mb1.Login("haro", "123");
   // mk1.showBikeInfo();

   // Admin ad;
   string user;
   string pass;
   Admin ad;
   ad.login(user,pass);

   return 0;
}