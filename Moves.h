#ifndef MOVES_H
#define MOVES_H
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Moves {
	public:
		Moves();
		string getMoves();
	private:
		string getRandomMove();
		bool moveIsOK(string move);

		string front;
		string back;
		string up;
		string down;
		string left;
		string right;
		string Rfront;
		string Rback;
		string Rup;
		string Rdown;
		string Rleft;
		string Rright;
		
		string lastMove;
};

#endif
