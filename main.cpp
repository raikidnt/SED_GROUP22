#include <iostream>
#include <fstream>
#include ".vscode\Class\User\Member.cpp"
using namespace std;
int main(int argc, char *argv[]) {
   Member mb1("Nhat Nguyen", 865608476, CCCD, 00112233,"9959334",  "30/12/2023", 10);
   mb1.showInfo_M();

   return 0;
}