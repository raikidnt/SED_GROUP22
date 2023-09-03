#include <iostream>
#include <fstream>
#include ".vscode/Class/User/Admin/Admin.h"
#include ".vscode/Class/Server/Ui/UI.cpp"
using namespace std;
int main(int argc, char *argv[]) {
   welcome();
   Admin ad;
   ad.login();
   if(ad.login()) {
      cout << "Welcome Admin!" << endl;
   } 
   else {
      cout << "Login failed!" << endl;
   }

   return 0;
}
