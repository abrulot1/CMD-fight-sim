/************************************************************
*Program Filename: Tmain.cpp
*Author: Adam Brulotte
*Date: 19 July 15
*Description: Main file for a program that will simulate a tournament battle 
*				between teams of user-selected fighters.
*Input: user selection of number of combatants and which team will consist of 
*			which fighters
*Output: First, second, and third place will be displayed along with team 
*			points and winning team
**************************************************************************/
#include<iostream>
#include<cstdlib>
#include<string>
#include<sstream>
#include<ctime>
#include "Barbarian.cpp"
#include "Reptile.cpp"
#include "Blue.cpp"
#include "Shadow.cpp"
#include "Goblin.cpp"
#include "MyQueue.cpp"
#include "MyStack.cpp"





/***************************************************************
*Function: regen
*Description: function that rolls a die to determine health regeneration 
*				after a fighter win
*Parameters: integer with amount of health lost during battle
*Pre-Conditions: winner of a battle must be declared and function called
*Post-Conditions: amount of regenerated health will be passed back to battle
*					function
*******************************************************************/
int regen(int lost)
{
	std::cout << "**in regen" <<std::endl;
	if(lost >= 0)
	{
		return 0;
	}
	else
	{
	std::cout << "\nLost: " << lost << std::endl;
		int gained = (rand() % lost + 1);
		return gained;
	}
}




/***********************************************************************
*Function: battle
*Description: function that will simulate the battle between combatants
*Parameters: pointers to two inhabitant class objects, references to two
*				team queues, reference to a loser stack, reference to 
*				total amount of fighters left, references to team 1 and 
*				team 2 scores.
*Pre-Conditions: creation of inhabitant class objects and calling of this
*					function with pointers to them. creation of 2 queues and
*					one stack, creation of total fighters in the tournament,
*					creation of team 1 & 2 score counters.
*Post-Conditions: this function will display the winner of each battle and
*					place the winner back into their queue with some 
*					regenerated health. Puts the loser in the loser stack
*					and updates fighters left and team scores
***********************************************************************/
void battle(Inhabitant *one, Inhabitant *two, MyQueue &team1, MyQueue &team2,
				MyStack &losers, int &total, int &t1score, int &t2score)
{
	int lostHealth1 = 0;
	int	lostHealth2 = 0;	//amount of health lost in battle
	bool alive = true;		//for victory condition
	do
	{
		//local health variables
		int health1 = one->getHP();
		int health2 = two->getHP();
		int def1, def2;		//holds defensive rolls
		int attack1;
		int	attack2;		//hold attack values
		int damageOne;
		int	damageTwo;		//hold total damage done
		
		if (one->getName() != "Goblin" && two->getName() != "Goblin")
		{
			std::cout << "\n*fight with no goblins" << std::endl;

			if (!one->getAchilles())
			{
				std::cout << "\n**fight if one" << std::endl;
				std::cout << "\n\t\t" << two->getAlias() << " attack!" <<
					std::endl;
				attack2 = (two->attRoll() / 2);
				std::cout << "\n**half att2 " << attack2 <<std::endl;
				def1 = (one->getArmor() + one->defRoll());
				damageOne = (def1 - attack2);
			}
			else if (one->getAchilles())
			{
				std::cout << "\n**fight 1 else if" << std::endl;
				std::cout << "\n\t\t" << two->getAlias() << " attack!" <<
					std::endl;
				attack2 = two->attRoll();
				def1 = (one->getArmor() + one->defRoll());
				damageOne = (def1 - attack2);
			}
			if (!two->getAchilles())
			{
				std::cout << "\n**fight if 2" << std::endl;
				std::cout << "\n\t\t" << one->getAlias() << " strike!" <<
					std::endl;
				attack1 = (one->attRoll() / 2);
				def2 = (two->getArmor() + two->defRoll());
				damageTwo = (def2 - attack1);
			}
			else if (two->getAchilles())
			{
				std::cout << "\n**fight 2 else if" << std::endl;
				std::cout << "\n\t\t" << one->getAlias() << " strike!" <<
					std::endl;
				attack1 = one->attRoll();
				def2 = (two->getArmor() + two->defRoll());
				damageTwo = (def2 - attack1);
			}
		}
		else if ((one->getName() != "Goblin") || (two->getName() != "Goblin"))
		{
			std::cout << "\n*fight with one goblin" << std::endl;	
			if (!one->getAchilles())
			{
				std::cout << "\n**fight if one" << std::endl;
				std::cout << "\n\t\t" << two->getAlias() << " attack!" <<
					std::endl;
				attack2 = (two->attRoll() / 2);
				std::cout << "\n**half att2 " << attack2 <<std::endl;
				def1 = (one->getArmor() + one->defRoll());
				damageOne = (def1 - attack2);
			}
			else if (one->getAchilles())
			{
				std::cout << "\n**fight 1 else if" << std::endl;
				std::cout << "\n\t\t" << two->getAlias() << " attack!" <<
					std::endl;
				attack2 = two->attRoll();
				def1 = (one->getArmor() + one->defRoll());
				damageOne = (def1 - attack2);
			}
			if (!two->getAchilles())
			{
				std::cout << "\n**fight if 2" << std::endl;
				std::cout << "\n\t\t" << one->getAlias() << " strike!" <<
					std::endl;
				attack1 = (one->attRoll() / 2);
				def2 = (two->getArmor() + two->defRoll());
				damageTwo = (def2 - attack1);
			}
			else if (two->getAchilles())
			{
				std::cout << "\n**fight 2 else if" << std::endl;
				std::cout << "\n\t\t" << one->getAlias() << " strike!" <<
					std::endl;
				attack1 = one->attRoll();
				def2 = (two->getArmor() + two->defRoll());
				damageTwo = (def2 - attack1);
			}
		}
		else
		{
			std::cout << "\n***2 goblin battle" << std::endl;	

			//bout between two goblins
			std::cout << "\n\t\t" << two->getAlias() << " strike!" <<
				std::endl;
			attack2 = two->attRoll();
			def1 = (one->getArmor() + one->defRoll());
			std::cout << "\n*def1: " << def1 << std::endl;
			damageOne = (def1 - attack2);
				
			std::cout << "\n\t\t" << one->getAlias() << " strike!" <<
				std::endl;
			attack1 = (one->attRoll());
			def2 = (two->getArmor() + two->defRoll());
			std::cout << "\n*def2: " << def2 << std::endl;
			damageTwo = (def2 - attack1);
		}
		
		//change combatants health
		if (damageOne < 0)
		{
			std::cout << "\n" << one->getAlias() << " " << damageOne <<
				" health" << std::endl;

			//add to team 2 score for hits
			t2score -= damageOne;
			health1 += damageOne;
			one->setHP(health1);
			std::cout << "\n\t" << health1 << " health remains" << std::endl;
			lostHealth1 += damageOne;	//add to health lost
		}
		else
		{
			std::cout << "\nYou can't damage " << one->getAlias() <<
				"!!!!" << std::endl;
		}
		if (damageTwo < 0)
		{
			std::cout << "\n" << two->getAlias() << " " << damageTwo <<
				" health" << std::endl;

			//add to team 1 score for hits
			t1score -= damageTwo;
			health2 += damageTwo;
			two->setHP(health2);
			std::cout << "\n\t" << health2 << " health remains" << std::endl;
			lostHealth2 += damageTwo;	//add to health lost
		}
		else
		{
			std::cout << "\nYou can't damage " << two->getAlias() <<
				"!!!!" << std::endl;
		}
		
		//ifs to determine victory conditions
		if (one->getHP() <= 0 && two->getHP() <= 0)
		{
			std::cout << "\n\nIt appears they are both dead" << std::endl;
			std::cout << "We have a tie!" << std::endl;

			losers.push(one);	//add loser to the stack
			losers.push(two);	//add loser to the stack
			total -= 2;
			alive = false;
		}
		else if (one->getHP() <= 0)
		{
			std::cout << "\n\n" << one->getAlias() << " is dead!" << std::endl;
			std::cout << two->getAlias() << " the " <<two->getName() 
				<< " wins!" << std::endl;
			
			//regenerate health before getting back in the queue
			int heal = regen(lostHealth2);
			std::cout << "**back from regen" <<std::endl;
			two->setHP(two->getHP() + heal);
			std::cout << "\nWinning invigorates me!   + " << heal << "HP" 
				<< std::endl;
			total -= 1;
			std::cout <<"**getting 2 health" << std::endl;
			std::cout << "**" << two->getHP() << std::endl;
			std::cout << "**putting fighter 2 back" << std::endl;
			two->setAchilles(true);	//reset achilles before going back	
			team2.addBack(two);	//put fighter back in queue
			losers.push(one);	//put loser on the stack
			alive = false;
		}
		else if (two->getHP() <= 0)
		{
			std::cout << "\n\n" << two->getAlias() << " is dead!" << std::endl;
			std::cout << one->getAlias() << " the " << one->getName()
				<< " wins!" << std::endl;
			
			//regenerate health before getting back in the queue
			int heal = regen(lostHealth1);	
			std::cout << "**back from regen" << std::endl;
			one->setHP(one->getHP() + heal);
			std::cout << "\nI'm going to take a nap now!   + " << heal << "HP" 
				<< std::endl;
			total -= 1;
			std::cout << "**getting 1 health" <<std::endl;
			std::cout << "**" << one->getHP() << std::endl;
			std::cout << "**putting fighter 1 back" << std::endl;		
			one->setAchilles(true);	//reset achilles before going back
			team1.addBack(one);	//put fighter back in queue
			losers.push(two);	//put loser on the stack
			alive = false;
		}
	} while (alive);
}




int main()
{
	//get random number generator and seed srand with it
	unsigned seed;

	seed = time(0);
	srand(seed);
	
	//create queues and stacks for teams and loser pile
	MyQueue team1q;
	MyQueue team2q;
	MyStack losers;

	//variable to store team scores
	int team1Score = 0;
	int team2Score = 0;

	std::string eName;	//to store the entrant's name

	std::cout << "\nYou: ""I'm here for the Kumite.""" << std::endl;
	std::cout << "Old Man: ""I don't know what you're talking about...""" <<
		std::endl;
	std::cout << "\n\n\nThis is the Galaxy's hardest tournament! Will " <<
		"anyone survive?" << std::endl;
	
	//string for input verification
	std::string verify;

	//integers to store team fighter amounts
	int team1, team2;
	
	std::cout << "\n\n\nHow many fighters should team 1 have:	";
	
	//verify user input is a number
	while (true)
	{
		std::getline(std::cin, verify);

		//convert string to int
		std::stringstream teamVer(verify);
		if (teamVer >> team1)
		{
			break;
		}
		std::cout << "Invalid number, try again" << std::endl;
	}
	std::cout << "\nHow many fighters should team 2 have:	";

	//verify user input is a number
	while (true)
	{
		std::getline(std::cin, verify);

		//convert string to int
		std::stringstream teamVer(verify);
		if (teamVer >> team2)
		{
			break;
		}
		std::cout << "Invalid number, try again" << std::endl;
	}

	//for tournament round loop
	int totalFighters = team1 + team2;

	//for podium finishes
	int originalFighters = team1 + team2;

	//show user how many fighters each team will have
	std::cout << "\n\nTeam 1 will have " << team1 << " fighters";
	std::cout << "\nTeam 2 will have " << team2 << " fighters" << std::endl;

	int fighterChoice;	//for saving fighter choice after verification

	//loop for placing fighters into queues for team 1
	for (int x = 0; x < team1; x++)
	{
		std::cout << "\n\nChoose first team fighter " << (x + 1) << std::endl;
		std::cout << "1. Barbarian" << std::endl;
		std::cout << "2. Reptile Person" << std::endl;
		std::cout << "3. Blue Man" << std::endl;
		std::cout << "4. Shadow" << std::endl;
		std::cout << "5. Goblin" << std::endl;
		std::cout << "6. Run Away!!!!" <<
			std::endl;
	
		//verify input
		while (true)
		{
			std::getline(std::cin, verify);

			//convert to string
			std::stringstream fighterVer(verify);
			if (fighterVer >> fighterChoice)
			{
				break;
			}
			std::cout << "Invalid fighter selection, try again" << std::endl;
		}

		switch (fighterChoice)
		{
			case 1:
			{
				//make new fighter object with name
				std::cout << "\nWhat is the fighter's name?" << std::endl;
				std::getline(std::cin, eName);
				Inhabitant *ptrInhabitant = new Barbarian(eName);
				
				//put new object into queue
				team1q.addBack(ptrInhabitant);

				//test				std::cout << team1q.getFront;
				break;
			}
			case 2:
			{
				//make new fighter object with name
				std::cout << "\nWhat is the fighter's name?" << std::endl;
				std::getline(std::cin, eName);
				Inhabitant *ptrInhabitant = new Reptile(eName);
				
				//put new object into queue
				team1q.addBack(ptrInhabitant);
				break;
			}
			case 3:
			{
				//make new fighter object with name
				std::cout << "\nWhat is the fighter's name?" << std::endl;
				std::getline(std::cin, eName);
				Inhabitant *ptrInhabitant = new Blue(eName);
				
				//put new object into queue
				team1q.addBack(ptrInhabitant);
				break;
			}
			case 4:
			{
				//make new fighter object with name
				std::cout << "\nWhat is the fighter's name?" << std::endl;
				std::getline(std::cin, eName);
				Inhabitant *ptrInhabitant = new Shadow(eName);
				
				//put new object into queue
				team1q.addBack(ptrInhabitant);
				break;
			}
			case 5:
			{
				//make new fighter object with name
				std::cout << "\nWhat is the fighter's name?" << std::endl;
				std::getline(std::cin, eName);
				Inhabitant *ptrInhabitant = new Goblin(eName);
				
				//put new object into queue
				team1q.addBack(ptrInhabitant);
				break;
			}
			case 6:
			{
				return 0;	//quit program
				break;
			}
		}
	}

	//loop for placing fighters into queues
	for (int x = 0; x < team2; x++)
	{
		std::cout << "\n\nChoose second team fighter " << (x + 1) << std::endl;
		std::cout << "1. Barbarian" << std::endl;
		std::cout << "2. Reptile Person" << std::endl;
		std::cout << "3. Blue Man" << std::endl;
		std::cout << "4. Shadow" << std::endl;
		std::cout << "5. Goblin" << std::endl;
		std::cout << "6. Run Away!!!!" <<
			std::endl;

		//verify input
		while (true)
		{
			std::getline(std::cin, verify);

			//convert to string
			std::stringstream fighterVer(verify);
			if (fighterVer >> fighterChoice)
			{
				break;
			}
			std::cout << "Invalid fighter selection, try again" << std::endl;
		}
		switch (fighterChoice)
		{
			case 1:
			{
				//make new fighter object with name
				std::cout << "\nWhat is the fighter's name?" << std::endl;
				std::getline(std::cin, eName);
				Inhabitant *ptrInhabitant = new Barbarian(eName);

				//put new object into queue
				team2q.addBack(ptrInhabitant);

				//test				std::cout << team1q.getFront;
				break;
			}
			case 2:
			{
				//make new fighter object with name
				std::cout << "\nWhat is the fighter's name?" << std::endl;
				std::getline(std::cin, eName);
				Inhabitant *ptrInhabitant = new Reptile(eName);

				//put new object into queue
				team2q.addBack(ptrInhabitant);
				break;
			}
			case 3:
			{
				//make new fighter object with name
				std::cout << "\nWhat is the fighter's name?" << std::endl;
				std::getline(std::cin, eName);
				Inhabitant *ptrInhabitant = new Blue(eName);

				//put new object into queue
				team2q.addBack(ptrInhabitant);
				break;
			}
			case 4:
			{
				//make new fighter object with name
				std::cout << "\nWhat is the fighter's name?" << std::endl;
				std::getline(std::cin, eName);
				Inhabitant *ptrInhabitant = new Shadow(eName);

				//put new object into queue
				team2q.addBack(ptrInhabitant);
				break;
			}
			case 5:
			{
				//make new fighter object with name
				std::cout << "\nWhat is the fighter's name?" << std::endl;
				std::getline(std::cin, eName);
				Inhabitant *ptrInhabitant = new Goblin(eName);
				//put new object into queue
				team2q.addBack(ptrInhabitant);
				break;
			}
			case 6:
			{

				return 0;	//quit program
				break;
			}
		}
	}
	int bout = 1; //counter for tournament round display

	//loop to pull fighters into the battle function and simulate a tournament
	while(totalFighters > 1)
	{
		//fighter variables for passing to battle
		Inhabitant *fighterOne = 0;
		Inhabitant *fighterTwo = 0;


		std::cout << "\n\n\t\t\t*********************************" << std::endl;
		std::cout << "\t\t\t|\tBout " << bout << " starting!\t|\t" << std::endl;
		std::cout << "\t\t\t*********************************" <<
			std::endl << std::endl;;
	
		std::cout << "\nFighers left: " << totalFighters << std::endl;

		if (!team1q.isEmpty() && !team2q.isEmpty())
		{
			std::cout << "\n**neither q is empty" << std::endl;

			//set fighters, and remove them from the queue
			fighterOne = team1q.getFront();
			std::cout << "\n\t\t\t\t   " << fighterOne->getAlias() << " ready!" 
			<< std::endl;
			
			team1q.removeFront();

			fighterTwo = team2q.getFront();
			std::cout << "\n\t\t\t\t   " << fighterTwo->getAlias() << " ready!" 
			<< std::endl;
			
			team2q.removeFront();
		}
		else if (team2q.isEmpty()) //2 queue is empty
		{
			std::cout << "\n**q 2 is empty" << std::endl;
			fighterOne = team1q.getFront();
			std::cout << "\n" << fighterOne->getAlias() << " ready!" <<
				std::endl;
			team1q.removeFront();
			
			fighterTwo = team1q.getFront();
			std::cout << "\n" << fighterTwo->getAlias() << " ready!" <<
				std::endl;
			team1q.removeFront();
		}
		else if (team1q.isEmpty()) //1 queue is empty
		{
			std::cout << "\n**q 1 is empty" << std::endl;
			fighterOne = team2q.getFront();
			std::cout << "\n" << fighterOne->getAlias() << " ready!" <<
				std::endl;
			team2q.removeFront();
			fighterTwo = team2q.getFront();
			std::cout << "\n" << fighterTwo->getAlias() << " ready!" <<
				std::endl;
			team2q.removeFront();
		}
		std::cout << "\n\n\t\t\t\tEntering the arena." << std::endl;
		battle(fighterOne, fighterTwo, team1q, team2q, losers, totalFighters,
				team1Score, team2Score);
		bout++;
	}

	//determine tournament victor and runner-ups
	if(originalFighters == 0)
	{
		std::cout << "\n\n\nIt seems no one wants to die today....." << std::endl;
		std::cout << "Tournament cancelled.\n" << std::endl << std::endl;
	}
	else if (team1q.isEmpty())
	{
		std::cout << "\n\n\n\nWE HAVE A VICTOR!!!!!!!" << std::endl;
		std::cout << "\n\nFrom team 2!!" << std::endl;
	
		Inhabitant *victor = team2q.getFront();

		std::cout << "\nAll hail " << victor->getAlias() << " the " <<
			victor->getName() << "!!!!!!" << std::endl;

		std::cout << "Master of carnage!!!!" << std::endl;

		team2Score += 1;	//one point for winning
	}
	else
	{
		std::cout << "\n\n\n\nWE HAVE A VICTOR!!!!!!!" << std::endl;
		std::cout << "\n\nFrom team 1!!" << std::endl;

		Inhabitant *victor = team1q.getFront();

		std::cout << "\nAll hail " << victor->getAlias() << " the " <<
			victor->getName() << "!!!!!!" << std::endl;

		std::cout << "Master of carnage!!!!" << std::endl;

		team1Score += 1;	//one point for winning
	}	
	if(originalFighters == 1)
	{
		std::cout << "\nLooks like the winner was too much for even one" <<
			" challenger!" << std::endl << std::endl;
	}
	if(originalFighters >= 2)
	{
		Inhabitant *second = losers.peek();

		std::cout << "\n\n\nLast to die (second place)..." << std::endl;
		std::cout << second->getAlias() << " the " << second->getName() <<
			std::endl << std::endl;

		losers.pop();	//take second place of of the stack
	}
	if(originalFighters == 2)
	{
		std::cout << "\nOnly two fighters brave enough for the tournament?"
			<< "\nWhen you think about the danger....You can't blame the others"
			<< std::endl << std::endl;
	}
	if(originalFighters >= 3)
	{
		Inhabitant *third = losers.peek();

		std::cout << "\n\nSo close but not good enough (third place)..." << 
			std::endl;
		std::cout << third->getAlias() << " the " << third->getName() << 
			std::endl << std::endl;
	}
	//team win by points value
	std::cout << "\n\n" << team1Score << std::endl;
	std::cout << "\n\n" << team2Score << std::endl;

	if(team1Score < team2Score)
	{
		std::cout << "\nTeam 2 wins with " << team2Score << " points" << 
			std::endl << std::endl << std::endl;
	}
	else if(team1Score > team2Score)
	{
		std::cout << "\nTeam 1 wins with " << team1Score << " points" <<
			std::endl << std::endl << std::endl;
	}
	else
	{
		std::cout << "\nBoth scores are equal!!!! We have a tie!!!" << 
			std::endl << std::endl << std::endl;
	}
	return 0;
}
