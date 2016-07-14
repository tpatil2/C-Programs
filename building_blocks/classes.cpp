#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Player
{

// private variables are only available to methods in the class
private:
	int odi;
	int test;
	string name;

	// A static variable shares the same value with every object in the class
	static int numOfPlayers;

// Public variables can be accessed by anything with access to the object
public:
	int getOdi(){return odi;}
	int getTest(){return test;}
	string getName(){return name;}
	void setOdi(int od){ odi = od; }
	void setTest(int te){ test = te; }
	void setName(string plrname){ name = plrname; }

	// Declared as a prototype
	void setAll(int, int, string);

	// Declare the constructor
	Player(int, int, string);

	// Declare the deconstructor
	~Player();

	// An overloaded constructor called when no data is passed
	Player();

	// protected members are available to members of the same class and
	// sub classes

	// Static methods aren't attached to an object and can only access
	// static member variables
	static int getNumOfPlayers() { return numOfPlayers; }

	// This method will be overwritten in Dog
	void toString();

};

int Player::numOfPlayers = 0;

// Define the protoype method setAll
void Player::setAll(int odi, int test, string name){

	// This is used to refer to an object created of this class type
	this -> odi = odi;
	this -> test = test;
	this -> name = name;
	Player::numOfPlayers++;

}

// A constructor is called when an object is created
Player::Player(int odi, int test, string name) {

	this -> odi = odi;
	this -> test = test;
	this -> name = name;

}

// The destructor is called when an object is destroyed
Player::~Player() {

	cout << "Player " << this -> name << " destroyed" << endl;

}

// A constructor called when no attributes are passed
Player::Player() {
	numOfPlayers++;
}

// This method prints object info to screen and will be overwritten
void Player::toString(){

	cout << this -> name << " Played " << this -> odi << " odi matches and "
		<< this -> test << " matches" << endl;

}

// We can inherit the variables and methods of other classes
class Bowler : public Player{

	private:
		string type = "spinner";
	public:
		void getType() { cout << type << endl; }

		// Declare the constructor
		Bowler(int, int, string, string);

		// Declare the default constructor and call the default superclass
		// constructor
		Bowler() : Player(){};

		// Overwrite toString
		void toString();

};

// Dog constructor passes the right attributes to the superclass
// constructor and then handles the attribute bark that remains
Bowler::Bowler(int odi, int test, string name, string types) :
Player(odi, test, name){

	this -> type = types;

}

// toString method overwritten
void Bowler::toString(){

	// Because the attributes were private in Animal they must be retrieved
	// by called the get methods
	cout << this -> getName() << " played " << this -> getTest() <<
		" test series and he payed  " << this -> getOdi() << " ODI matches and he balls" <<
		this -> type << endl;

}

// ---------- END OF CLASSES ----------
// ---------- CLASSES & OBJECTS ----------
	// Classes are the blueprints for modeling real world objects
	// Real world objects have attributes, classes have members / variables
	// Real world objects have abilities, classes have methods / functions
	// Classes believe in hiding data (encapsulation) from outside code

int main(){
	// Declare a Animal type object
	Player virat;

	// Set the values for the Animal
	virat.setOdi(33);
	virat.setTest(10);
	virat.setName("Virat Kohali");

	// Get the values for the Animal
	cout << virat.getName() << " Played " << virat.getOdi() << " Matches and "
		<< virat.getTest() << " Test series" << endl;

	virat.setAll(34, 12, "virat");

  cout << virat.getName() << " Played " << virat.getOdi() << " Matches and "
    << virat.getTest() << " Test series" << endl;

	// Creating an object using the constructor
	Player yuvi(36, 15, "Yuvraj Singh");

  cout << yuvi.getName() << " Played " << yuvi.getOdi() << " Matches and "
    << yuvi.getTest() << " Test series" << endl;

	// Demonstrate the inheriting class Dog
	Bowler bumra(38, 16, "Bumra", "spinner 1");

	// static methods are called by using the class name and the scope operator
	cout << "Number of Players " << Player::getNumOfPlayers() << endl;

	bumra.getType();

	// Test the toString method that will be overwritten
	virat.toString();
	bumra.toString();

	// We can call the superclass version of a method with the class name
	// and the scope operator
	bumra.Player::toString();

	// When a function finishes it must return an integer value
	// Zero means that the function ended with success
	return 0;
}
