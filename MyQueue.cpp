/***************************************************************
*Project Filename: MyQueue.cpp
*Author: Adam Brulotte
*Date: 25 July 15
*Description:  implementation file for a program that will make a queue with 
*				user-defined integers and add them, dispaly, and remove them.
*Input: integers from user input
*Output: integers that are stored in the queue
*************************************************************************/
#include "MyQueue.h"
#include<iostream>

/**********************************************************************
*Function: MyQueue
*Description: constructor for the MyQueue function that will set the front
*				and back pointers of the queue
*Parameters: none
*Pre-Conditions: creation of a MyQueue object
*Post-Conditions: front and back pointer of MyQueue will be NULL
************************************************************************/
MyQueue::MyQueue()
{
	front = 0;
	rear = 0;
}

/****************************************************************
*Function: addBack
*Description: this will add new user integers to the back of the queue
*Paramters: an integer to store
*Pre-Conditions: creation of the queue container and calling of the addBack 
*					function.
*Post-Conditoins: the queue will contain the integer at back of the line
**************************************************************************/
void MyQueue::addBack(Inhabitant *person)
{
	if (isEmpty())
	{
		front = new qNode(person);
		rear = front;
	}
	else
	{
		rear->next = new qNode(person);
		rear = rear->next;
	}
	//std::cout << std::endl << "front " << front->current << std::endl;
	//std::cout << std::endl << "current rear" << rear->current << std::endl;
}

/*********************************************************************
*Function: getFront
*Description: function to display the current value at the front of the queue
*Parameters: none
*Pre-Conditions: creation of the queue and calling of the getFront function
*Post-Conditions: value at the front of the queue will be returned to the 
*					calling function.
*********************************************************************/
Inhabitant* MyQueue::getFront()
{
	Inhabitant *qFront = front->qPerson;
	return qFront;
}

/*******************************************************************
*Function: removeFront
*Description: this function will remove the front value of the queue
*Parameters: a reference to an integer
*Pre-Conditions: creation of a queue and calling of the removeFront function
*Post-Conditions: the front integer of the queue will be removed
*********************************************************************/
void MyQueue::removeFront()
{
	qNode *temp;	//for storing current front variable
	if (isEmpty())
	{
		std::cout << "\nThe queue is empty" << std::endl;
	}
	else
	{
		temp = front;		// move front into the temp variable
		front = front->next;	//set front = to next in line
		delete temp;		//remove temp (old front)
	}
}

/**********************************************************************
*Function: isEmpty
*Description: will determine if the queue is empty or not
*Parmeters: none
*Pre-Conditions:  creation of a queue and calling of isEmpty function
*Post-Conditions: calling function will receive a bool indicating queue status
************************************************************************/
bool MyQueue::isEmpty() const
{
	if (front == 0)
	{
		//	std::cout << "\nThe queue is empty" << std::endl;
		return true;
	}

	else
		return false;
}