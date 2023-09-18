<<<<<<< Updated upstream
=======
<<<<<<< HEAD
<<<<<<< HEAD
#include <iostream>
#include <fstream>
#include ".vscode\Class\User\Member.cpp"
#include ".vscode\Class\UI\UI.cpp"
#include ".vscode\Class\Bike\Motorbike.cpp"
=======
>>>>>>> Stashed changes
#include <bits/stdc++.h>
// #include ".vscode\Class\User\Member.cpp"
// #include ".vscode\Class\UI\UI.cpp"
<<<<<<< Updated upstream
// #include ".vscode/Class/User/Admin.cpp"   
// #include ".vscode/Class/User/User.cpp"   
#include ".vscode/Class/UI/UI.cpp"
=======
#include ".vscode/Class/User/Admin.cpp"   
#include ".vscode/Class/User/User.cpp"   
#include <string>
>>>>>>> c0f1d76a0c0ee6fb3f36a908d7c87f63bd61eff8
=======
// #include <bits/stdc++.h>
// #include ".vscode\Class\User\Member.cpp"
// #include ".vscode\Class\UI\UI.cpp"
// #include ".vscode/Class/User/Admin.cpp"   
// #include ".vscode/Class/User/User.cpp"

#include ".vscode/Class/UI/UI.cpp"

#define memberFile ".vscode/Data/Member.txt"
// #include <string>
>>>>>>> d56694d5d12ad1911814cb6e55bb48e764b55d5f
>>>>>>> Stashed changes
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
   System sys;
   // sys.mainMenu();
   sys.loadMembers();

   // sys.showMembersList();
   sys.adminViewMembers();

<<<<<<< Updated upstream
=======
   // Admin ad;
   // string user;
   // string pass;
   // Admin ad;
   // ad.login(user,pass);
   
   System sys;


   // sys.loadBikes();
   
   sys.loadMembers();
   sys.showMembersList();
   
>>>>>>> Stashed changes

   return 0;
}