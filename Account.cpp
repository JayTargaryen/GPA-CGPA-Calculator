#include "Account.hpp"

bool Account::testPassword(string pass) {

  if (password == pass) {
    return true;
  }
  return false;
}
void Account::setPassword(string pass) {

  password = pass;
}
void Account::setName(string nam) {

  name = nam;
}
void Account::setFileName() {

  string header = "UserFiles/" + name + ".txt";
  // name1 += ".txt";
  fileName = header;
}
