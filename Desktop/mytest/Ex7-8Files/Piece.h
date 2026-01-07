#pragma once
#include <string>
class Board;

class Piece {
public:
	Piece(int color);

	int color;
	std::string type;
	bool hasMoved;
	std::string pose;
	Board *bd;

	virtual int isValidMove(std::string curr, std::string dest);
	virtual int checkEat(std::string curr, std::string dest);
	virtual bool isEmpty();
	virtual bool isKing();
};