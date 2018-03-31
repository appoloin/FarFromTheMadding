/*
 * GameBoard.cpp
 *
 *  Created on: 22 Oct 2016
 *      Author: andrew
 */

#ifndef GAMEBOARD_CPP_
#define GAMEBOARD_CPP_

#ifndef NDEBUG
	#define DeBug(msg)  std::cout << msg << std::endl
#else
	#define DeBug(msg)
#endif



#include "GameBoard.h"
#include <boost/regex.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <fstream>





GameBoard::GameBoard()
{
	//top to bottom left to right
	//TR CR B CL TL
	vBoardSqaures.push_back(Piece(Blank,Blank,Red,Red,Blue,false,1,""));
	vBoardSqaures.push_back(Piece(Blank,Blank,Red,Red,Red,false,2,""));
	vBoardSqaures.push_back(Piece(Red,Blank,Blank,Blank,Red,false,3,""));
	vBoardSqaures.push_back(Piece(Blank,Blank,Blank,Blank,Blank,false,4,""));
	vBoardSqaures.push_back(Piece(Blank,Green,Green,Blank,Blank,false,5,""));
	vBoardSqaures.push_back(Piece(Blank,Blank,Blank,Blank,Blank,false,6,""));
	vBoardSqaures.push_back(Piece(Blank,Blank,Green,Blank,Blank,false,7,""));
	vBoardSqaures.push_back(Piece(Blue,Green,Blank,Blank,Green,false,8,""));
	vBoardSqaures.push_back(Piece(Blank,Red,Blank,Blank,Blank,false,9,""));
	vBoardSqaures.push_back(Piece(Red,Blank,Red,Green,Blank,false,10,""));
	vBoardSqaures.push_back(Piece(Blue,Blank,Blue,Blank,Blue,false,11,""));
	vBoardSqaures.push_back(Piece(Blank,Blue,Green,Blank,Blue,false,12,""));
	vBoardSqaures.push_back(Piece(Blank,Blank,Blank,Blue,Blank,false,13,""));
	vBoardSqaures.push_back(Piece(Blank,Blank,Blue,Blank,Blank,false,14,""));
	vBoardSqaures.push_back(Piece(Green,Green,Blank,Blank,Green,false,15,""));
	vBoardSqaures.push_back(Piece(Blank,Blank,Blank,Blank,Blank,false,16,""));
	vBoardSqaures.push_back(Piece(Blank,Blank,Red,Green,Blank,false,17,""));
	vBoardSqaures.push_back(Piece(Green,Blank,Blank,Blank,Red,false,18,""));
	vBoardSqaures.push_back(Piece(Blank,Blank,Blank,Blank,Blank,false,19,""));
	vBoardSqaures.push_back(Piece(Red,Red,Green,Blank,Blank,false,20,""));
	vBoardSqaures.push_back(Piece(Red,Red,Red,Blank,Blank,false,21,""));


	vGamePieces.push_back(Piece(Blue,Red,Red,Red,Green,false,1,"N"));
	vGamePieces.push_back(Piece(Blue,Red,Green,Blue,Blue,false,2,"9"));
	vGamePieces.push_back(Piece(Red,Blue,Green,Green,Blue,false,3,"5"));
	vGamePieces.push_back(Piece(Green,Red,Blue,Green,Blue,false,4,"SP"));
	vGamePieces.push_back(Piece(Red,Blue,Red,Green,Green,false,5,"3"));
	vGamePieces.push_back(Piece(Blue,Green,Green,Blue,Green,false,6,"5"));
	vGamePieces.push_back(Piece(Blue,Blue,Blue,Green,Red,false,7,"1"));
	vGamePieces.push_back(Piece(Blue,Blue,Red,Red,Red,false,8,"5"));
	vGamePieces.push_back(Piece(Green,Green,Green,Green,Red,false,9,"6"));
	vGamePieces.push_back(Piece(Red,Blue,Red,Red,Green,false,10,"SP"));
	vGamePieces.push_back(Piece(Green,Green,Blue,Green,Green,false,11,"SP"));
	vGamePieces.push_back(Piece(Green,Red,Blue,Blue,Green,false,12,"SP"));
	vGamePieces.push_back(Piece(Red,Blue,Red,Green,Red,false,13,"0"));
	vGamePieces.push_back(Piece(Red,Blue,Green,Blue,Blue,false,14,"0"));
	vGamePieces.push_back(Piece(Blue,Green,Red,Red,Red,false,15,"W"));
	vGamePieces.push_back(Piece(Green,Green,Green,Blue,Blue,false,16,"0"));
	vGamePieces.push_back(Piece(Green,Green,Red,Red,Blue,false,17,"4"));
	vGamePieces.push_back(Piece(Red,Blue,Red,Blue,Green,false,18,"3"));
	vGamePieces.push_back(Piece(Green,Blue,Blue,Blue,Blue,false,19,"1"));
	vGamePieces.push_back(Piece(Green,Blue,Green,Blue,Blue,false,20,"4"));
	vGamePieces.push_back(Piece(Red,Red,Red,Green,Green,false,21,"2"));
}



GameBoard::GameBoard( const GameBoard & oOrginal)
{
	vBoardSqaures=oOrginal.vBoardSqaures;
	vGamePieces = oOrginal.vGamePieces;
}



GameBoard & GameBoard::operator=( const  GameBoard & oOrginal)
{
	vBoardSqaures=oOrginal.vBoardSqaures;
	vGamePieces = oOrginal.vGamePieces;
	return *this;
}



GameBoard::~GameBoard()
{
}



std::vector<GameBoard> GameBoard::game_move(unsigned int iSqaure)
{
	try
	{
		DeBug("GameBoard::game_move - Start - sqaure - " << iSqaure );

		std::vector<GameBoard> vReturn;
		if (iSqaure<=vBoardSqaures.size())
		{
			std::vector <Piece> vMoves = find_moves(iSqaure);
			if (vMoves.size()>0)
			{
				for( auto j : vMoves )
				{
					GameBoard oUpdateGameBoard(*this);
					oUpdateGameBoard.make_move(iSqaure, j);
					DeBug("GameBoard::game_move - " << oUpdateGameBoard.get_game_result_string());
					vReturn.push_back(oUpdateGameBoard);
				}
			}
		}
		DeBug("GameBoard::game_move - End");
		return vReturn;
	}
	catch(const std::exception& e)
	{
		DeBug("GameBoard::game_move - ERROR " << e.what());
		std::vector<GameBoard> vReturn;
		return  vReturn; //return empty vector
	}
}



bool GameBoard::make_move(int iSqaure, Piece oData)
{
	try
	{
		DeBug("GameBoard::make_move  - Start - Square "<< iSqaure << " Data ID " << oData.get_id());
		std::string strValue;

		if ((unsigned int) oData.get_id()<=vGamePieces.size())
		{
			vGamePieces[oData.get_id()-1].toggle_status(); // set tile as used;
			strValue = vGamePieces[oData.get_id()-1].get_value();
			DeBug("GameBoard::make_move  - toggled status ");
		}

		if ((unsigned int)iSqaure<=vBoardSqaures.size())// set sqaure with title data
		{
			vBoardSqaures[iSqaure-1].set_value(strValue);
			vBoardSqaures[iSqaure-1].set_top_left(oData.get_top_left());
			vBoardSqaures[iSqaure-1].set_top_right(oData.get_top_right());
			vBoardSqaures[iSqaure-1].set_centre_left(oData.get_centre_left());
			vBoardSqaures[iSqaure-1].set_centre_right(oData.get_centre_right());
			vBoardSqaures[iSqaure-1].set_bottom(oData.get_bottom());

			DeBug("GameBoard::make_move  - set square value " << strValue );
		}

		update_board(iSqaure);

		DeBug("GameBoard::make_move  - END ");
		return true;
	}
	catch(const std::exception& e)
	{
		DeBug("GameBoard::make_move( - ERROR " << e.what());
		return  false;
	}
}



void GameBoard::update_board(int iSquareID)
{
	try
	{
		DeBug("GameBoard::update_board  - Start - Square " << iSquareID);

		//update  squares
		switch(iSquareID)
		{
			case 1://update  SQ3CL=SQ1TR  &  SQ4TL=SQ1CR
				vBoardSqaures[2].set_centre_left(vBoardSqaures[0].get_top_right());
				vBoardSqaures[3].set_top_left(vBoardSqaures[0].get_centre_right());
			break;

			case 2:// SQ4CL=SQ2TR  & SQ5CL=SQ2CR
				vBoardSqaures[3].set_centre_left(vBoardSqaures[1].get_top_right());
				vBoardSqaures[4].set_centre_left(vBoardSqaures[1].get_centre_right());
			break;

			case 3://SQ1TR = SQ3CL & SQ4TR=SQ3B & SQ6TL=SQ3CR
				vBoardSqaures[0].set_top_right(vBoardSqaures[2].get_centre_left());
				vBoardSqaures[3].set_top_right(vBoardSqaures[2].get_bottom());
				vBoardSqaures[5].set_top_left(vBoardSqaures[2].get_centre_right());
			break;

			case 4: // SQ3B=SQ4TR  SQ1CR=SQ4TL  SQ2TR=SQ4CL SQ5TL=SQ4B SQ6CL=SQ4CR
				vBoardSqaures[2].set_bottom(vBoardSqaures[3].get_top_right());
				vBoardSqaures[0].set_centre_right(vBoardSqaures[3].get_top_left());
				vBoardSqaures[1].set_top_right(vBoardSqaures[3].get_centre_left());
				vBoardSqaures[4].set_top_left(vBoardSqaures[3].get_bottom());
				vBoardSqaures[5].set_centre_left(vBoardSqaures[3].get_centre_right());
			break;

			case 5: //SQ4B=SQ5TL SQ2CR=SQ5CL SQ7CL=SQ5TR
				vBoardSqaures[3].set_bottom(vBoardSqaures[4].get_top_left());
				vBoardSqaures[1].set_centre_right(vBoardSqaures[4].get_centre_left());
				vBoardSqaures[6].set_centre_left(vBoardSqaures[4].get_top_right());
			break;

			case 6://SQ3CR=SQ6TL SQ4CR=SQ6CL SQ7TL=SQ6B SQ9CL=SQ6CR SQ8CL=SQ6TR
				vBoardSqaures[2].set_centre_right(vBoardSqaures[5].get_top_left());
				vBoardSqaures[3].set_centre_right(vBoardSqaures[5].get_centre_left());
				vBoardSqaures[6].set_top_left(vBoardSqaures[5].get_bottom());
				vBoardSqaures[8].set_centre_left(vBoardSqaures[5].get_centre_right());
				vBoardSqaures[7].set_centre_left(vBoardSqaures[5].get_top_right());
			break;

			case 7://SQ6B=SQ7TL SQ5TR=SQ7CL SQ9B=SQ7TR SQ10TL=SQ7CR
				vBoardSqaures[5].set_bottom(vBoardSqaures[6].get_top_left());
				vBoardSqaures[4].set_top_right(vBoardSqaures[6].get_centre_left());
				vBoardSqaures[8].set_bottom(vBoardSqaures[6].get_top_right());
				vBoardSqaures[9].set_top_left(vBoardSqaures[6].get_centre_right());
			break;

			case 8: //SQ9TL=SQ8B SQ6TR=SQ8CL
				vBoardSqaures[8].set_top_left(vBoardSqaures[7].get_bottom());
				vBoardSqaures[5].set_top_right(vBoardSqaures[7].get_centre_left());
			break;


			case 9: //SQ8B=SQ9TL SQ6CR=SQ9CL SQ7TR=SQ9B SQ11CL=SQ9TR
				vBoardSqaures[7].set_bottom(vBoardSqaures[8].get_top_left());
				vBoardSqaures[5].set_centre_right(vBoardSqaures[8].get_centre_left());
				vBoardSqaures[6].set_top_right(vBoardSqaures[8].get_bottom());
				vBoardSqaures[10].set_centre_left(vBoardSqaures[8].get_top_right());
			break;


			case 10: //SQ7CR=SQ10TL SQ12CL=SQ10CR
				vBoardSqaures[6].set_centre_right(vBoardSqaures[9].get_top_left());
				vBoardSqaures[11].set_centre_left(vBoardSqaures[9].get_centre_right());
			break;


			case 11: //SQ9TR=SQ11CL SQ13TL=SQ11CR
				vBoardSqaures[8].set_top_right(vBoardSqaures[10].get_centre_left());
				vBoardSqaures[12].set_top_left(vBoardSqaures[10].get_centre_right());
			break;


			case 12: //SQ10CR=SQ12CL SQ14CL=SQ12TR
				vBoardSqaures[9].set_centre_right(vBoardSqaures[11].get_centre_left());
				vBoardSqaures[13].set_centre_left(vBoardSqaures[11].get_top_right());
			break;


			case 13: //SQ11CR=SQ13TL SQ15CL=SQ13TR SQ16CL=SQ13CR SQ14TL=SQ13B
				vBoardSqaures[10].set_centre_right(vBoardSqaures[12].get_top_left());
				vBoardSqaures[14].set_centre_left(vBoardSqaures[12].get_top_right());
				vBoardSqaures[15].set_centre_left(vBoardSqaures[12].get_centre_right());
				vBoardSqaures[13].set_top_left(vBoardSqaures[12].get_bottom());
			break;


			case 14: //	SQ13B=SQ14TL SQ12TR=SQ14CL SQ16B=SQ14TR SQ17TL=SQ14CR
				vBoardSqaures[12].set_bottom(vBoardSqaures[13].get_top_left());
				vBoardSqaures[11].set_top_right(vBoardSqaures[13].get_centre_left());
				vBoardSqaures[15].set_bottom(vBoardSqaures[13].get_top_right());
				vBoardSqaures[16].set_top_left(vBoardSqaures[13].get_centre_right());
			break;

			case 15: // SQ13TR=SQ15CL SQ16TL=SQ15B
				vBoardSqaures[12].set_top_right(vBoardSqaures[14].get_centre_left());
				vBoardSqaures[15].set_top_left(vBoardSqaures[14].get_bottom());
			break;


			case 16: //SQ15B=SQ16TL SQ18CL=SQ16TR SQ19TL=SQ16CR SQ14TR=SQ16B SQ13CR=SQ16CL
				vBoardSqaures[14].set_bottom(vBoardSqaures[15].get_top_left());
				vBoardSqaures[17].set_centre_left(vBoardSqaures[15].get_top_right());
				vBoardSqaures[18].set_top_left(vBoardSqaures[15].get_centre_right());
				vBoardSqaures[13].set_top_right(vBoardSqaures[15].get_bottom());
				vBoardSqaures[12].set_centre_right(vBoardSqaures[15].get_centre_left());
			break;

			case 17: //SQ14CR=SQ17TL SQ19CL=SQ17TR SQ20CL=SQ17CR
				vBoardSqaures[13].set_centre_right(vBoardSqaures[16].get_top_left());
				vBoardSqaures[18].set_centre_left(vBoardSqaures[16].get_top_right());
				vBoardSqaures[19].set_centre_left(vBoardSqaures[16].get_centre_right());
			break;


			case 18: //SQ16TR=SQ18CL SQ21TL=SQ18CR SQ19TR=SQ18B
				vBoardSqaures[15].set_top_right(vBoardSqaures[17].get_centre_left());
				vBoardSqaures[20].set_top_left(vBoardSqaures[17].get_centre_right());
				vBoardSqaures[18].set_top_right(vBoardSqaures[17].get_bottom());
			break;


			case 19: //SQ18B=SQ19TR SQ21CL=SQ19CR SQ20TL=SQ19B SQ17TR=SQ19CL SQ16CR=SQ19TL
				vBoardSqaures[17].set_bottom(vBoardSqaures[18].get_top_right());
				vBoardSqaures[20].set_centre_left(vBoardSqaures[18].get_centre_right());
				vBoardSqaures[19].set_top_left(vBoardSqaures[18].get_bottom());
				vBoardSqaures[16].set_top_right(vBoardSqaures[18].get_centre_left());
				vBoardSqaures[15].set_centre_right(vBoardSqaures[18].get_top_left());
			break;


			case 20: //SQ19B=SQ20TL SQ17CR=SQ20CL
				vBoardSqaures[18].set_bottom(vBoardSqaures[19].get_top_left());
				vBoardSqaures[16].set_centre_right(vBoardSqaures[19].get_centre_left());
			break;

			case 21: //	SQ18CR=SQ21TL SQ19CR=SQ21CL
				vBoardSqaures[17].set_centre_right(vBoardSqaures[20].get_top_left());
				vBoardSqaures[18].set_centre_right(vBoardSqaures[20].get_centre_left());
			break;

		}

		DeBug("GameBoard::update_board  - END ");
	}
	catch(const std::exception& e)
	{
		DeBug("GameBoard::update_board( - ERROR " << e.what());
	}
}



std::vector<Piece> GameBoard::find_moves(unsigned int iSqaure)
{
	try
	{
		DeBug("GameBoard::find_moves- Start - square " <<iSqaure);
		std::vector<Piece> vReturn;
		if(iSqaure<=vBoardSqaures.size())
		{
			//get square colour code
			//ND Squares start at 1 Vector start 0
			std::string strSquareCode = vBoardSqaures[iSqaure-1].get_colour_code();
			//square code = \s?212\s?
			boost::replace_all(strSquareCode, " ", "[0-3]");
			strSquareCode = "("+strSquareCode+")";
			DeBug("GameBoard::find_moves - sqaure code " << strSquareCode);
			boost::regex regExp(strSquareCode); //what to search for
			int iID= 0;

			//get piece code
			for( auto k : vGamePieces )
			{
				if (! k.get_status())//Unused game piece
				{
					//get piece colour code
					std::string strPieceCode = k.get_colour_code();
					//piece code = 23321 = 2332123321
					strPieceCode+=strPieceCode;
					DeBug("GameBoard::find_moves - piece code " << strPieceCode);

					//search for match
					boost::match_results<std::string::const_iterator> match;
					std::string::const_iterator start = strPieceCode.begin();
					std::string::const_iterator end = strPieceCode.end();
					int iPos=0;
					while (boost::regex_search(start,end,match,regExp))
					{
						DeBug("GameBoard::find_moves - Match found");
					    iID = k.get_id();
						std::string::difference_type position = match.position();
						start += position + 1;
						iPos += position + 1;
						if(iPos<6)
						{
							std::string strFound = match.str();
							DeBug("GameBoard::find_moves - position " << iPos << " iID " << iID << " Sting " << strFound);
							vReturn.push_back(Piece(boost::lexical_cast<int>(strFound[TopRight]),
													boost::lexical_cast<int>(strFound[CentreRight]),
													boost::lexical_cast<int>(strFound[Bottom]),
													boost::lexical_cast<int>(strFound[CentreLeft]),
													boost::lexical_cast<int>(strFound[TopLeft]),
												    iID));
						}
					}

				}
			}
		}
		DeBug("GameBoard::find_moves - END");
		return vReturn;
	}
	catch(const std::exception& e)
	{
		DeBug("GameBoard::find_moves - ERROR " << e.what());
		std::vector<Piece> vReturn;
		return  vReturn; //return empty vector
	}
}



std::string GameBoard::get_game_result_string()
{
	try
	{
		DeBug("GameBoard::get_game_result_string - START - ");
		std::string stringResult;

		for( auto L : vBoardSqaures )
		{
			stringResult+=L.get_value();
		}

		DeBug("GameBoard::get_game_result_string - END - " << stringResult);
		return stringResult;
	}
	catch(const std::exception& e)
	{
		DeBug("GameBoard::get_game_result_string - ERROR " << e.what());
		std::string stringResult;
		return stringResult;//return emtpy string
	}
}



std::vector<std::string> GameBoard::get_game_result()
{
	try
	{
		DeBug("GameBoard::get_game_result - Start - ");
		std::vector<std::string> vResult;

		for(auto L : vBoardSqaures)
		{
			vResult.push_back(L.get_value());
		}
		DeBug("GameBoard::get_game_result - END - ");
		return vResult;
	}
	catch(const std::exception& e)
	{
		DeBug("GameBoard::find_moves - ERROR " << e.what());
		std::vector<std::string> vResult;
		return vResult;
	}
}



std::vector<Piece> GameBoard::get_sqaures()
{
	try
	{
		DeBug("GameBoard::get_sqaures - Start - ");
		std::vector<Piece> vResult;

		vResult =vBoardSqaures;

		DeBug("GameBoard::get_sqaures - END - ");
		return vResult;
	}
	catch(const std::exception& e)
	{
		DeBug("GameBoard::get_sqaures - ERROR " << e.what());
		std::vector<Piece> vResult;
		return vResult;
	}
}




#endif /* GAMEBOARD_CPP_ */
