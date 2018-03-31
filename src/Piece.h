/*
 * Peice.h
 *
 *  Created on: 26 Oct 2016
 *      Author: andrew
 */

#ifndef PIECE_H_
#define PIECE_H_

#include <string>
#include <iostream>


class Piece
{
	public:
		Piece();
		Piece(const Piece &);
		Piece(  int  iTopRight,
			    int  iCentreRight,
			    int  iBottom,
				int  iCentreLeft,
				int  iTopLeft ,
				bool bUsed,
			    int  iID,
			    std::string  stringName);

		Piece(  int  iTopRight,
				int  iCentreRight,
				int  iBottom,
				int  iCentreLeft,
				int  iTopLeft ,
				int  iID);

		~Piece();

		bool get_status();
		void toggle_status();

		std::string get_value();
		void set_value(std::string);

		int get_id();

		std::string get_colour_code();

		void set_top_left(int iColour);
		int get_top_left();
		void set_top_right(int iColour);
		int get_top_right();
		void set_centre_left(int iColour);
		int get_centre_left();
		void set_centre_right(int iColour);
		int get_centre_right();
		void set_bottom(int iColour);
		int get_bottom();


	public:
		enum colours{Blank=-1, Blue = 1, Red = 2, Green = 3};

	private:
		int iID;
		std::string stringValue;
		int iTopLeft;
		int iTopRight;
		int iCentreLeft;
		int iCentreRight;
		int iBottom;
		bool bUsed;
};


#endif /* PIECE_H_ */
