#include "Piece.h"
#pragma once

class Bishop : public Piece
{
public:
	Bishop(int color) : Piece(color) { this->type = "Bishop"; this->hasMoved = false; }
	int isValidMove(std::string curr, std::string dest) override;
	int checkEat(std::string curr, std::string dest) override;
	bool isEmpty() override { return false; }
	bool isKing() override { return false; }
};