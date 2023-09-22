#ifndef USER_H
#define USER_H
#include <bits/stdc++.h>

class User{
    private:
        std::string username;
        std::string password;
    public:
        User ();
        User (std::string n,std::string p);
        friend class System;
        friend class Member;
};

#endif // USER_H