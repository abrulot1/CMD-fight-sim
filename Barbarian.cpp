/*********************************************************************
*Program Filename: Barbarian .cpp
*Author: Adam Brulotte
*Date: 19 July 15
*Description: implementation file for a barbarian child class of Inhabitant
*				,this will serve as a representation of a barbarian fighter.
*Input: none
*Output: values representing attack power, defense, and hitpoints.
************************************************************************/
#include "Barbarian.h"
#include<cstdlib>		//to use rand()


/*********************************************************************
*Function: Barbarian
*Description: user-defined constructor for the barbarian class
*Parameters: none
*Pre-Conditions: creation of a barbarian object
*Post-Conditions: calling of setter functions
*******************************************************************/
Barbarian::Barbarian()
{
	Barbarian::setName("Barbarian");
	Barbarian::setAlias("Barb");
	Barbarian::setArmor(0);
	Barbarian::setFaces(6);
	Barbarian::setHP(12);
	Barbarian::setAchilles(true);
}

/*********************************************************************
*Function: Barbarian
*Description: user-defined constructor for the barbarian class
*Parameters: string to set the alias to user input
*Pre-Conditions: creation of a barbarian object
*Post-Conditions: calling of setter functions
*******************************************************************/
Barbarian::Barbarian(std::string goesBy)
{
	Barbarian::setName("Barbarian");
	Barbarian::setAlias(goesBy);
	Barbarian::setArmor(0);
	Barbarian::setFaces(6);
	Barbarian::setHP(12);
	Barbarian::setAchilles(true);
}

/*****************************************************************
*Function: setName
*Description: setter function to set the value of protected variable name
*Pre-Conditions: calling of the function with an argument
*Post-Conditions: protected variable name will have a value
************************************************************************/
void Barbarian::setName(std::string alias)
{
	name = alias;
}

/**********************************************************************
*Function: getName
*Description: getter function that will return the value of variable name
*Paramters: none
*Pre-Conditions: creation of protected member variable name
*Post-Conditions: name will be returned to the calling function
**************************************************************************/
std::string Barbarian::getName()
{
	return name;
}

/***********************************************************************
*Function: setHP
*Description: setter funciton to set value of protected variable strength
*Parameters: integer h
*Pre-Conditions: calling of the function with an argument
*Post-Conditions: protected variable strenght will have a value
************************************************************************/
void Barbarian::setHP(int h)
{
	strength = h;
}

/**********************************************************************
*Function: getHP
*Description: getter function for the protected variabele strength
*Parameters: none
*Pre-Conditions: creation of protected member strength
*Post-Conditions: value of protected variable strength will be returned
**********************************************************************/
int Barbarian::getHP()
{
	return strength;
}

/**********************************************************************
*Function: setArmor
*Description: setter function to set the value of protected member armor
*Parameters: int a
*Pre-Conditions: calling of the function with an argument
*Post-Conditions: variable armor will have the value of the parameter
**********************************************************************/
void Barbarian::setArmor(int a)
{
	armor = a;
}

/**********************************************************************
*Function: getArmor
*Description: getter function for the protected variabele armor
*Parameters: none
*Pre-Conditions: creation of protected member variable armor
*Post-Conditions: value of protected variable armor will be returned
**********************************************************************/
int Barbarian::getArmor()
{
	return armor;
}

/**********************************************************************
*Function: setFaces
*Description: setter function to set the value of protected member faces
*Parameters: int f
*Pre-Conditions: calling of the function with an argument
*Post-Conditions: variable faces will have the value of the parameter
**********************************************************************/
void Barbarian::setFaces(int f)
{
	faces = f;
}

/**********************************************************************
*Function: getFaces
*Description: getter function for the protected variabele faces
*Parameters: none
*Pre-Conditions: creation of protected member variable faces
*Post-Conditions: value of protected variable faces will be returned
**********************************************************************/
int Barbarian::getFaces()
{
	return faces;
}

/********************************************************************
*Funtion: attRoll
*Decription: function that will simulate rolling of dice with the appropriate
*				number of sides for the object type being used
*Paramters: none
*Pre-Conditions: calling of the function from main
*Post-Conditions: return of an integer representing attack power
********************************************************************/
int Barbarian::attRoll()
{
	int counter = 0;

	for (int die = 0; die < 2; die++)
	{
		counter += (rand() % getFaces() + 1);
	}

	return counter;
}

/*********************************************************************
*Function: defRoll
*Description: function that will simulate rolling of dice with the appropriate
*				number of sides to represent a defense number
*Pre-Conditions: calling of the fucntion from main
*Post-Conditions: return of an integer representing attack power
*********************************************************************/
int Barbarian::defRoll()
{
	int defCounter = 0;

	for (int d = 0; d < 2; d++)
	{
		defCounter += (rand() % 6 + 1);
	}

	return defCounter;
}

/********************************************************************
*Function: setAchilles
*Description: function that will activate the achilles cut if the goblin rolls
*				a 12 roll
*Pre-Conditions: creation of achilles private member variable in parent class
*Post-Conditions: set the value of achilles to true or false
********************************************************************/
void Barbarian::setAchilles(bool a)
{
	achilles = a;
}

/************************************************************************
*Function: getAchilles
*Description: will return the status of the achilles modifier for attack
*Pre-Conditions: setting of the achilles variable with a value
*Post-Conditions: value of achilles will be returned to the calling function
**********************************************************************/
bool Barbarian::getAchilles()
{
	return achilles;
}

/***************************************************************************
*Function: setAlias
*Description: setter that will set the fighter's alias
*Pre-Conditions: making or the figher object
*Post-Conditions: fighter will have it's alias set
*************************************************************************/
void Barbarian::setAlias(std::string al)
{
	alias = al;
}

/******************************************************************
*Function: getAlias
*Description: getter function that will return the objects alias
*Pre-Conditions: setting of the alias and calling of the get function
*Post-Conditions: alias will be returned to the calling function.
**********************************************************************/
std::string Barbarian::getAlias()
{
	return alias;
}