#include <iostream>

using namespace std;


class Mycl{

public:
    int num;
    Mycl();
    Mycl(int);
    Mycl operator+(Mycl n);
};

Mycl::Mycl(){

}

Mycl::Mycl(int c){
  num = c;
}

Mycl Mycl::operator+(Mycl obj2){
  Mycl n;
  n.num=num+obj2.num;
  return n;
}

int main(){

  Mycl a(21);
  Mycl b(29);
  Mycl c;

  c=a+b;

  std::cout << c.num << '\n';

}
