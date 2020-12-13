#include "LSQ.h"

int main()
{
	LStack<int> a;
	a.push(1);
	a.push(2);
	a.push(3);
	cout << a.pop() << a.pop() << a.pop() << endl;

	LQueue<int> b;
	b.push(1);
	b.push(2);
	b.push(3);
	cout << b.pop() << b.pop() << b.pop();
}