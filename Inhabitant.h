/******************************************************************
*Program Filename: Inhabitant.h
*Author: Adam Brulotte
*Date: 19 July 15
*Description: header file for an abtract base class inhabitant.
*Input: none
*Output: none
**********************************************************************/
#ifndef INHABITANT_H
#define INHABITANT_H
#include <string>
class Inhabitant
{
	protected:
		int strength;
		int armor;
		int faces;
		std::string name;
		bool achilles;
		std::string alias;

	public:
		virtual void setAlias(std::string) = 0;
		virtual std::string getAlias() = 0;
		virtual void setName(std::string) = 0;
		virtual std::string getName() = 0;
		virtual void setHP(int) = 0;
		virtual int getHP() = 0;
		virtual void setArmor(int) = 0;
		virtual int getArmor() = 0;
		virtual void setFaces(int) = 0;
		virtual int getFaces() = 0;
		virtual int attRoll() = 0;
		virtual int defRoll() = 0;
		virtual void setAchilles(bool) = 0;
		virtual bool getAchilles() = 0;
};
#endif