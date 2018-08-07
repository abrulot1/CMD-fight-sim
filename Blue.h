/**************************************************************
*Program Filename: Blue.h
*Author: Adam Brulotte
*Date: 19 July 15
*Description: header file for a derived class of Inhabitant that will act as
*				a representation of a blue man fighter.
*Input: none
*Output: none
******************************************************************/
#include "Inhabitant.h"
#ifndef BLUE_H
#define BLUE_H

class Blue : public Inhabitant
{
	public:
		Blue();
		Blue(std::string);
		void setAlias(std::string);
		std::string getAlias();
		virtual void setName(std::string);
		virtual std::string getName();
		virtual void setHP(int);
		virtual int getHP();
		virtual void setArmor(int);
		virtual int getArmor();
		virtual void setFaces(int);
		virtual int getFaces();
		virtual int attRoll();
		virtual int defRoll();
		virtual void setAchilles(bool);
		virtual bool getAchilles();


};
#endif