#ifndef USERS_H
#define USERS_H

#include "Account.hpp"

class Users {

public:

  int numOfUsers;
  vector<Account>accounts;

  void loadInfo();
  void saveInfo();
  void menu();
  Account searchUser(string name);
  bool checkUser(string name);
  void addAccount(Account account1);

};

#endif
