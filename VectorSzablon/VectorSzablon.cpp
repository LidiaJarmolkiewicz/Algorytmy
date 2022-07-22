#include<string>
#include"VectorSzablon.hpp"



template<typename T>
VectorS<T>::VectorS(): _size(0), _capacity(0),  _data(nullptr)
{
}


template<typename T>
inline VectorS<T>::VectorS(unsigned int capacity): _size(0),  _capacity(capacity)
{
	_data = new T[_capacity];
}

template<typename T>
VectorS<T>::VectorS(const VectorS& old)
{
	_capacity = old._capacity;
	_size = old._size;

	_data = new int[_capacity];
	for (int i = 0; i < old._size; ++i)
	{
		_data[i] = old._data[i];
	}

}
template<typename T>
VectorS<T>::~VectorS()
{
	if (_data != nullptr)
	{
		delete[]_data;
		//_data = nullptr;
	}

}
template<typename T>
void VectorS<T>::reserve(unsigned int capacity)
{

	int* data = new int[capacity];//nowa tablica na elementy
	for (int i = 0; i < _size; ++i)//skopiuj wszystko
	{
		data[i] = _data[i];
	}
	_capacity = capacity;
	delete[] _data;//zwolnij star¹ pamiêæ
	_data = data;
	//nadpisz wskaznik zeby wektor przechowywa³ now¹ pamiec
}
template<typename T>
int VectorS<T>::capacity()const
{
	return _capacity;
}
template<typename T>
int VectorS<T>::size() const
{
	return _size;
}
template<typename T>
bool VectorS<T>::empty() const
{
	return (_size == 0);

}
template<typename T>
void VectorS<T>::insert(int value, unsigned int index)
{
	if (_capacity <= _size)
	{
		reserve((_capacity * 2) + 1);
	}
	if (index > _size)
	{
		throw std::string("nie mozna dodac bo indeks poza rozmiarem wektora");
	}

	for (int i = _size; i > index; --i)
	{

		_data[i] = _data[i - 1];
	}

	_data[index] = value;
	++_size;
}
template<typename T>
void VectorS<T>::remove(unsigned int index)
{
	if (index > _size)
	{
		throw std::string("nie mozna usunac bo indeks poza rozmiarem wektora");
	}
	for (int i = index; i < _size; ++i)
	{
		_data[i] = _data[i + 1];
	}
	--_size;
}
template<typename T>
void VectorS<T>::clear()
{
	_size = 0;
}
template<typename T>
void VectorS<T>::push_back(const int& value)//dodaje tylko jeden element
{
	if (_size >= _capacity)
	{
		reserve((_capacity * 2) + 1);
	}
	_data[_size++] = value;
	//_data[_size] = value;
	//_size++;

}
template<typename T>
void VectorS<T>::pop_back()
{
	--_size;
}
template<typename T>
void VectorS<T>::copyTo(VectorS& other, unsigned int index)
{
	for (int i = 0; i < other._size; ++i)
	{
		insert(other._data[i], index++);

	}
}
template<typename T>
void VectorS<T>::bubbleSort()

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
template<typename T>
int& VectorS<T>::operator[](unsigned int position)
{
	if (position > _size)
	{
		//throw std::string("position poza rozmiarem vektora");

	}

	return _data[position];
}
template<typename T>
VectorS<T>& VectorS<T>::operator=(const VectorS& other)
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