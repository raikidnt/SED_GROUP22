#include <string>
class User {
   private:
      std::string username;
      std::string password;
      std::string fullname;
      int userID;    //user ID: auto assigned when register as a user 
   public:
};

class Motobike {
   private:
      int rating = 3;
   public:
      int get_rating(){return rating;};
};
