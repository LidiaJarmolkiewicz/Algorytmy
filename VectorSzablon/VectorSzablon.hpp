#pragma once
template<typename T>
class VectorS
{
	
	public:

		VectorS(); 
		VectorS(unsigned int capacity); 
		VectorS(const VectorS& old); 
		virtual ~VectorS(); 

		void reserve(unsigned int capacity);
	
		int capacity() const;
		int size() const;
		bool empty() const;

		void insert(int value, unsigned int index);
		void remove(unsigned int index);
		void clear(); 
		void push_back(const int& value); 
		void pop_back();
		void copyTo(VectorS& other, unsigned int index); 
		void bubbleSort();

		int& operator[](unsigned int position); 
		VectorS& operator=(const VectorS& other); 

	private:
		int _size;
		int _capacity;
		T* _data;
	
};
