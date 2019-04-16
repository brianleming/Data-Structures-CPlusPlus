
//Data:  7 12 18 20 23 27 30 32 38 45 66 68 72 85 -999

#include <iostream>
#include "arrayListType.h"

using namespace std;

int main()
{
	char a;
	arrayListType<int> intList;

	int num;

	cout << "Enter positive integers ending with -999";
	cin >> num;

	while (num != -999)
	{
		intList.insert(num);
		cin>>num;
	}

	cout << "Before Sorted: ";
	intList.print();

	intList.insertionSort();

	cout << "After sorted: ";
	intList.print();

	cout << "Press x to exit";
	cin >> a;
	return 0;
}
