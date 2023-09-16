// #include <bits/stdc++.h>
// #include ".vscode\Class\User\Member.cpp"
// #include ".vscode\Class\UI\UI.cpp"
// #include ".vscode/Class/User/Admin.cpp"   
// #include ".vscode/Class/User/User.cpp"

#include ".vscode/Class/UI/UI.cpp"

#define memberFile ".vscode/Data/Member.txt"
// #include <string>
using namespace std;
int main(int argc, char *argv[]) {
   // welcome();
   // MotorBike mk1 ("Futures Neo", "Black", manual,  125,  2022, 6);

   // Member mb1("Nhat Nguyen", "0865608476", 
   //             "CCCD" , "00112233",12,  
   //             "22312","30/12/2023", 2.3);
   // mb1.showInfo_M();

   // mb1.addBike(mk1);
   // mb1.showInfo_M();
   
   // mb1.Login("haro", "123");
   // mk1.showBikeInfo();

   // Admin ad;
   // string user;
   // string pass;
   // Admin ad;
   // ad.login(user,pass);
   
   System sys;


   // sys.loadBikes();
   
   sys.loadMembers();
   sys.showMembersList();
   

   return 0;
}