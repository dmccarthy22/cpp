#include "unorderedmap.h"
#include <string>

using namespace std;

int main(){
   UnorderedMap <double, int8_t> m; 


   m.insert(13.2, 1);
   m.insert(14.2, 2);
   m.insert(15.2, 3);
   m.insert(16.2, 4);
   m.insert(17.2, 5);
   m.insert(18.2, 6);
   m.insert(19.2, 7);
cout << "ERASING" << endl;
  cout << m.erase(13.2) <<endl;
  //cout <<m.find(13.2)->key << endl;
   m.erase(15.2);
   m.erase(17.2);
   cout <<"DONE" << endl;
   m[3.6] = 5;
   cout << m.find(3.6)->data << endl;
 


}
