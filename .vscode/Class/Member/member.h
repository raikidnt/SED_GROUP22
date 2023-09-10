#ifndef MEMBER_H
#define MEMBER_H
#include <bits/stdc++.h>
#include "../User.h"
using namespace std;

class Member: public User {
    public:
        enum{citizenid,passport} idtype;
        string idnumber;
        string drivernumber;
        string ownbikeid;
        
};

#endif