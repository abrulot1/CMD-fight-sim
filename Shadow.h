/***************************************************************
*Program Filename: Shadow.h
*Author: Adam Brulotte
*Date: 19 July 15
*Description: header file for a shadow classs that is a derived class of
*				inhabitant class, this class will represent a shadow in combat
*Input: none
*Output: none
***********************************************************************/
#include"Inhabitant.h"
#ifndef SHADOW_H
#define SHADOW_H

class Shadow : public Inhabitant
{
	public:
		Shadow();
		Shadow(std::string);
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