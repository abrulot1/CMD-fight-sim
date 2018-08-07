/***********************************************************************
*Program Filename: MyStack.cpp
*Author: Adam Brulotte
*Date: 25 July 15
*Description: implementation file for a class that will act as a stack made
*				of a linked list
*Input: integer variables to be stored as data in the nodes
*Output: integers representing the top of the stack
**********************************************************************/
#include "MyStack.h"
#include<iostream>

/*******************************************************************
*Function: push
*Description: function that will create a new node for the linked list and 
*				add it to the top of the list.
*Parameters: integer that will be pushed onto the stack
*Pre-Conditions: calling of the push function from main and creation of the 
*					linked list
*Post-Conditoins:  the top value of the stack will be the value of the 
*					parameter integer
******************************************************************/
void MyStack::push(Inhabitant *loser )
{
	top = new Nodes(loser, top);
}

/*********************************************************************
*Function: pop
*Description: function that will remove the top value from the stack if the	
*				stack contains values, error message otherwise.
*Parameters: reference to the integer value at the top of the stack
*Pre-Conditions: calling of the pop function from main, and linked list node
*					having a value
*Post-Conditions:  the node from the parameter will be taken off of the stack
*********************************************************************/
void MyStack::pop()
{
	Nodes *temp;  //create a temporary storage for the top value

//	int number = top->current;  //set parameter = to top number of stack
	temp = top;		//copy top number into temp holder
	top = top->nextVal;	//reset top number to the second value(first now)
	delete temp;	//delete the temporary value (remove node)
}

/**********************************************************************
*Function: peek
*Description: this function will return the value on top of the stack 
*				for display.
*Paramters: none
*Pre-Conditons: creation of a stack (linked list), and calling of the peek
*					function from main.
*Post-Conditons: top value of the stack will be returned to the calling 
*					function for display.
***********************************************************************/
Inhabitant* MyStack::peek()
{
	Inhabitant* topPer = top->current;
	return topPer;
}

/************************************************************************
*Function: isEmpty
*Description: function to detrmine whether the stack is empty or not
*Parameters: none
*Pre-Conditions: creation of stack and calling of isEmpty function
*Post-Conditons: returning of a bool value that determines stack status
*************************************************************************/
bool MyStack::isEmpty() const
{
	if (top == 0)
	{
		return true;  //stack is empty
	}
	else
		return false;	//stack has nodes
}