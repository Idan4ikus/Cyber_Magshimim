#include "Piece.h"

Piece::Piece(int color)
{
    this->color = color;
}

int Piece::isValidMove(std::string curr, std::string dest)
{
    return 6;
}

int Piece::checkEat(std::string curr, std::string dest)
{
    return 6;
}

bool Piece::isEmpty()
{
    return false;
}

bool Piece::isKing()
{
    return false;
}
