#ifndef PLAYERLIST_H
#define PLAYERLIST_H
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include "player.h"

using namespace std;

class Playerlist{

public:
  Playerlist(string filepath);

//private:
  vector<Player> players;
};


#endif
