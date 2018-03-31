/*
 * Game.h
 *
 *  Created on: 22 Oct 2016
 *      Author: andrew
 */

#ifndef GAME_H_
#define GAME_H_

#include <mutex>
#include <thread>
#include <vector>
#include <string>


#include "GameBoard.h"

class mainWindow;

class Game
{
	public:
		Game();
		~Game();

		void play_game(mainWindow* caller);
		void stop_game();
		bool has_stopped() const;
		unsigned int get_possible_results_num();
		unsigned int get_result_num();
		GameBoard get_result(unsigned int iNum);

	private:
		std::vector<GameBoard> game_turn(int iSquare, std::vector<GameBoard> vBoard);

		// Synchronizes access to member data.
		mutable std::mutex m_Mutex;

		// Data used by both GUI thread and worker thread.
		bool bShallStop;
		bool bHasStopped;
		unsigned int iPossibleResults;
		std::vector<GameBoard> vGameBoard;
		std::vector<int>vPlaySeq;
};



#endif /* GAME_H_ */
