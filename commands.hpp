#include <fstream>
#include <iostream>
#include <string>

using namespace std;

#ifndef COMMANDS_H_
#define COMMANDS_H_

string encdec(string line, string key) {
  string result = line;
  int keysize = key.size();

  for (int i = 0; i < line.size(); i++) {
    result[i] = line[i] ^ key[i % keysize];
  }

  return result;
}

void open_file(string name, string key) {
  ifstream file(name + ".enced");

  string line;
  while (getline(file, line)) {
    cout << encdec(line, key) << endl;
  }

  file.close();
}

void add_file(string name, string key) {
  ofstream outf(name + ".enced");
  ifstream inf(name);

  string line;
  while (getline(inf, line)) {
    outf << encdec(line, key) << endl;
  }

  outf.close();
  inf.close();
}

#endif // COMMANDS_H_
