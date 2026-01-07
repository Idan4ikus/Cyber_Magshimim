#include "Piece.h"
#pragma once

class TheRook : public Piece
{
public:
	TheRook(int color) : Piece(color) { this->type = "Rook"; this->hasMoved = false; }
	int isValidMove(std::string curr, std::string dest);
	int checkEat(std::string curr, std::string dest);
	bool isEmpty() override { return false; }
	bool isKing() override { return false; }
};