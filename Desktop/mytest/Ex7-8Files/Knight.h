#pragma once
#include "Piece.h"
#include <string>

class Knight : public Piece {
public:
    Knight(int color) : Piece(color) { this->type = "Knight"; this->hasMoved = false; }
    int isValidMove(std::string curr, std::string dest) override;
    int checkEat(std::string curr, std::string dest) override;
    bool isEmpty() override { return false; }
    bool isKing() override { return false; }
};
