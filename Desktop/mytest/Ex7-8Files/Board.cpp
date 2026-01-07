#include "Board.h"
#include "Pawn.h"
#include "TheRook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Empty.h"
#include <iostream>

/// <summary>
/// sets the board at the begining stage
/// </summary>
Board::Board()
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            board[i][j] = new Empty();

    for (int j = 0; j < 8; j++)
    {
        Pawn* wp = new Pawn(0);
        wp->bd = this;
        board[1][j] = wp;

        Pawn* bp = new Pawn(1);
        bp->bd = this;
        board[6][j] = bp;
    }

    Piece* whitePieces[8] =
    {
        new TheRook(0), new Knight(0), new Bishop(0), new Queen(0),
        new King(0), new Bishop(0), new Knight(0), new TheRook(0)
    };
    Piece* blackPieces[8] = 
    {
        new TheRook(1), new Knight(1), new Bishop(1), new Queen(1),
        new King(1), new Bishop(1), new Knight(1), new TheRook(1)
    };

    for (int j = 0; j < 8; j++)
    {
        whitePieces[j]->color = 0;
        whitePieces[j]->hasMoved = false;
        whitePieces[j]->bd = this;
        board[0][j] = whitePieces[j];

        blackPieces[j]->color = 1;
        blackPieces[j]->hasMoved = false;
        blackPieces[j]->bd = this;
        board[7][j] = blackPieces[j];
    }

    this->lastEatedPiece = new Piece(-17);
    //for (int i = 0; i < 8; i++)
    //{
    //    for (int j = 0; j < 8; j++)
    //    {
    //        char c = boardstring[i * 8 + j];

    //        if (c == '#')
    //        {
    //            this->board[i][j] = new Empty();
    //        }
    //        else
    //        {
    //            int color;
    //            if (c >= 'a' && c <= 'z')
    //                color = 1; // black
    //            else
    //                color = 0; // white

    //            switch (tolower(c))
    //            {
    //            case 'p': this->board[i][j] = new Pawn(color);
    //                break;
    //            case 'r': this->board[i][j] = new TheRook(color);
    //                break;
    //            case 'n': this->board[i][j] = new Knight(color);
    //                break;
    //            case 'b': this->board[i][j] = new Bishop(color);
    //                break;
    //            case 'q': this->board[i][j] = new Queen(color);
    //                break;
    //            case 'k': this->board[i][j] = new King(color);
    //                break;
    //            }
    //        }
    //    }
    //}

}

/// <summary>
/// updates the board
/// </summary>
/// <param name="curr"></param>
/// <param name="dest"></param>
/// <returns></returns>
Board Board::UpdateBoard(std::string curr, std::string dest)
{  
	if (isLegalMove(curr, dest) != 0 || isLegalMove(curr, dest) != 1 || isLegalMove(curr, dest) != 2)
		return *this;

	int srcCol = converter(curr[0]);
	int srcRow = curr[1] - '1';
	int dstCol = converter(dest[0]);
	int dstRow = dest[1] - '1';
	Piece* p1 = board[srcRow][srcCol];
	Piece* p2 = board[dstRow][dstCol];
	lastEatedPiece = p2;
	board[dstRow][dstCol] = p1;
	board[srcRow][srcCol] = &em;
	p1->hasMoved = true;
	p1->pose = dest;
	currPlayer = (currPlayer == 0) ? 1 : 0;
	return *this;
}

/// <summary>
/// converts the char to the right int
/// </summary>
/// <param name="ch"></param>
/// <returns></returns>
int Board::converter(char ch)
{
    return (ch) - 'a';
}

/// <summary>
/// cheks which piece is in the place it gets
/// </summary>
/// <param name="place"></param>
/// <returns></returns>
Piece* Board::checkpiece(std::string place)
{
    int col = converter(place[0]);
    int row = place[1] - '1';
    return board[row][col];
}


/// <summary>
/// searches for the king in the color it gets
/// </summary>
/// <param name="color"></param>
/// <returns></returns>
std::string Board::WhereKing(int color)
{
    std::string res = "";
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j]->isKing() && board[i][j]->color == color)
            {
                res += (j + 'a'); 
                res += (i + '1');
                return res;
            }
        }
    }
    return "ti dalbibi";
}

/// <summary>
/// checks if check on the king in the color it gets
/// </summary>
/// <param name="color"></param>
/// <returns></returns>
bool Board::isCheck(int color,std::string curr, std::string dest)
{
    std::string KP = WhereKing(color);
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (!board[i][j]->isEmpty())
            {
                if (board[i][j]->color != color)
                {
                    int ret = (board[i][j]->isValidMove(curr,KP));
                    return ret == 0;

                }
            }
        }
    }
    return false;
}

/// <summary>
/// undoes the last move that happens for checks 
/// </summary>
/// <param name="curr"></param>
/// <param name="dst"></param>
/// <returns></returns>
Board Board::undoMove(std::string curr, std::string dst)
{
    int srcCol = converter(curr[0]);
    int srcRow = curr[1] - '1';
    int dstCol = converter(dst[0]);
    int dstRow = dst[1] - '1';

    Piece* p1 = board[dstRow][dstCol];
    board[srcRow][srcCol] = p1;
    Piece* p2 = lastEatedPiece;
    board[dstRow][dstCol] = p2;
    
    return *this;
}


int Board::isLegalMove(std::string curr, std::string dest)
{
    Piece* dstP = checkpiece(dest);
    Piece* srcP = checkpiece(curr);

    if (srcP->color != currPlayer)
        return 2;

    if (srcP->color == dstP->color)
        return 3;

    int dd = checkCheck(curr, dest);
    if (dd == 0)
    {
         dd = srcP->isValidMove(curr, dest);
    }
        
        
	return dd;
}

int Board::checkCheck(std::string curr, std::string dest)
{
	int color = currPlayer;
	if (isCheck(color,curr, dest))
		return 2;
	color = (color == 0) ? 1 : 0;
	if (isCheck(color, curr, dest))
		return 1;

    return 0;
}

void Board::createboard(std::string boardstring)
{

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            char c = boardstring[i * 8 + j];

            if (c == '#')
            {
                board[i][j] = new Empty();
            }
            else
            {
                int color;
                if (c >= 'a' && c <= 'z')
                    color = 1; // black
                else
                    color = 0; // white

                switch (tolower(c))
                {
                case 'p': board[i][j] = new Pawn(color); 
                    break;
                case 'r': board[i][j] = new TheRook(color); 
                    break;
                case 'n': board[i][j] = new Knight(color); 
                    break;
                case 'b': board[i][j] = new Bishop(color);
                    break;
                case 'q': board[i][j] = new Queen(color);
                    break;
                case 'k': board[i][j] = new King(color);
                    break;
                }
            }
        }
    }

}
