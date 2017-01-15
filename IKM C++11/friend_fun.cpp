#include <iostream>

using namespace std;

class Test{
private:
  int cnt;
public:
  Test(){ cnt=0;}
  friend void changeVal(Test &ob);
};

void changeVal(Test &obj){
  std::cout << "  obj->cnt"<<  obj.cnt << '\n';
  obj.cnt = 99;
  std::cout << "  obj->cnt"<<  obj.cnt << '\n';
}

int main(){
  Test o;
  changeVal(o);
  return 0;
}
