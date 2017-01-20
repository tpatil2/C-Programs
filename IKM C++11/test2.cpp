#include <iostream>
using namespace std;
class Object {
  public:
  Object() {}
  void Print() const
  {
    cout << "const" << endl;
  }
  void Print()
  {
    cout << "mutable" << endl;
  }
};
void print_obj(const Object& obj) {
       obj.Print();
     }

int main() {
  Object obj1;
  const Object obj2;
  Object*const pobj1 = &obj1;
  print_obj(obj1);
  print_obj(obj2);
  obj1.Print();
  obj2.Print();
  pobj1->Print();
  return 0;
 }
