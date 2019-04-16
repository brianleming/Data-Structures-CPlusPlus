#ifndef H_linkedQueue
#define H_linkedQueue

#include <iostream>
#include <cassert>

#include "queueADT.h"

using namespace std;
template <class Type>
struct nodeType
{
	Type info;
	nodeType<Type> *link;
};

template <class Type>
class linkedQueueType : public queueADT<Type>
{
public:
	const linkedQueueType<Type>& operator=(const linkedQueueType<Type>&);
	bool isEmptyQueue() const;
	bool isFullQueue() const;
	void initializeQueue();
	Type front() const;
	Type back() const;
	void addQueue(const Type& queueElement);
	void deleteQueue();
	linkedQueueType(int queueSize = 100);
	linkedQueueType(const linkedQueueType<Type>& otherQueue);
	~queueType();

private:
	int maxQueueSize;
	int count;
	int queueRear;
	Type *list;
	nodeType<Type> *queueFront;
	nodeType<Type> *queueRear;
};

template <class Type>
bool queueType<Type>::isEmptyQueue() const
{
	return (queueFront == NULL);
}

template <class Type>
bool queueType<Type>::isFullQueue() const
{
	return false;
}

template <class Type>
void queueType<Type>::initializeQueue()
{
	nodeType<Type> *temp;
	while (queueFront != NULL)
	{
		temp = queueFront;
		queueFront = queueFront->link;
		delete temp;
	}
	queueRear = NULL;
}

template <class Type>
void queueType<Type>::front() const
{
	assert(queueFront != NULL);
	return queueFront->info;
}

template <class Type>
void queueType<Type>::back() const
{
	assert(queueRear != NULL);
	return queueRear->info;
}

template <class Type>
void queueType<Type>::addQueue(const Type& newElement)
{
	nodeType<Type> *newNode;
	newNode = new nodeType<Type>;
	newNode->info = newElement;
	newNode->link = NULL;
	if (queueFront == NULL)
	{
		queueFront = newNode;
		queueRear = newNode;
	}
	else
	{
		queueRear->link = newNode;
		queueRear = queueRear->link;
	}
}

template <class Type>
void queueType<Type>::deleteQueue()
{
	nodeType<Type> *temp;
	if (!isEmptyQueue())
	{
		temp = queueFront;
		queueFront = queueFront->link;

		delete temp;

		if (queueFront == NULL)
			queueRear = NULL;
	}
	else
		cout << "Cannot remove from and empty queue." << endl;
}

template <class Type>
void linkedQueueType<Type>::linkedQueueType()
{
	queueFront = NULL;
	queueRear = NULL;
}

template <class Type>
void queueType<Type>::~queueType()
{
	delete[] list;
}

template <class Type>
void queueType<Type>::queueType(const queueType<Type>& otherQueue)
{
	nodeType<Type> *newNode;
	nodeType<Type> *current;

	if (otherQueue.queueFront = NULL)
	{
		queueFront = NULL;
		queueRear = NULL;
	}
	else
	{
		current = otherQueue.queueFront;
		queueFront = new nodeType<Type>;
		queueFront->info = current->info;
	}
}

template <class Type>
void queueType<Type>::const linkedQueueType<Type>& operator=(const linkedQueueType<Type>&)
{
	nodeType<Type> *newNode;
	nodeType<Type> *current;

	if (this != &otherQueue)
	{
		if (queueFront != NULL)
			initializeQueue();

		if (otherQueue.queueFront == NULL)
		{
			queueFront = NULL;
			queueRear = NULL;
		}
		else
		{
			current = otherQueue.queueFront;
			queueFront = new nodeType<Type>;
			queueFront->info = current->info;
			queueFront->link = NULL;
			queueRear = queueFront;
			current = current->link;

			while (current != NULL)
			{
				newNode = new nodeType<Type>;
				newNode->info = current->info;
				newNode->link = NULL;
				queueRear->link = newNode;
				queueRear = newNode;
				current = current->link;
			}
		}
	}
	return *this;
}

template <class Type>
void queueType<Type>::linkedInsertionSort()
{
	nodeType<elemType> *lastInOrder;
	nodeType<elemType> *firstOutOfOrder;
	nodeType<elemType> *current;
	nodeType<elemType> *trailCurrent;

	lastInOrder = first;

	if (first == NULL)
		cerr << "Cannot sort an empty list." << endl;
	else if (first->link == NULL)
		cout << "The list is of length 1. It is already ordered." << endl;
	else
		while (lastInOrder->link != NULL)
		{
			firstOutOfOrder = lastInOrder->link;

			if (firstOutOfOrder->info < first->info)
			{
				lastInOrder->link = firstOutOfOrder->link;
				firstOutOfOrder->link = first;
				first = firstOutOfOrder;
			}
			else
			{
				trailCurrent = first;
				current = first->link;
				
				while (current->info < firstOutOfOrder->info)
				{
					trailCurrent = current;
					current = current->link;
				}

				if (current != firstOutOfOrder)
				{
					lastInOrder->link = firstOutOfOrder->link;
					firstOutOfOrder->link = current;
					trailCurrent->link = firstOutOfOrder;
				}
				else
					lastInOrder = lastInOrder->link;
			}
		}
} #endif