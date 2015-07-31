#define CATCH_CONFIG_MAIN
#include <iostream>
#include <string>
#include "catch.hpp"
#include "../Moves.h"
using namespace std;

SCENARIO( "Moves to scramble a rubiks cube", "[int]" ){

	GIVEN( "Moves and an string for moves" ){
		Moves moves;
		string newMoves;

		WHEN( "we haven't called getMoves from moves"){

			THEN( "the string should be empty") {
				REQUIRE(newMoves.size() == 0);
			}
		}

		WHEN( "we call getMoves from moves"){
			newMoves = moves.getMoves();
			THEN( "the string should not be empty"){
				REQUIRE(newMoves.size() != 0);
			}
			THEN( "the string should not contain two of the same moves in a row"){
				for(int i = 0; i < newMoves.size() - 2; i++){
					REQUIRE( newMoves.substr(i, 2) != newMoves.substr(i + 2, 2) );
				}
			}
		}
		
	}
}
	
