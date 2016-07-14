#include <iostream>

using namespace std;

class Game{

public:
    void get_game(){ std::cout << "I am in Game base" << std::endl;}
    virtual void get_class(){ std::cout << "I am in animal class" << std::endl;}

};

class Art : public Game{

public:
  void get_class(){ std::cout << "I am in Art class" << std::endl;}
};

void what_is_myClass(Game *gm){

    gm->get_class();
}

int main(){

  Game *game = new Game;
  Art *art = new Art;

  game->get_class();
  art->get_class();

  what_is_myClass(game);
  what_is_myClass(art);


  return 0;

}
