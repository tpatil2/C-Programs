#include <iostream>
#include <fstream>

using namespace std;

class game
{

private:
    string name;
    int players;
    string type;

    static int numbersOfGames;

public:

    string get_name(){ return name;}
    int get_players(){ return players;}
    string get_type(){ return type;}

    void set_name(string play){ name = play; }
    void set_players(int num){ players = num;}
    void set_type(string typ){ type = typ; }

    //constructor Declared
    game(string, int ,string);
    //destructor
    ~game();
    //default constructor
     game();

};

int game::numbersOfGames=0;

game::game(string name, int plyr ,string typ){

    this->name=name;
    this->players=plyr;
    this->type=typ;
}

game::~game(){
  std::cout << "End of program "<< this->name<< " is destroyed" << std::endl;
}

game::game(){

  this->numbersOfGames++;


}

int main(){

  game cricket;

  cricket.set_name("India");
  cricket.set_players(11);
  cricket.set_type("outdoor");

  cout<<"The game played in "<< cricket.get_name()<<" and it has total "
  << cricket.get_players()<<" players and this game is of type " <<
  cricket.get_type()<<endl;

  game chess("Chess",1,"indoor game");

  cout<<"The game played is "<< chess.get_name()<<" and it has total"
  << chess.get_players()<<" players and this game is of type " <<
  chess.get_type()<<endl;


  return 0;
}
