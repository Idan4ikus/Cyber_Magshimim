#pragma once
#include "Piece.h"

class Empty : public Piece {
public:
	Empty() : Piece(-1) { this->type = "Empty"; }

	int isValidMove(std::string curr, std::string dest) ;
	int	checkEat(std::string curr, std::string dest) ;
	bool isEmpty() override { return true; }
	bool isKing() override{ return false; }
};