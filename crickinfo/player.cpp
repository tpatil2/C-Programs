#include "player.h"

using namespace std;

Player::Player(string player_information){

  stringstream playerinfo(player_information);

  playerinfo >> rank;
  playerinfo >> name;
  playerinfo >> contry;
  playerinfo >> rating;
}

int Player::get_rank(){
  return rank;
}

string Player::get_name(){
  return name;
}

string Player::get_contry(){
  return contry;
}

double Player::get_rating(){
  return rating;
}
