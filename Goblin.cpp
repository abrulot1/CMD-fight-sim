/********************************************************************
*Program Filename: Goblin.cpp
*Author: Adam Brulotte
*Date: 20 July 15
*Description: implementation file for a goblin class that is a derived class
*				of inhabitant, this will serve as a goblin fighter
*Input: none
*Output: values representative of attack and defense for the goblin
******************************************************************/
#include "Goblin.h"
#include <cstdlib>
#include <iostream>

/*********************************************************************
*Function: Goblin
*Description: user-defined constructor for the Goblin class
*Parameters: none
*Pre-Conditions: creation of a Goblin object
*Post-Conditions: calling of setter functions
*******************************************************************/
Goblin::Goblin()
{
	Goblin::setName("Goblin");
	Goblin::setArmor(3);
	Goblin::setFaces(6);
	Goblin::setHP(8);
	Goblin::setAchilles(true);
}

/*********************************************************************
*Function: Goblin
*Description: user-defined constructor for the Goblin class
*Parameters: string to set the alias to user input
*Pre-Conditions: creation of a Goblin object
*Post-Conditions: calling of setter functions
*******************************************************************/
Goblin::Goblin(std::string goesBy)
{
	Goblin::setName("Goblin");
	Goblin::setAlias(goesBy);
	Goblin::setArmor(3);
	Goblin::setFaces(6);
	Goblin::setHP(8);
	Goblin::setAchilles(true);
}

/*****************************************************************
*Function: setName
*Description: setter function to set the value of protected variable name
*Pre-Conditions: calling of the function with an argument
*Post-Conditions: protected variable name will have a value
************************************************************************/
void Goblin::setName(std::string alias)
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
std::string Goblin::getName()
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
void Goblin::setHP(int h)
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
int Goblin::getHP()
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
void Goblin::setArmor(int a)
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
int Goblin::getArmor()
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
void Goblin::setFaces(int f)
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
int Goblin::getFaces()
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
int Goblin::attRoll()
{
	int counter = 0;
	
	for (int die = 0; die < 2; die++)
	{
		counter += (rand() % getFaces() + 1);
	}

	//if for setting oppenent attack cut
	if (counter == 12)
	{
		setAchilles(false);
		std::cout << "\nCritical Hit!" << std::endl;
		std::cout << "Opponent's attack cut in half for the rest of battle" <<
			"\n(if not battling another goblin)" << std::endl;
	}

	std::cout << "\n**gob att pow: " << counter << std::endl;
	return counter;
}

/*********************************************************************
*Function: defRoll
*Description: function that will simulate rolling of dice with the appropriate
*				number of sides to represent a defence number
*Pre-Conditions: calling of the fucntion from main
*Post-Conditions: return of an integer representing attack power
*********************************************************************/
int Goblin::defRoll()
{
	int defense = (rand() % 6 + 1);
	return defense;
}

/********************************************************************
*Function: setAchilles
*Description: function that will activate the achilles cut if the goblin rolls
*				a 12 roll
*Pre-Conditions: creation of achilles private member variable in parent class
*Post-Conditions: set the value of achilles to true or false
********************************************************************/
void Goblin::setAchilles(bool a)
{
	achilles = a;
}

/************************************************************************
*Function: getAchilles
*Description: will return the status of the achilles modifier for attack
*Pre-Conditions: setting of the achilles variable with a value
*Post-Conditions: value of achilles will be returned to the calling function
**********************************************************************/
bool Goblin::getAchilles()
{
	return achilles;
}

/***************************************************************************
*Function: setAlias
*Description: setter that will set the fighter's alias
*Pre-Conditions: making or the figher object
*Post-Conditions: fighter will have it's alias set
*************************************************************************/
void Goblin::setAlias(std::string al)
{
	alias = al;
}

/******************************************************************
*Function: getAlias
*Description: getter function that will return the objects alias
*Pre-Conditions: setting of the alias and calling of the get function
*Post-Conditions: alias will be returned to the calling function.
**********************************************************************/
std::string Goblin::getAlias()
{
	return alias;
}