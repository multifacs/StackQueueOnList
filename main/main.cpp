#include "DList.h"

int main()
{
	DList<int> lst;
	lst.push_back(1);
	lst.push_back(5);
	lst.push_back(100);

	cout << "Size: " << lst.GetSize() << endl;
	cout << lst << endl;
	
	cout << endl << "Popping front" << endl;
	lst.pop_front();
	cout << lst << endl;

	cout << endl << "Inserting 99 at 1, 2 at 1, 33 at 2" << endl;
	lst.insert(99, 1);
	lst.insert(2, 1);
	lst.insert(33, 2);
	cout << lst << endl;

	//cout << endl << "Reversing" << endl;
	//lst.reverse();
	//cout << lst << endl;

	cout << endl << "Removing element at [2]" << endl;
	lst.remove(2);
	cout << lst << endl;

	cout << endl << "Popping back" << endl;
	lst.pop_back();
	cout << lst << endl;

	DList<int> a;
	a.push_back(123);
	DList<int> b(a);

	/*cout << endl << "Reversing" << endl;
	lst.reverse();
	cout << lst << endl;

	cout << endl << "Testing find and delete (1)" << endl;

	b.push_back(1);
	b.push_back(1);
	b.push_back(2);
	b.push_back(3);
	b.push_back(1);
	b.push_back(5);
	b.push_front(1);

	cout << b << endl;
	b.find_and_delete(1);
	cout << b << endl;

	cout << endl << "Testing find max odd" << endl;
	cout << b.find_max_odd()->data << endl;
	b.push_back(125);
	cout << b.find_max_odd()->data << endl;*/
}