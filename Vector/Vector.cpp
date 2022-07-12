#include"Vector.hpp"

Vector::Vector()
	:_capacity(0)
	,_size(0)
	,_data (nullptr)
{
}

Vector::Vector(unsigned int capacity)
	:_size(0)
	, _capacity(capacity)
	
{
	 _data = new int[_capacity];
}

Vector::Vector(const Vector& old)
{
	_capacity = old._capacity;
	_size = old._size;
	
	_data = new int[_capacity];
	for (int i = 0; i < old._size; ++i)
	{
		_data[i] = old._data[i];
	}

}

Vector::~Vector()
{
	if (_data != nullptr)
	{
	delete[]_data;
	//_data = nullptr;
	}
	
}

void Vector::reserve(unsigned int capacity)
{
	int* data=new int[capacity];//nowa tablica na elementy
	for (int i = 0; i < _size; ++i)//skopiuj wszystko
	{
		data[i] = _data[i];
	}
	_capacity = capacity;
	delete[] _data;//zwolnij star¹ pamiêæ
	_data = data;
	//nadpisz wskaznik zeby wektor przechowywa³ now¹ pamiec
}

unsigned int Vector::capacity() const
{
	return _capacity;
}

unsigned int Vector::size() const
{
	return _size;
}

bool Vector::empty() const
{
	return (_size == 0);
		
}

void Vector::insert(int value, unsigned int index)
{
	if (_capacity <= _size)
	{
		reserve((_capacity * 2) + 1);
	}
		
	for (int i = _size; i > index; --i)
	{

		_data[i] = _data[i - 1];
	}

	_data[index] = value;
	++_size;
}

void Vector::remove(unsigned int index)
{
	if (index > _size)
	{
		//wyjatek
	}
	for (int i = index; i < _size; ++i)
	{
		_data[i] = _data[i + 1];
	}
	--_size;
}

void Vector::clear()
{
	_size = 0;
}

void Vector::push_back(const int& value)//dodaje tylko jeden element
{
	if (_size >= _capacity)
	{
		reserve((_capacity * 2)+1);
	}
	_data[_size++] = value;
		//_data[_size] = value;
		//_size++;
		
}

void Vector::pop_back()
{
	--_size;
}

void Vector::copyTo(Vector& other, unsigned int index)
{
	for (int i = 0; i < other._size; ++i) 
	{
		insert(other._data[i], index++);

	}
}

void Vector::bubbleSort()

	{
		bool swapped = false;
		do
		{
			swapped = false;
			for (int i = 0; i < _size - 1; ++i)
			{
				if (_data[i] > _data[i + 1])
				{
					int x = _data[i];
					_data[i] = _data[i + 1];
					_data[i + 1] = x;
					swapped = true;
				}
			}
		} while (swapped);
	}

int& Vector::operator[](unsigned int position)
{
	if (position > _size)
	{
		//todo exception
		
	}

	return _data[position];
}

Vector& Vector::operator=(const Vector& other)
{
	delete[] _data;//usuwamy tablice na kt wskazuje wskaznik
	

	_capacity = other._capacity;
	_size = other._size;

	_data = new int[_capacity];
	for (int i = 0; i < other._size; ++i)
	{
		_data[i] = other._data[i];
	}
	return *this;//obiekt test-wska¿nik na obiekt na który wywo³ujemy
}
