#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
using namespace std;


int main (int argc, char * argv[]){

  ifstream file;
  file.open(argv[1]);
  map<string , map <int,int>> words;
  string word;
  int year;
  int freq;
  int hold;
  while (!file.eof()){
    file>>word;
    file>>year;
    file>>freq;
    file>>hold;
    words[word][year] = freq;


  }
  file.close();
  while (cin){
    cout << "Which word starting which year? " << endl;
    cin >>word;
    cin>>year;
    while(year<2009){
      cout <<year << " " << words[word][year] << endl;
      year++;
    }
  }


 

}
