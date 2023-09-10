#include "Member.h"

Member::Member(){};
Member::Member(std::string i_fullName, int i_phoneNumber,
               IDTYPE &i_idType, int i_IDNum, std::string i_licenseID,
               std::string i_liscenceExpDate, int i_credits) {
      fullName = i_fullName;
      phoneNumber = i_phoneNumber;
      IDTYPE i_idType = i_idType;   //check this
      IDNum  = i_idNum;
      drvLicenseID = i_licenseID;
      expDate = i_liscenceExpDate;
      availCredits = i_credits;
}