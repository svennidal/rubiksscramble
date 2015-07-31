#include "Moves.h"
#include <iostream>

Moves::Moves()
{
	this->lastMove = "";
	this->front = "F";
	this->back = "B";
	this->up = "U";
	this->down = "D";
	this->left = "L";
	this->right = "R";
	this->Rfront = "F'";
	this->Rback = "B'";
	this->Rup = "U'";
	this->Rdown = "D'";
	this->Rleft = "L'";
	this->Rright = "R'";
}

string Moves::getRandomMove()
{
	srand(time(NULL));
	int turn = rand() % 12 + 1;

	switch(turn){
		case 1:
			return this->front;
			break;
		case 2:
			return this->Rfront;
			break;
		case 3:
			return this->back;
			break;
		case 4:
			return this->Rback;
			break;
		case 5:
			return this->up;
			break;
		case 6:
			return this->Rup;
			break;
		case 7:
			return this->down;
			break;
		case 8:
			return this->Rdown;
			break;
		case 9:
			return this->left;
			break;
		case 10:
			return this->Rleft;
			break;
		case 11:
			return this->right;
			break;
		case 12:
			return this->Rright;
			break;
		default:
			return "error!";
			exit(1);
	}
}

string Moves::getMoves()
{
	string returnMoves = "";
	string currentMove = "";

	int count = 0;
	while(count < 12){
		currentMove = this->getRandomMove();
		if(moveIsOK(currentMove)){ 
			this->lastMove = currentMove;
			returnMoves += currentMove + " "; 
			count++; }
	}
	return returnMoves;
}

bool Moves::moveIsOK(string move)
{
	// if it's the same move we return false
	if(move == this->lastMove){ return false; }

	// if it's a FRONT turn
	else if(move == this->front){
		if(
				this->lastMove == this->back ||
				this->lastMove == this->Rback ||
				this->lastMove == this->Rfront
		  ){ return false; }}
	else if(move == this->Rfront){
		if(
				this->lastMove == this->back ||
				this->lastMove == this->Rback ||
				this->lastMove == this->front
		  ){ return false; }}

	// if it's a BACK turn
	else if(move == this->back){
		if(
				this->lastMove == this->front ||
				this->lastMove == this->Rfront ||
				this->lastMove == this->Rback
		  ){ return false; }}
	else if(move == this->Rback){
		if(
				this->lastMove == this->front ||
				this->lastMove == this->Rfront ||
				this->lastMove == this->back
		  ){ return false; }}

	// if it's a UP turn
	else if(move == this->up){
		if(
				this->lastMove == this->down ||
				this->lastMove == this->Rdown ||
				this->lastMove == this->Rup
		  ){ return false; }}
	if(move == this->Rup){
		if(
				this->lastMove == this->down ||
				this->lastMove == this->Rdown ||
				this->lastMove == this->up
		  ){ return false; }}

	// if it's a DOWN turn
	else if(move == this->down){
		if(
				this->lastMove == this->up ||
				this->lastMove == this->Rup ||
				this->lastMove == this->Rdown
		  ){ return false; }}
	if(move == this->Rdown){
		if(
				this->lastMove == this->up ||
				this->lastMove == this->Rup ||
				this->lastMove == this->down
		  ){ return false; }}
	
	// if it's a LEFT turn
	else if(move == this->left){
		if(
				this->lastMove == this->right ||
				this->lastMove == this->Rright ||
				this->lastMove == this->Rleft
		  ){ return false; }}
	if(move == this->Rleft){
		if(
				this->lastMove == this->right ||
				this->lastMove == this->Rright ||
				this->lastMove == this->left
		  ){ return false; }}

	// if it's a RIGHT turn
	else if(move == this->right){
		if(
				this->lastMove == this->left ||
				this->lastMove == this->Rleft ||
				this->lastMove == this->Rright
		  ){ return false; }}
	if(move == this->Rright){
		if(
				this->lastMove == this->left ||
				this->lastMove == this->Rleft ||
				this->lastMove == this->right
		  ){ return false; }}
	return true;
}

