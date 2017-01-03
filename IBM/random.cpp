#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>

using namespace std;

int getRandom(int a)
{
  int c=535,d=43443, b=4444;
  int ans;

  ans=a*(b/c)+d;
  ans=ans%27;
  ans=ans+65;
  return ans;
}

int main(){

  int len;
  int num;
  string result = "";

  cout<<"please enter length of string";
  cin>>len;
  srand(time(0));

  for(int i = 0; i < len; i++)
  {
    cout << getRandom(rand()%30 +1985) << endl;
  }

  std::cout << result << std::endl;

  return 0;
}
