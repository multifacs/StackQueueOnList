#pragma once
#include <DList.h>

template<class T>
class LStack
{
protected:
	DList<T> container;
public:
	LStack() : container() {}
	LStack(LStack& _v) : container(_v.container) {}

	bool IsEmpty()
	{
		return(container.GetSize() == 0);
	}
	int GetSize()
	{
		return(container.GetSize());
	}
	void push(const T& data)
	{
		container.push_back(data);
	}
	virtual T pop()
	{
		auto i = container.end();
		T temp = *i;
		container.pop_back();

		return(temp);
	}
};

template<class T>
class LQueue : public LStack<T>
{
public:
	T pop() override
	{
		auto i = container.begin();
		T temp = *i;
		this->container.pop_front();

		return(temp);
	}
};

template<class T>
class PQueue
{
protected:
	DList<T> container;
	int* P;
public:
	PQueue() : container()
	{
		P = new int[1];
	}
	PQueue(PQueue& _v)
	{
		container = _v.container;
		P = new int[GetSize()];
		for (int i = 0; i < GetSize(); i++)
			P[i] = _v.P[i];
	}
	~PQueue()
	{
		container.~DList();
		delete[] P;
	}

	bool IsEmpty() { return(container.GetSize() == 0); }
	int GetSize() { return(container.GetSize()); }

	void push(const T& data, int p)
	{
		int* P2;
		P2 = new int[GetSize() + 1];

		int pos;
		if (GetSize() == 0)
			pos = 0;
		else
		{
			pos = 0;
			while (pos < GetSize())
			{
				if (P[pos] < p)
					break;
				pos++;
			}
		}
		for (int i = 0; i < pos; i++)
			P2[i] = P[i];
		P2[pos] = p;
		container.insert(data, pos);
		for (int i = pos + 1; i < GetSize(); i++)
			P2[i] = P[i - 1];

		if (GetSize() > 0)
			delete[] P;
		P = P2;
	}

	T pop()
	{
		if (GetSize() == 0)
			return 0;

		int* P2;
		P2 = new int[GetSize() - 1];

		auto i = container.begin();
		T item = *i;

		for (int i = 0; i < GetSize() - 1; i++)
			P2[i] = P[i + 1];

		if (GetSize() == 0)
			delete[] P;

		container.pop_front();
		P = P2;
		return item;
	}

};