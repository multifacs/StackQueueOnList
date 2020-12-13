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
		T temp = container[container.GetSize() - 1];
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
		T temp = this->container[0];
		this->container.pop_front();

		return(temp);
	}
};
