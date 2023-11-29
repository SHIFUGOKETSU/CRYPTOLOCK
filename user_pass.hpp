#include "hashing.hpp"
#include <fstream>
#include <iostream>
#include <string>

#ifndef USER_PASS_H_
#define USER_PASS_H_

using namespace std;

string ask_pass() {
  ifstream hashfile("key");
  string hash;
  getline(hashfile, hash);
  hashfile.close();

  string username, pass;
wrongpass:
  cout << "\nUsername?:  ";
  cin >> username;
  cout << "\nPass?:  ";
  cin >> pass;

  if (hash == calculateSHA128(username + pass)) {
    return pass;
  } else {
    system("clear");
    cout << "\nWrong Username or Password";
    goto wrongpass;
  }
}

void create_key() {
  string username, pass, confirm_pass;
cantconfirm:
  cout << "\nEnter a username:  ";
  cin >> username;
  cout << "\nEnter pass:  ";
  cin >> pass;
  cout << "\nConfirm pass:  ";
  cin >> confirm_pass;

  if (pass == confirm_pass) {
    fstream file;
    file.open("key", ios::out);
    file << calculateSHA128(username + pass);
    file.close();
  } else {
    goto cantconfirm;
  }
}

#endif // USER_PASS_H_
