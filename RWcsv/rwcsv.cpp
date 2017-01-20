#include <iostream>
#include <fstream>
using namespace std;

int main(){

  ifstream ip("data.csv");

  if(!ip.is_open()) std::cout << "ERROR: File Open" << '\n';
  string firstname;
  string lastname;
  string age;
  string weight;

  while(ip.good()){

    getline(ip,firstname,',');
    getline(ip,lastname,',');
    getline(ip,age,',');
    getline(ip,weight,'\n');

    std::cout << "Name: "<<firstname<< " "<<lastname << '\n';
    std::cout << "Age: "<<age << '\n';
    std::cout << "Weight: "<<weight << '\n';
    std::cout << "-------------------" << '\n';
  }

  ip.close();
}
