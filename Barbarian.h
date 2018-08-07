/***********************************************************************
*Program Filename: Barbarian.h
*Author: Adam Brulotte
*Date: 19 July 15
*Description: header file for a barbarian class that is a child class of 
*				inhabitant class. This class represents a  barbarian fighter
*Input: none
*Output: none
*************************************************************************/
#ifndef BARBARIAN_H
#define BARBARIAN_H
#include "Inhabitant.h"

class Barbarian : public Inhabitant
{
	public:
		Barbarian();
		Barbarian(std::string);
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