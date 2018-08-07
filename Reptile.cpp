/***********************************************************************
*Program Filename: Reptile.cpp
*Author: Adam Brulotte
*Date: 19 July 15
*Description: Implementation file for a reptile class that will represent a 
*				reptile person combatant
*Input: none
*Output: values representing attack power and defense power
*********************************************************************/
#include "Reptile.h"
#include<cstdlib>		//for  rand()

/*********************************************************************
*Function: Reptile
*Description: user-defined constructor for the Reptile class
*Parameters: none
*Pre-Conditions: creation of a Reptile object
*Post-Conditions: calling of setter functions
*******************************************************************/
Reptile::Reptile()
{
	Reptile::setName("Reptile Man");
	Reptile::setArmor(7);
	Reptile::setFaces(6);
	Reptile::setHP(18);
	Reptile::setAchilles(true);
}

/*********************************************************************
*Function: Reptile
*Description: user-defined constructor for the Reptile class
*Parameters: string to set the alias to user input
*Pre-Conditions: creation of a Reptile object
*Post-Conditions: calling of setter functions
*******************************************************************/
Reptile::Reptile(std::string goesBy)
{
	Reptile::setName("Reptile Man");
	Reptile::setAlias(goesBy);
	Reptile::setArmor(7);
	Reptile::setFaces(6);
	Reptile::setHP(18);
	Reptile::setAchilles(true);
}

/*****************************************************************
*Function: setName
*Description: setter function to set the value of protected variable name
*Pre-Conditions: calling of the function with an argument
*Post-Conditions: protected variable name will have a value
************************************************************************/
void Reptile::setName(std::string alias)
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
std::string Reptile::getName()
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
void Reptile::setHP(int h)
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
int Reptile::getHP()
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
void Reptile::setArmor(int a)
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
int Reptile::getArmor()
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
void Reptile::setFaces(int f)
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
int Reptile::getFaces()
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
int Reptile::attRoll()
{
	int counter = 0;

	for (int die = 0; die < 3; die++)
	{
		counter += (rand() % getFaces() + 1);
	}
	std::cout << "\n**rep att: " << counter << std::endl;
	return counter;
}

/*********************************************************************
*Function: defRoll
*Description: function that will simulate rolling of dice with the appropriate
*				number of sides to represent a defence number
*Pre-Conditions: calling of the fucntion from main
*Post-Conditions: return of an integer representing attack power
*********************************************************************/
int Reptile::defRoll()
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
void Reptile::setAchilles(bool a)
{
	achilles = a;
}

/************************************************************************
*Function: getAchilles
*Description: will return the status of the achilles modifier for attack
*Pre-Conditions: setting of the achilles variable with a value
*Post-Conditions: value of achilles will be returned to the calling function
**********************************************************************/
bool Reptile::getAchilles()
{
	return achilles;
}

/***************************************************************************
*Function: setAlias
*Description: setter that will set the fighter's alias
*Pre-Conditions: making or the figher object
*Post-Conditions: fighter will have it's alias set
*************************************************************************/
void Reptile::setAlias(std::string al)
{
	alias = al;
}

/******************************************************************
*Function: getAlias
*Description: getter function that will return the objects alias
*Pre-Conditions: setting of the alias and calling of the get function
*Post-Conditions: alias will be returned to the calling function.
**********************************************************************/
std::string Reptile::getAlias()
{
	return alias;
}