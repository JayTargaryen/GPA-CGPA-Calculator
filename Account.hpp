#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "Career.hpp"

class Account {

  public:

    string name;
    string password;
    string fileName;
    Career career1;

    void setPassword(string pass);
    void setName(string nam);
    void setFileName();
    bool testPassword(string pass);

};

#endif
