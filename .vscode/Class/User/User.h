#ifndef USER_H
#define USER_H
#include <bits/stdc++.h>

class User{
    private:
        std::string userName;
        std::string password;
    public:
        User ();
        User (std::string n,std::string p);
        int UserLogin(std::string name, std::string pass);
        // int UserLogout();

    

};

#endif // USER_H