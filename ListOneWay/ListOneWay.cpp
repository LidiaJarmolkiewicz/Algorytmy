#include"ListOneWay.hpp"
#include<iostream.>

ListOneWay::ListOneWay() :_head(nullptr),_tail(nullptr)
{
}

ListOneWay::~ListOneWay()
{
	clear();
}

void ListOneWay::remove(const unsigned int index)
{
	Node* temp = _head;
	int currentIndex = 0;
	while (_head != nullptr && currentIndex != index)
	{
		++currentIndex;
		temp = temp->next;
	}
	if (temp->prev == nullptr && temp->next != 0)//kasuje pierwszy
	{
		_head = temp->next;
		delete temp;

	}
	//if (temp->prev != nullptr && temp->next == 0)//kasuje ostatni
	//{
	//	temp->prev->next = _tail->prev;
	//	//_tail->next = nullptr;
	//	delete temp;
	//}
	else if (temp->prev != nullptr && temp->next != 0)//dowolny
		
		{
		temp->prev->next = temp->next;
		delete temp;

		}


}

void ListOneWay::clear()
{
	Node* temp = nullptr;
	while (_head != nullptr)
	{
		temp = _head->next;
		delete _head;
		_head = temp;
	}
	_tail = nullptr;
}

void ListOneWay::print() const
{
	Node* temp = _head;
	while (temp!= nullptr)
	{
		std::cout << temp->data << "<->" ;
		temp = temp->next;
	}
	std::cout << "koniec" << std::endl;
}

void ListOneWay::insertFront(int value)
{
	Node* newNode = new Node();
	newNode->data = value;
	newNode->prev = nullptr;
	if (_head == nullptr && _tail == nullptr)
	{
		newNode->next = nullptr;
		_head = newNode;
		_tail = newNode;
		return;
	}
	if (_head != nullptr)
	{
		_head->prev = newNode;
	}
	newNode->next = _head;
	_head = newNode;
}

void ListOneWay::insertBack(int value)
{
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = nullptr;
	if (_head == nullptr && _tail == nullptr)
	{
		newNode->prev = nullptr;
		_head = newNode;
		_tail = nullptr;
		return;
	}
	if (_tail != nullptr)
	{
		_tail->next = newNode;
	}
	newNode->prev = _tail;
	_tail = newNode;
}

void ListOneWay::insertAfter(int value, const unsigned int index)
{
	Node* temp = _head;
	int currentIndex = 0;
	while (_head != nullptr&&currentIndex!=index)
	{
		++currentIndex;
		temp = temp->next;
	}
	if (temp != nullptr && temp->next != nullptr)
	{
		Node* newNode = new Node;
		newNode->data = value;

		temp->next->prev = newNode;
		newNode->next = temp->next;
		temp->next = newNode;
		newNode->prev = temp;
	}

	

}
