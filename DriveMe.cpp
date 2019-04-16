#include "binaryTree.h"
#include "binarySearchTree.h"
#include "MyStack.h"
#include <iostream>
#include <cassert>

using namespace std;
int main() 
{

	binarySearchTree<int>object1;
	int num;

	cout << "How many numbers would you like to insert?";
	cin >> num;

	while (num != 0)
	{
		int i = 1;
		int item;
		cout << "Item " << i << ": ";
		cin >> item;
		object1.insert(item);
		i++;
		num--;
	}

	object1.nonRecursiveInTraversal();
    object1.nonRecursivePreTraversal();
	object1.nonRecursivePostTraversal();

	return 0;
}
