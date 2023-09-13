#include <iostream>
#include <fstream>
#include ".vscode\Class\User\Member.cpp"
#include ".vscode\Class\UI\UI.cpp"
using namespace std;
int main(int argc, char *argv[]) {
   // welcome();
   // MotorBike mk1 ("Futures Neo", "Black", manual,  125,  2022, 6);
   Member mb1("Nhat Nguyen", 865608476, CCCD , 00112233,"9959334",  "30/12/2023", 10);
   // mb1.showInfo_M();
   // mb1.addBike(mk1);
   mb1.showInfo_M();
   
   // mb1.Login("haro", "123");
   // mk1.showBikeInfo();
   // vector <MotorBike> bike;
   // vector <Member> members;
   return 0;
}