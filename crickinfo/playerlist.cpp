#include "playerlist.h"

using namespace std;

Playerlist::Playerlist(string filepath){

  ifstream playerfile(filepath);

  string linecontent;

  while(playerfile.good()){
    getline(playerfile, linecontent);
    if(linecontent != "\0"){
      Player p(linecontent);
      players.push_back(p);
    }
  }
  playerfile.close();

  sort(players.begin(), players.end(),[](Player &p1, Player &p2){
    return p1.get_rating() > p2.get_rating();
  });
}
