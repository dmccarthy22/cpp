/* CS515 Assignment 1
File: image.cpp
Name: Dan McCarthy
Section: 4
Collaboration Declaration:
          I received assistance from TA Ethan, the PAC, and collaborated with other students in PAC (Paul Ackels and Joe Vignone)
*/
#include <iostream>
#include <fstream>
#include <string>
#include<sstream>
#include<vector>
using namespace std;


int** rotateArray(int** array , int width, int height){
  int** rot;
  rot = new int*[height];
  for(int i = 0; i < height; i++){
    rot[i] = new int[width];
  }

  cout << "baa" << endl;
  for (int i = 0; i < height; i++){
    for (int j = 0; j < width; j++){
      rot[i][j] = array[(width-1)-j][i];
    }
  }


  



//cout << "m" << endl;
return rot;
}

int ** negativeArray(int **array, int width, int height, int maxScale){
  int ** negative = new int*[width];
  for (int i = 0; i < width; i++){
    negative[i] = new int[height];
  }
//  cout << "MMM" <<endl;

  for (int i = 0; i < width; i++){
    for (int j = 0; j < height; j++){
      negative[i][j] = maxScale - array[i][j];
    }
  }
  return negative;
}



int main(int argc, char *argv[]){

string data[4], a, widthstr, heightstr, d;
  int width = 0;
  int height = 0;

  if (argc != 4){
    cout << "Usage: image <input image> <neg image> <rotate image>" << endl;
  }

  ifstream fileIn(argv[1]);

  if (!fileIn){
    cout << "Can not open " << argv[1] << " for input." << endl;
  }
  for (int i = 0; i < 4; i++){
    fileIn >> data[i];
  }

  a = data[0];
  widthstr = data[1];
  heightstr = data[2];
  d = data[3];
int max = stoi(d);
  width = stoi(widthstr);
  height = stoi(heightstr);
int ** arry = new int*[height];
for (int i = 0; i < height; i++){
  arry[i] = new int[width];
}
  for (int i = 0; i < width; i++){
    for (int j = 0; j < height; j++){
      fileIn >> arry[i][j];
    }
  }
  cout << arry[0][0]<< endl;
  //cout << "lo" << endl;
//cout << arry[1][3] << endl;
  fileIn.close();

int ** rotateImage;

rotateImage = rotateArray(arry, width, height);
//cout << "a" << endl;
rotateImage = rotateArray(rotateImage, width, height);
//cout << "b" << endl;
rotateImage = rotateArray(rotateImage, width, height);
//cout << "c" << endl;
/*
for (int i = 0; i < height; i++){
  for (int j = 0; j < width; j++){
    rotateImage[i][j] = arry[j][i];
  }
}
*/
ofstream outfile;
outfile.open(argv[3]);
outfile << "P2" << endl;
outfile << height << " " << width << endl;
outfile << d << endl;
for (int i = 0; i < width; i++){
  for (int j = 0; j < height; j++){
    outfile << rotateImage[i][j] << endl;
  }
}
//cout << "IBIYVUVUVGVJVVJGVJCG" << endl;
//int ** negImage;
//negImage = negativeArray(arry, width, height, max);
//cout<< "nnnn" << endl;
ofstream neg;
neg.open(argv[2]);
neg << "P2" << endl;
neg << width << " " << height << endl;
neg << max << endl;
//cout << "ba" << endl;
for (int i = 0; i < height; i++){
  for (int j = 0; j < width; j++){
    neg << (max - arry[i][j]) << endl;
  }
}
//cout << "bruh" << endl;
/*for (int i = 0; i < width; i++){

    //delete [] arry [i][j];
    delete [] arry[i];


}
for (int i = 0; i < height; i++){

    delete [] rotateImage[i];
  //  delete [] rotateImage[i];
  //  delete [] rotateImage[j];
}


delete [] arry;
delete [] rotateImage;


*/
}
