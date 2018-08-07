/**********************************************************************
*Project Filename: Goblin.h
*Author: Adam Brulotte
*Date: 19 July 15
*Description: Header file for a goblin class that is a child class of 
*				inhabitant and will represent a goblin in combat
*Input: none
*Output: none
********************************************************************/
#include "Inhabitant.h"
#ifndef GOBLIN_H
#define GOBLIN_H

class Goblin : public Inhabitant
{
	public:
		Goblin();
		Goblin(std::string);
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