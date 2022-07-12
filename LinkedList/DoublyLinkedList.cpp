#include "DoublyLinkedList.hpp"
#include<iostream>
	
DoublyLinkedList::DoublyLinkedList():_head(nullptr),_tail(nullptr)
{
}

DoublyLinkedList::~DoublyLinkedList()
{
	clear();
}

unsigned int DoublyLinkedList::size() const
{
	Node* temp = _head;
	int size = 0;
	while (temp != nullptr)
	{
		++size;
		temp = temp->next;
	}
	
	return size;
}

bool DoublyLinkedList::empty() const
{
	if(_head == nullptr || _tail == nullptr)
	return true;
}

void DoublyLinkedList::print() const
{
	Node* temp = _head;
	while (temp != nullptr)
	{
		std::cout << temp->data<<"<->";
		temp = temp->next;
	}
	std::cout << "koniec listy" << std::endl;;
}



void DoublyLinkedList::insertFront(int value)
{
	Node* newNode = new Node();
	newNode->data = value;
	newNode->prev = nullptr;
	if (_head != nullptr)
	{
		_head->prev = newNode;
	}
	newNode->next = _head;
	_head=newNode;
	
}

void DoublyLinkedList::insertBack(int value)
{
	Node* newNode = new Node();
	newNode->data = value;
	newNode->next = nullptr;
	if (_tail != nullptr)
	{
		_tail->next = newNode;
	}
	newNode->prev = _tail;
	_tail = newNode;

}
	
void DoublyLinkedList::insertAfter(int value, const unsigned int index)
{
	Node* temp = _head;
	int currentIndex = 0;
	while (temp != 0 && currentIndex != index)
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

void DoublyLinkedList::remove(const unsigned int index)
{
	Node* temp = _head;
	int currentIndex = 0;
	while (temp != 0 && currentIndex != index)
	{
		++currentIndex;
		temp = temp->next;
	}

	if (temp->prev == nullptr && temp->next != nullptr)//pierwszy
	{
		_head = temp->next;
		_head->prev = nullptr;
		delete temp;
	}
	else if (temp->prev != nullptr && temp->next == nullptr)//ostatni
	{
		_tail = temp->prev;
		_tail->next = nullptr;
		delete temp;
	}
	else if (temp->prev != nullptr && temp->next != nullptr)//srodkowy
	{
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		delete temp;
	}
	else //jedyny
	{
		_head = nullptr;
		_tail = nullptr;
		delete temp;
	}
}

void DoublyLinkedList::clear()
{
	Node* temp = nullptr;
	while(_head!=nullptr)
	{
	temp = _head->next;
	delete _head;
	_head = temp;
	}
	_tail = nullptr;
}

int& DoublyLinkedList::operator[](const unsigned int index) const
{

	Node* temp = _head;
	unsigned int currentIndex = 0;

	while (temp != nullptr && currentIndex != index) 
	{
		++currentIndex;
		temp = temp->next;
	}

	if (temp == nullptr)
	{
		//todo wyjatek
	}

	return temp->data;
}
