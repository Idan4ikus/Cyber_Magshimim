#pragma once
#include <string>
#include "Piece.h"

class King : public Piece
{
public:
	King(int color) : Piece(color) { this->type = "King"; this->hasMoved = false; }
	int isValidMove(std::string curr, std::string dest)override;//Done
	int checkEat(std::string curr, std::string dest)override;
	bool isEmpty() { return false; }
	bool isKing() { return true; }
};