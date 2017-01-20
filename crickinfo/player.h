#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Player{

public:

  Player(string player_information);

  string get_name();
  string get_contry();
  double get_rating();
  int get_rank();

private:
  int rank;
  string name;
  string contry;
  double rating;

};
#endif
