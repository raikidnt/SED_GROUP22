#include "User.h"
#include <string>
User::User(){};   //default constructor
User::User (std::string n,std::string p): username(n),password(p){}