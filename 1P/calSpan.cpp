/* CS515 Assignment 1
File: calSpan.cpp
Name: Dan McCarthy
Section: 4
Collaboration Declaration:
          I received assistance from TA Ethan, the PAC, and collaborated with other students in PAC (Paul Ackels and Joe Vignone)
*/

#include <iostream> // for cin and cout
#include <string> // for string type
#include<fstream>
#include<vector>
#include<sstream>
using namespace std;
double validNum(string str);
int validInput(string input);

int main(int argc, char ** argv) {

  if (argc!=2){
    cout << "Wrong number of arguments" << endl;
    exit(1);
  }

  string in;
  double val;
  vector<double> list;
  string input = "";
  int intInput;
  stringstream ss;
  string str;
  bool isExit = false;
  int counter = 1;
  bool inRange = true;
  bool goodInput = true;

  ifstream fileIn(argv[1]);

  if (!fileIn){
    cout << "Error opening file" << endl;
    exit(1);
  }
  while (fileIn >> str){
    list.push_back(validNum(str));
  }

  fileIn.close();
//for (int i =0; i < list.size(); i++){
  //cout << list[i] << endl;
//}

  while (!isExit){
    cout << "Which minute to query? ";
     cin >> input;
     if ((tolower(input[0]))=='e'
     && (tolower(input[1]))=='x'
    && (tolower(input[2]))=='i'
     && (tolower(input[3]=='t'))){
     isExit = true;
     break;
   }

     intInput = validInput(input);
     if (intInput == -1000){
       cout << "Wrong query input." << endl;
       goodInput = false;

     }
     else if (intInput >= list.size() || intInput < 0){
       inRange = false;
       cout << "Query minute out of range" << endl;
     }
     else if (list[intInput]== -999){
       cout << "Data at minute " << intInput << " is corrupted." << endl;
     }
     else {
       if (list[intInput]> list[intInput-1]){

       }
     }
     for (int i = intInput-1; i >=0; i--){
       if (list[intInput] == -999){
         break;
       }
       if (list[intInput]>=list[i]){
         counter = counter +1;
       }
       else {
         break;
       }
     }
     if (list[intInput]!=-999 && inRange && goodInput){
     cout << "Data at minute " << intInput << " is a " << counter << "-minute(s) high." << endl;

   }
   counter = 1;
}
cout << "" << endl;
  }




double validNum(string str){
  bool decimal = false;
  for (int i = 0; i < str.length(); i++){
    if (!(isdigit(str[i]))){
      if (str[i] == '.' && !decimal){
      decimal = true;
    }
    else if (str[i] == '.' && decimal){
      return -999;
    }
    else if (str[i] == '-'){
      continue;
    }


    else {
      return -999;
    }
  }

}
if (stod(str)<100 && stod(str)>-100){
  return stod(str);
}
else {
  return -999;
}
}

int validInput(string input){
  for (int i = 0; i < input.length(); i++){
  if (!(isdigit(input[i]))){
    return -1000;
  }

}
return stoi(input);
}
