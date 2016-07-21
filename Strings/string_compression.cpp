/*
Implement a method to perform basic string compression using the counts
of repeated characters. For example, the string aabcccccaaa would become
a2blc5a3. If the "compressed" string would not become smaller than the original
string, your method should return the original string.
*/
#include <iostream>
#include <string>
#include <cstring>

using namespace std;


string compress_string(string const &str){

      string buffer{};
      char set=str[0];
      int count = 1;

      for(int i=1;i<=str.size();i++){

        if(i != str.size() && str[i]==set){
          count++;
        }
        else{
          buffer+=set;
          buffer.append(to_string(count));
          set=str[i];
          count=1;

          }
        }

        if(str.size() < buffer.size()){
          return str;
        }
        else {
          return buffer;
        }

}


int main(){
  string str = "aabcccccaaa";

  cout<<"output is: "<<compress_string(str)<<endl;

  return 0;
}
