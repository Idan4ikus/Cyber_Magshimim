#pragma once
#include <string>
#include "Piece.h"
#include "Empty.h"


class Piece; 
class Controller;

class Board {
public:
    Piece* board[8][8];   
    Piece* lastEatedPiece;
    Empty em;
    int currPlayer = 0;

    Board();

    void createboard(std::string board);
    Board UpdateBoard(std::string curr, std::string dest);
	std::string WhereKing(int color);
    Piece* checkpiece(std::string place);
    int converter(char ch);
    bool isCheck(int color, std::string curr, std::string dest);
    int isLegalMove(std::string curr, std::string dest);
    Board undoMove(std::string curr, std::string dest);
    int checkCheck(std::string curr, std::string dest);

};
