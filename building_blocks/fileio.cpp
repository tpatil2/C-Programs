#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdio.h>

using namespace std;

int main(int argc, char const *argv[]) {

  string my_str = "I am the theme of my perfect life";

  //open output file if it dosent exists then create it
  ofstream output("myfile.txt");

    if(!output){
      cout<<"Error in opening file"<<endl;
      return -1;
    }else{
      output<<my_str<<endl;
      output.close();
    }

      // Open a stream to append to whats there with ios::app
    	// ios::binary : Treat the file as binary
    	// ios::in : Open a file to read input
    	// ios::trunc : Default
    	// ios::out : Open a file to write output
    	ofstream writer2("myfile.txt", ios::app);

    	if(! writer2){

    		cout << "Error opening file" << endl;

    		// Signal that an error occurred
    		return -1;

    	} else {

    		writer2 << "\n- Yes you are right Tejas" << endl;
    		writer2.close();

    	}


    //read from file
    char letter;
    ifstream read_f ("myfile.txt");

    if(read_f.is_open()) {

      for(int i=0; ! read_f.eof(); i++){
        read_f.get(letter);
        cout<<letter;
      }

      std::cout << "" << std::endl;

      read_f.close();

    }else{
      std::cout << "Error in opening file" << std::endl;
      return -1;
    }

  return 0;
}
