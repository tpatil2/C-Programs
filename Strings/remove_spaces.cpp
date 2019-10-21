/*
remove wite spaces in sting
*/

#include <iostream>
#include <fstream>


using namespace std;


int main(){

    string s,line;

    ifstream file("myfile.txt");

    while (!file.eof()) {
     getline(file,line);
     s+=line;
    }

    std::cout << "Stirng is : "<< s << std::endl;

    for(int i=0;i<s.length();i++){
      int k=0;
      if(s[i]=='\n' || s[i]=='\t' || s[i]==' ' ){
        s.erase(i,1);
        i--;
      }
    }

    std::cout << "Stirng is : "<< s << std::endl;

    ofstream fileop ("output.txt");

    fileop<<s;

    fileop.close();
    file.close();

    return 0;

}
