#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[]) {

    cout << "Some data types in C++" << endl;

    //variables and datatypes

    const double PI = 3.1424342345434;
    char myGrade= 'A';// one byte
    bool flag = true; //one byte
    int age = 234567890; // four byte
    float speed = 9.12345;  //6 decimal place
    double  accleration = 86.1234567891112131415; // 15 digits a lenght

    cout << "char  :"<<sizeof(myGrade)<<" "<<myGrade<<endl;
    cout << "bool  :"<<sizeof(flag)<<" "<<flag<<endl;
    cout << "int   :"<<sizeof(age)<<" "<<age<<endl;
    cout << "float :"<<sizeof(speed)<<" "<<speed<<endl;
    cout << "double:"<<sizeof(accleration)<<" "<<accleration<<endl;

    /*output:
    Some data types in C++
    char  :1
    bool  :1
    int   :4
    float :4
    double:8
    */

    //increment and decrement

    int three = 3;
    std::cout << "three++ is :" << three++ << std::endl;
    std::cout << "++three is :" << ++three << std::endl;
    std::cout << "three-- is :" << three-- << std::endl;
    std::cout << "--three is :" << --three << std::endl;


    // Order of operation * / + -
    float exp1 = 3-2+3*6/3;
    float exp2 = (3+2-3)*(1/2);
    std::cout << "3-2+3*6/3 = " << exp1 << std::endl;
    std::cout << "(3+2-3)*(8/2) = " << exp2 << std::endl;
    std::cout << "simpe div type cast " <<(float)4/5<< std::endl;

  return 0;

}
