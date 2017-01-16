#include <iostream>
#include <regex>

using namespace std;
int main(){

  string str;
  std::cout << "Enter String" << '\n';

  while(true){
    std::cin >> str;

    //1. regex e("abc"); // match abc
    //regex e("abc", regex_constants::icase); //any case
    //regex e("abc.", regex_constants::icase); //abc ends with any char
    //regex e("abc?"); // zero or one preceding char matched
    //regex e("abc*"); // zero or more preceding char matched
    //regex e("abc+"); // one or more preceding char matched
    //regex e("abc[cd]*"); //[...]any chars inside the sq brackets
    //regex e("abc[^xy]*");  //[...]any chars except inside the sq brackets
    //regex e("abc[^xy]{3}*");  //[...]any chars except inside the sq brackets
                                //exact 3 appreance
    //regex e("abc[^xy]{3,}*");  //[...]any chars except inside the sq brackets
                              // 3  or more appreance
    //regex e("abc[^xy]{3,5}*");  //[...]any chars except inside the sq brackets
                                  // 3 to 5 more appreance
    //regex e("abc|de[fg]");       // | or
    //regex e("(abc)de+\\1");
    //regex e("(abc)dc(xyz)\\2\\1");
    //regex e("[[:w:]]+@[[:w:]]+\.com");

    //bool match = regex_match(str,e);

    //search
    //regex e("abc."); //abc as substirng anywhere
    //regex e("^abc."); //abc as substirng at the begning
    regex e("abc.$"); //abc as substirng at the end


    bool match = regex_search(str,e);

    std::cout << (match? "matched":"Not matched") << '\n';


  }
}
