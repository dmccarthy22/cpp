#include "HuffTree.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    HuffTree h;
    char c[7] = {'e', 'f', 'd', 'a', 'g'};
    int f[7] = {12, 15, 2, 3, 11};
    h.buildTree(c,f,5);
    //cout <<"HHHHHH" << endl;
    

    cout << h.getCode('e') << endl;
    cout << h.getCode('f') << endl;
    cout << h.getCode('a') << endl;
    cout << h.getCode('g') << endl;
    cout << h.getCode('d') << endl;
}
