/*******************************************************************
*Program Filename: Shadow.cpp
*Author: Adam Brulotte
*Date: 19 July 15
*Description: Header file for a derived class of Inhabitant that will
*				act as a representative of a shadow figure in combat
*Input: none
*Output: values that represent attack power and defense strength
*************************************************************************/
#include "Shadow.h"
#include <cstdlib>
#include <iostream>

/*********************************************************************
*Function: Shadow
*Description: user-defined constructor for the Shadow class
*Parameters: none
*Pre-Conditions: creation of a Shadow object 
*Post-Conditions: calling of setter functions
*******************************************************************/
Shadow::Shadow()
{
	Shadow::setName("Shadow");
	Shadow::setArmor(0);
	Shadow::setFaces(10);
	Shadow::setHP(12);
	Shadow::setAchilles(true);
}

/*********************************************************************
*Function: Shadow
*Description: user-defined constructor for the Shadow class
*Parameters: string a
*Pre-Conditions: creation of a Shadow object and passing of an alias
*Post-Conditions: calling of setter functions
*******************************************************************/
Shadow::Shadow(std::string a)
{
	Shadow::setAlias(a);
	Shadow::setName("Shadow");
	Shadow::setArmor(0);
	Shadow::setFaces(10);
	Shadow::setHP(12);
	Shadow::setAchilles(true);
}

/*****************************************************************
*Function: setName
*Description: setter function to set the value of protected variable name
*Pre-Conditions: calling of the function with an argument
*Post-Conditions: protected variable name will have a value
************************************************************************/
void Shadow::setName(std::string alias)
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
std::string Shadow::getName()
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
void Shadow::setHP(int h)
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
int Shadow::getHP()
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
void Shadow::setArmor(int a)
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
int Shadow::getArmor()
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
void Shadow::setFaces(int f)
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
int Shadow::getFaces()
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
int Shadow::attRoll()
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
*				number of sides to represent a defence number
*Pre-Conditions: calling of the fucntion from main
*Post-Conditions: return of an integer representing attack power
*********************************************************************/
int Shadow::defRoll()
{
/*
	int defense = (rand() % getFaces() + 1);
	//coin toss for deception defense attribute
	int deception = (rand() % 2 + 1);
	//if for deception defense activation
	if (deception = 1)
	{
		std::cout << getAlias() << ": Tricked you!, I'm over here!" << std::endl;
		defense = 100;
	}
	std::cout << "\n**" << defense << std::endl;
	return defense;
*/
	int defense = 0;	//defense counter

	//coin toss for deception attribute
	int deception = (1 + rand() % 2);

	std::cout << "\n**" << deception << std::endl;
	if(deception == 1)
	{
		std::cout << getAlias() << ": \"Tricked you! I'm over here.\""
			<< std::endl;

		defense += 100;

		std::cout << "\n**" << defense << std::endl;
		return defense;
	}
	else
	{	
		defense += (rand() % 6 + 1);

		std::cout << "\n*d*" << defense << std::endl;
		return defense;
	}
}

/********************************************************************
*Function: setAchilles
*Description: function that will activate the achilles cut if the goblin rolls
*				a 12 roll
*Pre-Conditions: creation of achilles private member variable in parent class
*Post-Conditions: set the value of achilles to true or false
********************************************************************/
void Shadow::setAchilles(bool a)
{
	achilles = a;
}

/************************************************************************
*Function: getAchilles
*Description: will return the status of the achilles modifier for attack
*Pre-Conditions: setting of the achilles variable with a value
*Post-Conditions: value of achilles will be returned to the calling function
**********************************************************************/
bool Shadow::getAchilles()
{
	return achilles;
}

/***************************************************************************
*Function: setAlias
*Description: setter that will set the fighter's alias
*Pre-Conditions: making or the figher object
*Post-Conditions: fighter will have it's alias set
*************************************************************************/
void Shadow::setAlias(std::string al)
{
	alias = al;
}

/******************************************************************
*Function: getAlias
*Description: getter function that will return the objects alias
*Pre-Conditions: setting of the alias and calling of the get function
*Post-Conditions: alias will be returned to the calling function.
**********************************************************************/
std::string Shadow::getAlias()
{
	return alias;
}