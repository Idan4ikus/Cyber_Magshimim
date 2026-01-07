#pragma once
#include "Piece.h"
#include <string>

class Pawn : public Piece {
public:
	Pawn(int color);
	int isValidMove(std::string curr, std::string dest) override;
	int checkEat(std::string curr, std::string dest) override;
	bool isEmpty() override { return false; }
	bool isKing() override { return false; }

};