#include<iostream>
#include<algorithm>
#include <cstring>


using namespace std;




int main(){

  char text[] = "I am here for all my life";
  char text2[] = "They are here to win us all";

  char *word = strtok(text, " ");

  while (word != NULL) {
    if (strstr(text2, word)) {
        /* Match found */
        printf("Match: %s\n", word);
    }
    word = strtok(NULL, " ");
  }

  return 0;
}
