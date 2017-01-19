#include <iostream>
#include <fstream>

using namespace std;

int main(){

ofstream myfile;
myfile.open("newfile.txt");
myfile << "hello World 2. \n";
myfile.close();

}
