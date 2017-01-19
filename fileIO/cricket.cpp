#include <iostream>
#include <fstream>
using namespace std;

int get_choice(){

  int choice;
  std::cout << "Menu" << '\n';
  std::cout << "Enter 1 for ---Centuries" << '\n';
  std::cout << "Enter 2 for -----Fifties" << '\n';
  std::cout << "Enter 3 for Less than 49" << '\n';
  std::cout << "Enter 4 to ---------Exit" << '\n';

  cin >> choice;
  return choice;
}

void display_score(int x) {

    ifstream ip;
    ip.open("scoreboard.txt");
    if(!ip.is_open()) std::cout << "File Does not exists" << '\n';
    int score;
    string player;

    if(x==1){
        while (ip >> player >>score ) {
            if(score >= 100){
            std::cout << player<< " "<<score<< '\n';
            }
        }
    }
    if(x==2){
        while (ip >> player >>score ) {
            if(score >= 50 && score < 100 ){
            std::cout << player<< " "<<score<< '\n';
            }
        }
    }
    if(x==3){
        while (ip >> player >>score ) {
            if(score < 50){
            std::cout << player<< " "<<score<< '\n';
            }
        }
    }
}

int main(){

  int choice = get_choice();
  while (choice!=4) {

    switch (choice) {
      case 1:
            display_score(1);
            break;
      case 2:
            display_score(2);
            break;
      case 3:
            display_score(3);
            break;
    }
      choice = get_choice();

  }

}
