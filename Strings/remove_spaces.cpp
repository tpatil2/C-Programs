/*
remove wite spaces in sting
*/

#include <iostream>
#include <fstream>


using namespace std;


int main(){

    string str,line;

    ifstream file("myfile.txt");

    while (!file.eof()) {
     getline(file,line);
     str+=line;
    }

    std::cout << "Stirng is : "<< str << std::endl;

    for(int i=0;i<str.length();i++){
      int k=0;
      if(str[i]=='\n' || str[i]=='\t' || str[i]==' ' ){
        str.erase(i,1);
        i--;
      }
    }

    std::cout << "Stirng is : "<< str << std::endl;

    ofstream fileop ("output.txt");

    fileop<<str;

    fileop.close();
    file.close();

    return 0;

}
