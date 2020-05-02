#include "Users.hpp"

// void Users::openFile(Account account1) {
//
//   //account1.car
// }
void Users::loadInfo() {

    Account account1;

    ifstream inFS("UserFiles/gpaProgramInfo.txt");
    //inFS.open("/GPA/UserFiles/gpaProgramInfo.txt");
    string temps;
    getline(inFS,temps);
    istringstream (temps) >> numOfUsers;
    for(int i = 0; i < numOfUsers; i++) {
      getline(inFS, account1.name);
      getline(inFS, account1.password);
      getline(inFS, account1.fileName);
      accounts.push_back(account1);
    }
}
void Users::saveInfo() {

  Account account1;
  ofstream osFS;

  osFS.open("UserFiles/gpaProgramInfo.txt");
  osFS << numOfUsers << "\n";
  for(int i = 0; i < numOfUsers; i++) {
    account1 = accounts.at(i);
    osFS << account1.name << "\n";
    osFS << account1.password << "\n";
    osFS << account1.fileName << "\n";
  }
  osFS.close();
}
Account Users::searchUser(string name) {

  Account account1;

  for(int i = 0; i < accounts.size(); i++) {
    account1 = accounts.at(i);
    if (account1.name == name) {
      return account1;
    }
  }
}
bool Users::checkUser(string name) {

  Account account1;

  for(int i = 0; i < accounts.size(); i++) {
    account1 = accounts.at(i);
    if (account1.name == name) {
      return true;
    }
  }
  return false;
}
void Users::addAccount(Account account1) {

  accounts.push_back(account1);
  numOfUsers++;
}
void Users::menu() {

  int num,num2 = 0;
  Account account1;
  string password;
  string password2;
  string name;

  cout << "GPA Calculator Login" << endl
       << "Type 1 to create a new account" << endl
       << "Type 2 to sign in" << endl;

  cin >> num;

  while(!(num == 1 || num == 2)) {
    cout << "Type 1 to create a new account'" << endl
         << "Type 2 to sign in" << endl;
         cin >> num2;
  }
  if(num == 1) {
    cout << "Set username" << endl;
      cin >> ws;
    getline(cin,name);

    bool exist = checkUser(name);
    if (exist == false) {
      account1.setName(name);
    }
    else {
      cout << "Name is already taken" << endl;
      return;
    }
    cout << "Set password" << endl;
    getline(cin,password);
    cout << "Confirm password" << endl;
    cin >> password2;
    while(!(password == password2)) {
      cout << "Passwords don't match" << endl
           << "Try password again" << endl;
        cin >> password2;
    }
    account1.setPassword(password);
    account1.setFileName();
    addAccount(account1);
    account1.career1.buildCareer();
    saveInfo();
    account1.career1.menu(account1.fileName);
    //cout << "That's all we have working so far." << endl;

  }
  if(num == 2) {
    cout << "Type username:" << endl;
    cin >> ws;
    getline(cin, name);
    bool exist1 = checkUser(name);
    if (exist1 == true) {
      account1 = searchUser(name);
      cout << "Type password: " << endl;
      getline(cin, name);
      if(name == account1.password) {
        account1.career1.setSemesters(account1.fileName);
        account1.career1.menu(account1.fileName);
      }
      else {
        cout << "Wrong password." << endl;
      }
    }
    else {
      cout << "That account doesn't exist" << endl;
      return;
    }
  }
}
