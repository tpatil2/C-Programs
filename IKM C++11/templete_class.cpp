#include <iostream>

using namespace std;

template <class T>

class Cal{

    T first, second;

  public:
    Cal(int a, int b){
      first = a;
      second =b;
    }
    T max();
};

template <class T>

T Cal<T>::max(){
  return (first>second?first:second);
}

int main()
{
  Cal<int> c(22,10);
  std::cout << "max is:"<<c.max() << '\n';
  return 0;
}
