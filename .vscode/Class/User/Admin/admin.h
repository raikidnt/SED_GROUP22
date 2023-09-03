#ifndef ADMIN
#define ADMIN
// #include <string>
class Admin {
   private:
      std::string admin_username = "admin";
      std::string admin_password = "123abc";
   public:
      Admin(){};
      bool login();
};


#endif