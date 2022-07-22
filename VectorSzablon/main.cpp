#include "VectorSzablon.hpp"
#include "VectorSzablon.cpp"
#include <iostream>


int main()
{
    VectorS<int> test;
    VectorS<int> test2;


    std::cout << "capacity" << test.capacity() << std::endl;
    std::cout << "size" << test.size() << std::endl;
    std::cout << "empty" << test.empty() << std::endl;
    test.push_back(1);
    test.push_back(2);

    std::cout << "capacity" << test.capacity() << std::endl;
    std::cout << "size" << test.size() << std::endl;
    std::cout << "empty" << test.empty() << std::endl;
    test.push_back(3);
    test.push_back(4);
    test.push_back(5);

    std::cout << "capacity" << test.capacity() << std::endl;
    std::cout << "size" << test.size() << std::endl;
    std::cout << "empty" << test.empty() << std::endl;
    for (int i = 0; i < test.size(); ++i)
    {
        std::cout << "[" << i << "]" << test[i] << std::endl;
    }
    std::cout << test.operator[](2) << "to samo co " << test[2] << std::endl;
    std::cout << "Insert - dodaje wartosc 8 na pozycji 1" << std::endl;
    try
    {
        test.insert(8, 1);
        for (int i = 0; i < test.size(); ++i)
        {
            std::cout << "[" << i << "]" << test[i] << std::endl;
        }
    }
    catch (std::string& error)
    {
        std::cout << error << std::endl;
    }

    std::cout << "Remove - usuwam wartosc 3 na pozycji 3" << std::endl;
    try
    {
        test.remove(3);
    }
    catch (std::string& error)
    {
        std::cout << error << std::endl;
    }

    for (int i = 0; i < test.size(); ++i)
    {
        std::cout << "[" << i << "]" << test[i] << std::endl;
    }
    std::cout << "Pop_back - usuwam ostatni element" << std::endl;
    test.pop_back();
    for (int i = 0; i < test.size(); ++i)
    {
        std::cout << "[" << i << "]" << test[i] << std::endl;
    }
    test2.push_back(9);
    test2.push_back(10);
    test.copyTo(test2, 2);
    std::cout << "nowy wektor(9,10)" << std::endl;
    for (int i = 0; i < test.size(); ++i)
    {
        std::cout << "[" << i << "]" << test[i] << std::endl;
    }
    test.bubbleSort();
    std::cout << "sortowanie wektora" << std::endl;
    for (int i = 0; i < test.size(); ++i)
    {
        std::cout << "[" << i << "]" << test[i] << std::endl;
    }
    return 0;
}

