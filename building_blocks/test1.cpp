#include <iostream>
#include <string>

using namespace std;

int solution(int X) {

    string str = to_string(X);

    unsigned int i=0;
    bool flag = true;
    int smallest=0;
    string temp;
    unsigned int len = str.length()-1;


    while(i < len){

      if(str[i] == str[i+1]){
          temp=str;
          temp.erase(i,1);
          int n = stoi(temp);
          if(flag == true) smallest = n;
          else if(smallest > n) smallest = n;
          }
          else if(str[i] != str[i+1]){
          temp=str;
          if(str[i]>str[i+1]) temp.erase(i+1,1);
          else temp.erase(i,1);
          int n2 = stoi(temp);
          if(flag == true) smallest = n2;
          else if(smallest > n2) smallest = n2;
          }
          i++;
      }



    return smallest;

}


int main(){

  std::cout << "ans is "<< solution(1) << std::endl;


}
