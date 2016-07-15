#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

void print_vector(vector<double> vec){

      std::cout << "\nVector is :" << std::endl;

      std::vector<double>::iterator it;

      for(it = vec.begin();it != vec.end(); ++it){
        std::cout <<"[" <<*it <<"]"<< " ";
      }

      /*
      for(int i=0;i<vec.size();i++){
        std::cout << vec.at(i)<< " " << std::endl;
      }*/


      std::cout << "\nEnd of vector" << std::endl;
}

void print_it(vector<double> vec) {

    std::cout << "\nMy vector contains" << std::endl;

    for(auto it=vec.cbegin(); it!=vec.cend();it++){
      std::cout <<"["<< *it <<"]"<< " " ;
    }

    std::cout << "\nEnd of vector" << std::endl;

    while (!vec.empty())
  {
    vec.pop_back();
  }

  if (vec.empty()) {std::cout << "vec is EMPTY NOW" << std::endl;}


    std::cout << "Print using auto" << std::endl;
    for(auto& x:vec)
      std::cout << x<<" " << std::endl;
      std::cout << "Done printing" << std::endl;

}


void print_revit(vector<double> vec) {

    std::cout << "\nMy vector contains" << std::endl;

    for(auto rit=vec.crbegin(); rit!=vec.crend();rit++){
      std::cout <<"["<< *rit <<"]"<< " " ;
    }

    std::cout << "\nEnd of vector" << std::endl;

}
int main(int argc, char const *argv[]) {

  //vectors are like arrays but size is changed
  //decleration  vector <datatype> vectorname(size);

    vector<double> rainfall(7);
    std:std::vector<double>::iterator it;

    rainfall[0]=22.1;
    rainfall[1]=44.4;
    rainfall[2]=44.3;
    rainfall[3]=22.5;
    rainfall[4]=11.4;
    rainfall[5]=77.5;
    rainfall[6]=33.3;

    rainfall.push_back(25.3);
    rainfall.emplace(rainfall.begin()+1, 123);
    rainfall.emplace_back(999);
    rainfall.erase(rainfall.begin()+2,rainfall.end()-3);

      it=rainfall.begin();

      rainfall.insert(it,5,992);

    std::cout << "Value at front is :"<<rainfall.front() << std::endl;
    std::cout << "Value at back is : " << rainfall.back()<< std::endl;
    print_vector(rainfall);
    print_revit(rainfall);
    //Modifiers
    rainfall.assign(3,100); //assign 3 values with
    rainfall.clear();

    rainfall.push_back(25.3);
    rainfall.push_back(25.3);
    rainfall.push_back(25.3);

    print_vector(rainfall);
    print_it(rainfall);

    std::cout << "size: " << rainfall.size() << '\n';
    std::cout << "capacity: " << rainfall.capacity() << '\n';
    std::cout << "max_size: " << rainfall.max_size() << '\n';

    std::vector<int> myvector (5);

    int* p = myvector.data();

    *p = 10;
    ++p;
    *p = 20;
    p[1] = 100;

    std::cout << "myvector contains:";
    for (unsigned i=0; i<myvector.size(); ++i)
    std::cout << ' ' << myvector[i];
    std::cout << '\n';


    std::vector<double> vec1(5);
    std::vector<double> vec2(3);

    vec1.assign(5,555);
    vec2.assign(3,333);

    print_it(vec1);
    print_it(vec2);

    print_vector(vec1);
    print_vector(vec2);

    vec1.swap(vec2);

    print_vector(vec1);
    print_vector(vec2);



  return 0;
}
