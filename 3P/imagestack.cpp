#include <iostream>
#include <fstream>
#include <string>
#include<sstream>
#include<vector>
#include <algorithm>
using namespace std;





int median(int x, int y, int argc, int*** arry){
/*  int ** output = new int*[x];
  for (int i = 0; i < x; i++){
    arry[i] = new int*[y];
  }

vector<int> v;

  for (int i = 0; i < argc-2; i++){
    for (int j = 0; j < x-1; j++){
      for (int n = 0; n < y-1; n++){

        v.push_back(arry[j][n][i]);
        sort(v.begin(), v.end());
        int size = v.size();
        output[j][n] = v[size/2];
        v.clear();
        size = 0;
      }
    }


  } */

vector<int> v;
for (int i = 0; i < argc-2; i++){
  v.push_back(arry[x][y][i]);
}
int sz = v.size();
sort(v.begin(), v.end());
return v[sz/2];



}


int main (int argc, char *argv[]){
if (argc<11){
  cout << "Wrong number of inputs" << endl;
}
int width;
int height;
int max;
string pic;
ifstream fileIn(argv[1]);
fileIn>>pic;
fileIn>>width;
fileIn>>height;
fileIn>>max;
static int*** all = new int**[width];
for (int i = 0; i < width; i++){
  all[i] = new int*[height];
  for (int j = 0; j < height; j++){
    all[i][j] = new int[argc];
  }
}
for (int i = 0; i < width; i++){
  for (int j = 0; j < height; j++){
    fileIn>>all[i][j][0];
  }
}
int counter =1;
for (int i = 2; i < argc-1; i++){
  ifstream fileIn(argv[i]);
  fileIn>>pic;
  fileIn>>width;
  fileIn>>height;
  fileIn>>max;
  for (int q = 0; q < width; q++){
    for(int w = 0; w < height; w++){
      fileIn>>all[q][w][counter];
    }
  }
  counter++;
}


//int ** medianOut;
//medianOut = median(width, height, argc, all);

ofstream outFile;
outFile.open(argv[argc-1]);
outFile << "P2" << endl;
outFile << width << " " << height << endl;
outFile << max << endl;
/*for (int i = 0; i < width; i++){
  for (int j = 0; j < height; j++){
    outFile<< medianOut[i][j] << endl;
  }
}
*/
for (int i = 0; i < width; i++){
  for (int j = 0; j < height; j++){
    outFile << median(i, j, argc, all) << endl;
  }
}
outFile.close();
for (int i = 0; i < width; i++)
{
  for (int j = 0; j < height; j++)
  delete[] all[i][j];
  delete[] all[i];
}
delete[] all;
return 0;
}
