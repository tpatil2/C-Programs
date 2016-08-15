/*A DNA sequence can be represented as a string consisting of the letters A, C, G and T, which correspond to the types of successive nucleotides in the sequence. Each nucleotide has an impact factor, which is an integer. Nucleotides of types A, C, G and T have impact factors of 1, 2, 3 and 4, respectively. You are going to answer several queries of the form: What is the minimal impact factor of nucleotides contained in a particular part of the given DNA sequence?

The DNA sequence is given as a non-empty string S = S[0]S[1]...S[N-1] consisting of N characters. There are M queries, which are given in non-empty arrays P and Q, each consisting of M integers. The K-th query (0 ≤ K < M) requires you to find the minimal impact factor of nucleotides contained in the DNA sequence between positions P[K] and Q[K] (inclusive).

For example, consider string S = CAGCCTA and arrays P, Q such that:
    P[0] = 2    Q[0] = 4
    P[1] = 5    Q[1] = 5
    P[2] = 0    Q[2] = 6

The answers to these M = 3 queries are as follows:

        The part of the DNA between positions 2 and 4 contains nucleotides G and C (twice), whose impact factors are 3 and 2 respectively, so the answer is 2.
        The part between positions 5 and 5 contains a single nucleotide T, whose impact factor is 4, so the answer is 4.
        The part between positions 0 and 6 (the whole string) contains all nucleotides, in particular nucleotide A whose impact factor is 1, so the answer is 1.

Write a function:

    vector<int> solution(string &S, vector<int> &P, vector<int> &Q);

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    // write your code in C++11 (g++ 4.8.2)
    vector<int> R;

    int Min=4;
    //  string S = "CAGCCTA";
    //              0123456
    for(unsigned int i=0;i<P.size();i++){

          string temp = S.substr(P[i],Q[i]-P[i]+1);
          sort(temp.begin(),temp.end());

          if(temp[0]=='A') R.push_back(1);
          else if(temp[0]=='C') R.push_back(2);
          else if(temp[0]=='G') R.push_back(3);
          else if(temp[0]=='T') R.push_back(4);
        }

    return R;
}

int main(){
  string S = "CAGCCTA";
  vector<int> P ={2,5,0};
  vector<int> Q ={4,5,6};
  vector<int> result;

  result=solution(S,P,Q);

  for(int i:result){
    std::cout << i <<" ";
  }

  std::cout << std::endl;






  return 0;
}
