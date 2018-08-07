/**********************************************************************
*Program Filename: Reptile.h
*Author: Adam Brulotte
*Date: 19 July 15
*Description: Header file for a reptile class that is derived from an 
*				inhabitant class.
*Input: none
*Output: none
*********************************************************************/
#ifndef REPTILE_H
#define REPTILE_H
#include"Inhabitant.h"

class Reptile : public Inhabitant
{
	public:
		Reptile();
		Reptile(std::string);
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