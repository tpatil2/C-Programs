#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;


int main(){

  char filename[50];
  ifstream ip;
  cin.getline(filename, 50);

  ip.open(filename);

  if(!ip.is_open()){
    std::cout << "File Name does not Exists" << '\n';
    exit(EXIT_FAILURE);
  }

  char word[50];
  ip >> word;
  while(ip.good()){
    std::cout << word<< ' ';
    ip>>word;
  }

  return 0;
}
