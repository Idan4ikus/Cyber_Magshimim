#pragma once
#include <cmath>
#include "Piece.h"
#include "Pawn.h"
#include "Board.h"
#include <string>

Pawn::Pawn(int color) : Piece(color)
{
    this->hasMoved = false;
	this->type = "Pawn";
}

//int Pawn::isValidMove(std::string curr, std::string dest)
//{
//    if (curr == dest)
//        return 7;
//
//
//    int currRow = '8' - curr[1];
//    int destRow = '8' - dest[1];
//    int currCol = std::tolower(curr[0]) - 'a';
//    int destCol = std::tolower(dest[0]) - 'a';
//
//    int direction = (color == 0) ? 1 : -1;  
//    int rowDiff = destRow - currRow;
//    int colDiff = destCol - currCol;
//
//    if (colDiff == 1 || colDiff == -1)
//        if (rowDiff == direction)
//            return checkEat(curr, dest) ? 0 : 6; 
//
//    if (colDiff != 0)
//        return 6; 
//
//    if (rowDiff == direction)
//    {
//        if (bd->board[destRow][destCol]->isEmpty())
//            return 0;
//        else
//            return 6;
//    }
//
//    if (!hasMoved && rowDiff == 2 * direction)
//    {
//        int intermediateRow = currRow + direction;
//        if (bd->board[intermediateRow][currCol]->isEmpty() && bd->board[destRow][destCol]->isEmpty())
//            return 0;
//        else
//            return 6; 
//    }
//
//    return 6; 
//}


int Pawn::isValidMove(std::string curr, std::string dest)
{
    if (curr.length() != 2 || dest.length() != 2)
        return 6;

    if (curr == dest)
        return 7;

    int currCol = std::tolower(curr[0]) - 'a';
    int destCol = std::tolower(dest[0]) - 'a';

    int currRow = curr[1] - '1';
    int destRow = dest[1] - '1';

    int direction = (color == 0) ? 1 : -1;
    int rowDiff = destRow - currRow;
    int colDiff = destCol - currCol;

    if ((colDiff == 1 || colDiff == -1) && rowDiff == direction)
        return checkEat(curr, dest) ? 0 : 6;

    if (colDiff != 0)
        return 6;

    if (rowDiff == direction)
        return bd->board[destRow][destCol]->isEmpty() ? 0 : 6;

    if (!hasMoved && rowDiff == 2 * direction)
    {
        int midRow = currRow + direction;
        return (bd->board[midRow][currCol]->isEmpty() &&
            bd->board[destRow][destCol]->isEmpty()) ? 0 : 6;
    }

    return 6;
}


int Pawn::checkEat(std::string curr, std::string dest)
{
    int currCol = std::tolower(curr[0]) - 'a';
    int currRow = curr[1] - '1';
    int destCol = std::tolower(dest[0]) - 'a';
    int destRow = dest[1] - '1';

    Piece* target = bd->board[destRow][destCol];
    if (target->isEmpty())
        return 6;

    if (target->color == color)
        return 6; 

    return 0; 
}


