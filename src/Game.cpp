/*
 * Game.c pp
 *
 *  Created on: 22 Oct 2016
 *      Author: andrew
 */

#include "Game.h"
#include "mainWindow.h"
#include <iostream>
#include <string>

#ifndef NDEBUG
	#define DeBug(msg)  std::cout << msg << std::endl
#else
	#define DeBug(msg)
#endif

Game::Game()
{
	bHasStopped = false;
	bShallStop = false;
	iPossibleResults =0;
	vPlaySeq={18,21,20,19,17,15,16,13,11,14,12,10,8,9,7,6,5,2,1,4,3};
}

Game::~Game()
{
}



void Game::play_game(mainWindow* caller)
{
	try
	{
		DeBug("Game::play_game - Start");

		if (!bShallStop)
		{
			DeBug("Game::play_game - running");
			std::vector<GameBoard> vGameInPlay;

			{
				std::lock_guard<std::mutex> lock(m_Mutex);
				vGameBoard.empty();  //clear old results
				iPossibleResults = vGameInPlay.size();
			}


			for(auto seq : vPlaySeq)
			{
				DeBug("Game::play_game - Square " <<seq );
				vGameInPlay = game_turn(seq, vGameInPlay);
				int iSize = vGameInPlay.size();
				DeBug("Game::play_game - vGameInPlay.size() "<<iSize);

				{
					std::lock_guard<std::mutex> lock(m_Mutex);
					iPossibleResults = iSize;

					//check for hand brake
					if (bShallStop)
					{
						DeBug("Game::play_game - Hand Brake STOP");
						break; ///exit for loop
					}
				}

				caller->notify();
			}


			{
				std::lock_guard<std::mutex> lock(m_Mutex);
				vGameBoard = vGameInPlay;
				iPossibleResults = vGameInPlay.size();
			}
		}

		DeBug("Game::play_game - stopping");
		{
			std::lock_guard<std::mutex> lock(m_Mutex);
			bShallStop = false;
			bHasStopped = true;
		}
		caller->notify();


		DeBug("Game::play_game - End");
	}
	catch(const std::exception& e)
	{
		DeBug("Game::play_game - ERROR " << e.what());
	}
}


void Game::stop_game()
{
	DeBug("Game::stop_game - Start");
	std::lock_guard<std::mutex> lock(m_Mutex);
	bShallStop = true;
}



bool Game::has_stopped() const
{
	DeBug("Game::has_stopped - Start");
	std::lock_guard<std::mutex> lock(m_Mutex);
	return bHasStopped;
}



unsigned int Game::get_result_num()
{
	DeBug("Game::get_result_num");
	std::lock_guard<std::mutex> lock(m_Mutex);
	int iSize = vGameBoard.size();
	DeBug("get_result_num - size " <<iSize);
	return iSize;
}



GameBoard Game::get_result(unsigned int iNum)
{
	try
	{
		DeBug("Game::get_result - START " << iNum);
		GameBoard oResult;
		std::lock_guard<std::mutex> lock(m_Mutex);

		if (iNum<=vGameBoard.size()) oResult = vGameBoard[iNum];

		DeBug("Game::get_result - END");

		return oResult;
	}
	catch(const std::exception& e)
	{
		DeBug("Game::get_result - ERROR " << e.what());
		GameBoard oResult;
		return  oResult; //return empty vector
	}
}



unsigned int Game::get_possible_results_num()
{
	std::lock_guard<std::mutex> lock(m_Mutex);
	DeBug("get_possible_results_num" << iPossibleResults);
	return iPossibleResults;
}



std::vector<GameBoard> Game::game_turn(int iSquare, std::vector<GameBoard> vBoard)
{
	try
	{
		DeBug("Game::game_turn  - Start iSquare " << iSquare);
		std::vector<GameBoard> vReturn;

		//check if new game
		if(vBoard.size()==0)
		{
			DeBug("Game::game_turn  - New game ");
			GameBoard newGame;
			vReturn = newGame.game_move(iSquare);
		}
		else
		{
			for( auto i : vBoard )
			{
				DeBug("Game::game_turn  -Next Square ");
				std::vector<GameBoard> vTemp;
				vTemp = i.game_move(iSquare);
				vReturn.insert(vReturn.end(), vTemp.begin(), vTemp.end());
			}
		}

		DeBug("Game::game_turn  - End");
		return vReturn;
	}
	catch(const std::exception& e)
	{
		DeBug("Game::game_turn - ERROR " << e.what());
		std::vector<GameBoard> vReturn;
		return  vReturn; //return empty vector
	}
}




