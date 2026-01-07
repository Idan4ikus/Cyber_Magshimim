#pragma once
#include "Board.h"

class Board;

class Controller
{
public:
	Board* bd;
	Controller();
	std::string menageMove(std::string cords);
	std::string convert(std::string dkdkd);
};