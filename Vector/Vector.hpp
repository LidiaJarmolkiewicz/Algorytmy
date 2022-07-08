#pragma once
class Vector
{
public:

	Vector(); // konstruktor domyslny, tworzy pusty vector 
	Vector(unsigned int capacity); // rezerwuje miejsca na podana liczbe elementow
	Vector(const Vector& old); //c-tor kopiuj�cy
	virtual ~Vector(); //d-tor

	void reserve(unsigned int capacity); // zwi�ksza rozmiar zarezerwowanej pamieci vectora, ale nie mozna zmienjszyc
	//void resize(unsigned int size); // pozwala zmniejszych rozmiar wektora, ale tez zwiekszyc

	//Gettery:
	unsigned int capacity() const;
	unsigned int size() const;
	bool empty() const;

	void insert(int value, unsigned int position); //pozwala wstawic wartosc do wektora na zadana pozycje
	void remove(unsigned int position); //usuwa element z wektora
	void clear(); //usuwa wszystkie elementy zwektora, jednak nie zmniejsza zarezerwowanej pamieci
	void push_back(const int& value); // odklada element na ostatnie wolne miejsce 
	void pop_back();//usuwa ostatni element

	int& operator[](unsigned int position); //operator dostepu do danych na podanej pozycji
	Vector& operator=(const Vector& other); //to samo co c-tor kopiujacy

private:
	unsigned int _size;//rozmiar
	unsigned int _capacity;//pojemnosc
	int* _data; 
};