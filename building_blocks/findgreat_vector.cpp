#include <iostream>
#include <vector>
using namespace std;



int findgreatest(vector<int> v){

    string str;
    string temp;
    int i=0;
    int largest=0;

  if(!v.empty()){

    for(auto it = v.begin();it != v.end(); ++it){
        str += to_string(*it);
      }

     while(i < str.length()-1){

        if(str[i]==str[i+1]){
          temp = str;
          temp.erase(i,1);
            int x = stoi(temp);
          //  std::cout <<x << std::endl;

          if(largest < x) largest=x;
        }

        while(str[i]==str[i+1]) i++;
        if(str[i]!=str[i+1]) i++;
     }

     bool unique = false;
     for(int i=0;i<str.length()-1;i++){
       if(str[i]!=str[i+1]){
          unique = true;
       }else{
          unique = false;
          break;
        }
     }

     if(unique==true) largest = stoi(str);
   }

return largest;
}




int main(){

    vector<int> n = {2,2,3,3,3,6,2,2,6};
    //vector<int> n = {1,2,3,4,5,6,7,8};
    //vector<int> n = {};

    std::cout << "Largest is "<< findgreatest(n) << std::endl;

  return 0;
}
