// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <iostream>
#include <bitset>
#include <string>

using namespace std;

int solution(int N) {

    if(N < 1)
     return -1;

    int maxlen = 0;
    int currlen = 0;

    bool binGapStart = false;
    bool gapZeroes = false;

    while(N >= 1) {
            if(N%2 == 1) {
                binGapStart = binGapStart && gapZeroes;
                if(binGapStart) {
                    maxlen = (maxlen > currlen)? maxlen:currlen;
                    gapZeroes = false;
                    currlen = 0;
                }
                else
                    binGapStart = true;
            }
            else{
                gapZeroes = binGapStart;
                if(gapZeroes)
                    currlen++;
            }
            N = N/2;
        }
        return maxlen;
}


int main()
{

    std::cout << "lenght is"<< solution(1041) << std::endl;

    return 0;
}
