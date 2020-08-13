/* CS515 Assignment 0
File: hello.cpp
Name: Karen JIN
Section: 1
Collaboration Declaration:
          assistance received from TA, PAC and online resources etc.
*/

#include <iostream> // for cin and cout
#include <string> // for string type
using namespace std;


int main(int argc, char ** argv) {
    string name = "";
    while (name == ""){
    cout << "What is your name?" << endl;
    std:getline (std::cin,name);
  }
    cout << "Hello World!" << endl;
    cout << "Welcome to CS515, " << name << "!" << endl;

    return 0;
}
