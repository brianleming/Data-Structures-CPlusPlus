#include "linkedListIterator.h"
template <class Type>
class linkedListType
{
public:
	void initializeList();

	void print() const;

	int length() const;

	void destroyList();

	Type front() const;

	Type back() const;

	virtual void insertFirst(const Type& newItem) = 0;

	virtual void insertLast(const Type& newItem) = 0;

	virtual void deleteNode(const Type& deleteItem) = 0;

	linkedListType();

	~linkedListType();

protected:
	int count;
	nodeType<Type> *first;
	nodeType<Type> *last;
};

template <class Type>
linkedListType<Type>::linkedListType()
{
	first = NULL;
	last = NULL;
	count = 0;
}

template <class Type>
void linkedListType<Type>::destroyList()
{
	nodeType<Type> *temp;
	while (first != NULL)
	{
		temp = first;
		first = first->link;
		delete temp;
	}
	last = NULL;
	count = 0;
}

template <class Type>
void linkedListType<Type>::initializeList()
{
	destroyList();
}

template <class Type>
void linkedListType<Type>::print() const
{
	nodeType<Type> *current;
	current = first;
	while (current != NULL)
	{
		cout << current->info << " ";
		current = current->link;
	}
}

template <class Type>
int linkedListType<Type>::length() const
{
	return count;
}

template <class Type>
Type linkedListType<Type>::front() const
{
	assert(first != NULL);
	return first->info;
}

template <class Type>
Type linkedListType<Type>::back() const
{
	assert(last != NULL);
	return last->info;
}

template <class Type>
linkedListType<Type>::~linkedListType()
{
	destroyList();
}




template <class Type>
class unorderedLinkedList : public linkedListType<Type>
{
public:
	void insertFirst(const Type& newItem);

	void insertLast(const Type& newItem);

	void deleteNode(const Type& deleteItem);

	void linkedInsertionSort();
};


template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type& newItem)
{
	nodeType<Type> *newNode;
	newNode = new nodeType<Type>;
	newNode->info = newItem;
	newNode->link = first;
	first = newNode;
	count++;
	if (last == NULL)
		last = newNode;
}

template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type& newItem)
{
	nodeType<Type> *newNode;
	newNode = new nodeType<Type>;
	newNode->info = newItem;
	newNode->link = NULL;
	if (first == NULL)
	{
		first = newNode;
		last = newNode;
		count++;
	}
	else
	{
		last->link = newNode;
		last = newNode;
		count++;
	}
}

template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
	nodeType<Type> *current;
	nodeType<Type> *trailCurrent;
	bool found;
	if (first == NULL)
		cout << "Cannot delete from an empty list." << endl;
	else
	{
		if (first->info == deleteItem)
		{
			current = first;
			first = first->link;
			count--;
			if (first == NULL)
				last = NULL;
			delete current;
		}
		else
		{
			found = false;
			trailCurrent = first;
			current = first->link;
			while (current != NULL && !found)
			{
				if (current->info != deleteItem)
				{
					trailCurrent = current;
					current = current->link;
				}
				else
					found = true;
			}
			if (found)
			{
				trailCurrent->link = current->link;
				count - ;
				if (last == current)
					last = trailCurrent;
				delete current;
			}
			else
				cout << "The item to be deleted is not in the list." << endl;
		}
	}
}

template <class Type>
void unorderedLinkedList<Type>::linkedInsertionSort()
{
	nodeType<Type> *lastInOrder;
	nodeType<Type> *firstOutOfOrder;
	nodeType<Type> *current;
	nodeType<Type> *trailCurrent;

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
}
