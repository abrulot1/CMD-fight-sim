/********************************************************************
*Program Filename: MyStack.h
*Author: Adam Brulotte
*Date: 25 July 15
*Description: Header file for a class that will act as a stack to store data 
*				using linked lists
*Input: none
*Output: none
*****************************************************************/
#ifndef MYSTACK_H
#define MYSTACK_H
#include "Inhabitant.h"

class MyStack
{
	private:
		class Nodes
		{
			friend class MyStack;
			 Inhabitant *current;
			Nodes *nextVal;
			
			Nodes(Inhabitant* inPer, Nodes *nextNum = 0)
			{
				current = inPer;
				nextVal = nextNum;
			}
		};
		Nodes *top;

	public:
		MyStack()
		{
			top = 0;
		}
		void push(Inhabitant*);
		void pop();
		bool isEmpty() const;
		Inhabitant* peek();
};
#endif