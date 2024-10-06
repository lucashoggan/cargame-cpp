#include <algorithm>
#include <iostream>
#include <string>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <format>

using std::string;

const string VERSION = "1.0.0";
int count = 0;

class Player {
	public:
		Player(int _carHP, int _money) {
			carHP = _carHP;
			money = _money;
		}

		int carHP;
		int money;
		double racerMargin = 0.1;


		int getOppMin() {
			return (int)(carHP - ((double)carHP * racerMargin));
		}

		int getOppMax() {
			return (int)(carHP + ((double)carHP * racerMargin));
		}

		int getOppHP() {
			int minHP = getOppMin();
			int maxHP = getOppMax();

			return randInt(minHP, maxHP);
		}

		int pairRace(int bet=100) {
			int oppHP = getOppHP();
			if (oppHP > carHP) {
				money -= bet;
				return 0;
			}
			else {
				money += bet;
				return 1;
			}
		}
		
};

string getLineInput(string prefix) {
	string in;
	std::cout << prefix << "";
	std::getline(std::cin, in);
	count++;
	return in;
}


int randInt(int _min, int _max) {
	
	return (int)((std::rand() % (_max - _min + 1) + _min));

}

int* getRacerMinMaxHP(int carHP, double margins) {
	int minMar = carHP - ((double) carHP * margins);
	int maxMar = carHP + ((double)carHP * margins);
	int return_arr[2] = { minMar, maxMar };
	return return_arr;
}

int validIntInput(string prefix, int _min, int _max, string err_msg="") {
	int input;
	std::cout << prefix;
	std::cin >> input;
	while (_min > input || input > _max) {
		if (err_msg != "") {
			std::cout << err_msg << std::endl;
		}
		std::cout << prefix;
		std::cin >> input;
	}
	std::cin.ignore();
	return input;
}

void setupRand() { std::srand(std::time(0)); }



char asciiToLower(char in) {
	if (in <= 'Z' && in >= 'A') {
		return in - ('Z' - 'z');
	}
	return in;
}

string strLower(string in) {
	string _in = in;
	std::transform(_in.begin(), _in.end(), _in.begin(), asciiToLower);
	return _in;
}

void onInit() {
	setupRand();
	std::cout << "CarGame C++ v" << VERSION << std::endl;
}

int main() {

	onInit();

	bool running = true;
	string action;
	Player player(100, 1000);
	int bet;
	int result;
	string moneyStr;

	

	while (running) {
		moneyStr = std::to_string(player.money);
		action = strLower(getLineInput("$" + moneyStr + " : "));
		

		if (action == "race") {
			bet = validIntInput("Race Bet>", 1, 100000, "Bet Needs to be Between 1 and 100,000");
			result = player.pairRace(bet);
			if (result == 0) {
				std::cout << "Opponent Won, You've lost $" << bet << std::endl;
			}
			else {
				std::cout << "Opponent Lost, You've won $" << bet << std::endl;
			}

		}

		if (action == "quit") {
			running = false;
		}
	}


	return 0;
}