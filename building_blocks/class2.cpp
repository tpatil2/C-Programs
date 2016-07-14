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

     void toString();

     static int getnumOfGames(){ return numbersOfGames;}

};


class ipl : public game{

private:
    int payment;

public:

    void set_payment(int paym){ payment=paym;}
    int get_payment(){return payment;}

    //constructor
    ipl(string ,int , string , int );
    ipl():game(){};

    //overwritten method
    void toString();


};


ipl::ipl(string name, int plyr, string typ,int payment):game( name,plyr,typ){

  this->payment=payment;
  

}

void ipl::toString() {

  cout<<"The game played is "<< this->get_name() <<" and it has total"
  << this->get_players() <<" players and this game is of type " <<
  this->get_type() <<"got payment of Rs. "<< this->payment<<endl;
}


int game::numbersOfGames=0;

game::game(string name, int plyr ,string typ){

    this->name=name;
    this->players=plyr;
    this->type=typ;

    this->numbersOfGames++;

}

game::~game(){
  std::cout << "End of program "<< this->name<< " is destroyed" << std::endl;
}

game::game(){

  this->numbersOfGames++;


}
void game::toString() {

  cout<<"The game played is "<< this->name <<" and it has total"
  << this->players <<" players and this game is of type " <<
  this->type <<endl;
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

  game hockey;

  hockey.set_name("Pune");
  hockey.set_players(12);
  hockey.set_type("outdoor");

  cout<<"The game played in "<< hockey.get_name()<<" and it has total "
  << hockey.get_players()<<" players and this game is of type " <<
  hockey.get_type()<<endl;

  cricket.toString();
  cout<<"number of games are "<< cricket.getnumOfGames()<<endl;

  ipl delhi("Dare devils", 15 ,"stedium", 99999);

  delhi.toString();


  return 0;
}
