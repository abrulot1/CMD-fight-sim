/**********************************************************************
*Program Filename: MyQueue.h
*Author: Adam Brulotte
*Date: 25 July 15
*Description: header file for a class that will create a queue using a linked
*				list
*Input: none
*Output: none
*************************************************************************/
#ifndef MYQUEUE_H
#define MYQUEUE_H
#include "Inhabitant.h"

class MyQueue
{
	private:
		class qNode
		{
			friend class MyQueue;
			Inhabitant *qPerson;
			qNode *next;
			qNode(Inhabitant* inh, qNode *newVal = 0)
			{
				qPerson = inh;
				next = newVal;
			}
		};

		qNode *front;
		qNode *rear;

	public:
		MyQueue();
	//	~MyQueue();

		void addBack(Inhabitant*);
		Inhabitant* getFront();
		void removeFront();
		bool isEmpty() const;
};
#endif