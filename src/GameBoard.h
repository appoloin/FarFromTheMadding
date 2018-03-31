/*
 * GameBorad.h
 *
 *  Created on: 22 Oct 2016
 *      Author: andrew
 */

#ifndef GAMEBOARD_H_
#define GAMEBOARD_H_

#include <vector>
#include <string>
#include <iostream>

#include "Piece.h"


class GameBoard
{
	public:
		GameBoard();
		GameBoard( const GameBoard &);
		~GameBoard();
		GameBoard & operator=( const  GameBoard &);

		std::vector<GameBoard> game_move(unsigned int iSquare =1);
		bool make_move(int iSquare, Piece oData );
		std::string get_game_result_string();
		std::vector<std::string> get_game_result();
		std::vector<Piece> get_sqaures();


	private:
		std::vector <Piece> find_moves(unsigned int iSqaure);
		void update_board(int iSqaureID);

		enum colours{Blank=-1, Blue = 1, Red = 2, Green = 3};
		enum face{TopRight =0, CentreRight=1, Bottom=2, CentreLeft=3, TopLeft=4};
		std::vector<Piece> vBoardSqaures;
		std::vector<Piece> vGamePieces;
};

#endif /* GAMEBOARD_H_ */
