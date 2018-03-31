/*
 * Peice.cpp
 *
 *  Created on: 26 Oct 2016
 *      Author: andrew
 */

#ifndef NDEBUG
	#define DeBug(msg)  std::cout << msg << std::endl
#else
	#define DeBug(msg)
#endif

#include "Piece.h"



Piece::Piece()
{
	iTopLeft = Blank;
	iTopRight = Blank;
	iCentreLeft = Blank;
	iCentreRight = Blank;
	iBottom = Blank;
	bUsed = false;
	iID = -1;
}

//TR CR B CL TL
Piece::Piece(  int  orgiTopRight, int  orgiCentreRight, int  orgiBottom, int  orgiCentreLeft, int orgiTopLeft,
		       bool orgbUsed, int  orgiID,  std::string  orgstringName)
{
	iTopLeft = orgiTopLeft;
	iTopRight =  orgiTopRight;
	iCentreLeft = orgiCentreLeft;
	iCentreRight =  orgiCentreRight;
	iBottom =  orgiBottom;
	iID = orgiID;
	bUsed = orgbUsed;
	stringValue =  orgstringName;
}



Piece::Piece( int  orgiTopRight, int  orgiCentreRight, int  orgiBottom, int  orgiCentreLeft, int orgiTopLeft, int orgiID)
{
	iTopLeft = orgiTopLeft;
	iTopRight =  orgiTopRight;
	iCentreLeft = orgiCentreLeft;
	iCentreRight =  orgiCentreRight;
	iBottom =  orgiBottom;
	iID = orgiID;
	bUsed = false;
}


Piece::Piece(const Piece &oOrginal)
{
	iTopLeft = oOrginal.iTopLeft;
	iTopRight = oOrginal.iTopRight;
	iCentreLeft = oOrginal.iCentreLeft;
	iCentreRight = oOrginal.iCentreRight;
	iBottom = oOrginal.iBottom;
	iID = oOrginal.iID;
	stringValue = oOrginal.stringValue;
	bUsed = oOrginal.bUsed;
}


Piece::~Piece()
{

}

//TR CR B CL TL
std::string Piece::get_colour_code()
{
	std::string stringReturn;

	stringReturn =  (iTopRight!=-1 ?std::to_string(iTopRight):" ");
	stringReturn += (iCentreRight!=-1 ?std::to_string(iCentreRight):" ");
	stringReturn += (iBottom!=-1 ?std::to_string(iBottom):" ");
	stringReturn += (iCentreLeft!=-1 ?std::to_string(iCentreLeft):" ");
	stringReturn += (iTopLeft!=-1 ?std::to_string(iTopLeft):" ");

	DeBug(" Piece::get_colour_code - " + stringReturn);
	return stringReturn;
}



bool Piece::get_status()
{
	return bUsed;
}



void Piece::toggle_status()
{
	bUsed = bUsed?false:true;
}



int Piece::get_id()
{
	return iID;
}



std::string Piece::get_value()
{
	return stringValue;
}


void Piece::set_value(std::string stringNewValue)
{
	stringValue = stringNewValue;
}


void Piece::set_top_left(int iColour)
{
	iTopLeft = iColour;
}


int Piece::get_top_left()
{
	return iTopLeft;
}


void Piece::set_top_right(int iColour)
{
	iTopRight = iColour;
}


int Piece::get_top_right()
{
	return iTopRight;
}


void Piece::set_centre_left(int iColour)
{
	iCentreLeft = iColour;
}


int Piece::get_centre_left()
{
	return iCentreLeft;
}


void Piece::set_centre_right(int iColour)
{
	iCentreRight = iColour;
}


int Piece::get_centre_right()
{
	return iCentreRight;
}


void Piece::set_bottom(int iColour)
{
	iBottom = iColour;
}


int Piece::get_bottom()
{
	return iBottom;
}
