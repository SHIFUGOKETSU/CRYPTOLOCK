#ifndef PRINTS_H_
#define PRINTS_H_

#include <iostream>
using namespace std;

void print_banner() {
  cout << "   ██████╗ ██╗ █████╗ ██████╗ ██╗   ██╗" << endl;
  cout << "   ██╔══██╗██║██╔══██╗██╔══██╗╚██╗ ██╔╝" << endl;
  cout << "   ██║  ██║██║███████║██████╔╝ ╚████╔╝" << endl;
  cout << "   ██║  ██║██║██╔══██║██╔══██╗  ╚██╔╝ " << endl;
  cout << "   ██████╔╝██║██║  ██║██║  ██║   ██║  " << endl;
  cout << "   ╚═════╝ ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝ " << endl;
}

void print_help() {
  cout << "Help:" << endl;
  cout << "1) open \"name\" -- Open by filename" << endl;
  cout << "2) add \"name\"  -- Add more files as encrypted" << endl;
  cout << "3) help " << endl;
  cout << "4) reset " << endl;
  cout << "5) exit " << endl;
}

#endif // PRINTS_H_
