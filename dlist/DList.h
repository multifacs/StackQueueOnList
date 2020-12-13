#include <iostream>
using namespace std;

template<class T>
class DList
{
private:
	template<class T>
	class Node
	{
	public:
		Node* pNext;
		Node* pPrev;
		T data;

		Node(T data = T(), Node* pNext = nullptr, Node* pPrev = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
			this->pPrev = pPrev;
		}
	};
	int Size;
	Node<T>* head;
	Node<T>* tail;

	Node<T>* find_prev(int index)
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
			previous = previous->pNext;
		return previous;
	};

public:
	DList()
	{
		Size = 0;
		head = nullptr;
		tail = nullptr;
	}
	DList(DList<T>& _l)
	{
		Size = 0;
		head = nullptr;
		tail = nullptr;
		for (int i = 0; i < _l.Size; i++)
			push_back(_l[i]);
	}
	~DList()
	{
		clear();
	}

	int GetSize() const { return Size; }

	T& operator[](const int index)
	{
		if (index < 0 || index >= Size)
			throw length_error("incorrect index");

		if (index <= round(Size / 2.0))
		{
			int counter = 0;
			Node<T>* current = this->head;
			while (current != nullptr)
			{
				if (counter == index)
					return current->data;
				current = current->pNext;
				counter++;
			}
		}
		else
		{
			int counter = Size - 1;
			Node<T>* current = this->tail;
			while (current != nullptr)
			{
				if (counter == index)
					return current->data;
				current = current->pPrev;
				counter++;
			}
		}
	}

	void push_back(T data)
	{
		if (head == nullptr)
		{
			head = new Node<T>(data);
			tail = head;
		}
		else
		{
			Node<T>* current = this->tail;
			current->pNext = new Node<T>(data, nullptr, current);
			tail = current->pNext;
		}

		Size++;
	}

	void pop_front()
	{
		if (Size == 0)
			throw logic_error("list empty");

		Node<T>* temp = head;
		head = head->pNext;
		
		if (head != nullptr)
			head->pPrev = nullptr;
		else
			tail = tail->pPrev;

		delete temp;
		Size--;
	}

	void clear()
	{
		while (Size)
			pop_front();
	}

	void push_front(T data)
	{
		Node<T>* temp = head;
		head = new Node<T>(data, head);
		temp->pPrev = head;
		Size++;
	}

	void pop_back()
	{
		if (Size == 0)
			throw logic_error("list empty");

		Node<T>* temp = tail;
		tail = tail->pPrev;

		if (tail != nullptr)
			tail->pPrev = nullptr;
		else
			head = head->pNext;

		delete temp;
		Size--;
	}

	void insert(T data, int index)
	{
		if (index < 0 || index > Size)
			throw logic_error("incorrect index");

		if (index == 0)
			push_front(data);
		else if (index == Size)
			push_back(data);
		else
		{
			Node<T>* previous = find_prev(index);

			Node<T>* newNode = new Node<T>(data, previous->pNext, previous);
			previous->pNext->pPrev = newNode;
			previous->pNext = newNode;

			Size++;
		}
	}

	void remove(int index)
	{
		if (index < 0 || index >= Size)
			throw logic_error("incorrect index");

		if (index == 0)
			pop_front();
		else if (index == Size - 1)
			pop_back();
		else
		{
			Node<T>* previous = find_prev(index);

			Node<T>* toDelete = previous->pNext;
			toDelete->pNext->pPrev = previous;
			previous->pNext = toDelete->pNext;

			delete toDelete;
			Size--;
		}
	}

	friend ostream& operator << (ostream& ostr, DList<T>& _l)
	{
		ostr << "{";
		for (int i = 0; i < _l.GetSize() - 1; i++)
			ostr << _l[i] << ", ";
		ostr << _l[_l.GetSize() - 1] << "}";

		return ostr;
	}

};

	//extra tasks
/*
	void reverse()
	{
		if (Size == 0)
			throw logic_error("list empty");

		Node<T>* previous = nullptr;
		Node<T>* current = this->head;
		Node<T>* next = this->head->pNext;

		current->pNext = nullptr;
		previous = current;
		current = next;
		next = next->pNext;

		for (int i = 1; i < Size; i++)
		{
			current->pNext = previous;
			previous = current;
			current = next;
			if (next != nullptr)
				next = next->pNext;
		}

		head = previous;
	}

	void find_and_delete(T value)
	{
		if (Size == 0)
			throw logic_error("list empty");

		Node<T>* current = head;
		int counter = 0;

		while (current != nullptr)
		{
			if (current->data == value)
			{
				current = current->pNext;
				remove(counter);
				continue;
			}
			current = current->pNext;
			counter++;
		}
	}

	Node<T>* find_max_odd()
	{
		if (Size == 0)
			throw logic_error("list empty");

		Node<T>* current = head;
		Node<T>* result = nullptr;
		T temp = 0;

		while (current != nullptr)
		{
			if ((current->data % 2 == 1) && (current->data > temp))
			{
				result = current;
				temp = current->data;
			}
			current = current->pNext;
		}

		return result;
	}
};
*/