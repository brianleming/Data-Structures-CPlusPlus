#include <iostream>
#include "linkedListType.h"

using namespace std; 

    int main()
    {
        linkedListType<int> list1;
        int num;

        cout << "Line 3: Enter integers ending with -999" << endl;
        cin >> num;

        while (num != -999)
        {
            list1.insertLast(num);
            cin >> num;
        }

	cout << endl;
	list1.print();
	cout << endl;
	list1.linkedInsertionSort();
	list1.print();

	return 0;                    
   }