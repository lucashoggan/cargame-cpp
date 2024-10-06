#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using std::string;

string getLineInput(string prefix) {
	string in;

	std::cout << prefix;
	std::getline(std::cin, in);

	return in;
}


int randInt(int _min, int _max) {
	
	return (int)((std::rand() % (_max - _min + 1) + _min));

}

void setupRand() { std::srand(std::time(0)); }



int main() {
	/*
	string name = getLineInput("Whats Your Name:");

	std::cout << name << std::endl;*/
	setupRand();
	
	
	for (int i = 0; i < 10; i++) {
		std::cout << randInt(1, 6) << std::endl;
	}
	


	return 0;
}