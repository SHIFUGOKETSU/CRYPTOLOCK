#include "commands.hpp"
#include "prints.hpp"
#include "user_pass.hpp"
#include <filesystem>
#include <vector>

namespace fs = filesystem;

int main() {
  if (!fs::exists("key")) {
    create_key();
  }

  string key = ask_pass();

reset:
  system("clear");
  print_banner();
  print_help();

  string command, arg, temp;
next:
  getline(cin, temp);
  cout << "\n>> ";
  cin >> command;

  if (command == "open") {
    cin >> arg;
    open_file(arg, key);
  } else if (command == "add") {
    cin >> arg;
    add_file(arg, key);
  } else if (command == "help") {
    print_help();
  } else if (command == "exit") {
    return 0;
  } else if (command == "reset") {
    goto reset;
  } else if (command == "sample") {
    string line;
    getline(cin, line);
    string enc = encdec(line, key);
    cout << enc << endl;
    cout << encdec(enc, key) << endl;
  } else {
    cout << "\nUnknown Command";
  }
  goto next;

  return 0;
}
