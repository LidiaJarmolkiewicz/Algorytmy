#pragma once
class DoublyLinkedList
{
public:
	DoublyLinkedList();
	virtual ~DoublyLinkedList();
	DoublyLinkedList(const DoublyLinkedList& old) = delete;//-zabronienie kompilatorowi generowania domyœlnego konstr.
	

	unsigned int size()const;//policz ilosc elementow w liscie
	bool empty()const;//true gdy head  lub tail =0
	void print()const;

	void insertFront(int value);//wstaw wartoœæ na poczatek
	void insertBack(int value);//na koniec
	void insertAfter(int value, const unsigned int index);//w dowolnym miejscu


	void removeValue(int value);
	void remove(const unsigned int index);
	void clear();
	void merge(DoublyLinkedList& other, const unsigned int index);
	int& operator[](const unsigned int index)const;
	//operator=
	//merge
	//splice

private:
	struct Node
	{
		int data;
		Node* next;
		Node* prev;
	};

	Node* _head;
	Node* _tail;
	//DoublyLinkedList(const DoublyLinkedList& old);//;-zabronienie copy konstr w strym C++
	DoublyLinkedList& operator=(DoublyLinkedList& other);
};

