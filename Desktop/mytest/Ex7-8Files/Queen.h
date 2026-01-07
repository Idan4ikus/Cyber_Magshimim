#include "Piece.h"
#pragma once

class Queen : public Piece
{
public:
	Queen(int color) : Piece(color) { this->type = "Queen"; this->hasMoved = false; }
	int isValidMove(std::string curr, std::string dest);
	int checkEat(std::string curr, std::string dest);
	bool isEmpty() { return false; }
	bool isKing() { return false; }
};