#include <iostream>
#include "player.h"
#include "playerlist.h"

using namespace std;

void Display(Player p) {
  std::cout << "Rank: " <<p.get_rank() << '\n';
  std::cout << "name: " << p.get_name()<<'\n';
  std::cout << "contry: " << p.get_contry()<<'\n';
  std::cout << "rating: " << p.get_rating() <<'\n';
}

int main(){

 //Player p("2	V.Kohli	IND	875");
 Playerlist pl("playerinfo.txt");
for(int i=0;i<pl.players.size();i++){
  Player p = pl.players[i];
   Display(p);
   std::cout << "----------------------" << '\n';
}




  return 0;
}
