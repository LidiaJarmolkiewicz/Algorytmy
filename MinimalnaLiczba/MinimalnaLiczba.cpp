
#include <iostream>

#include<random>



void readN(int* tab, const unsigned int size)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, 50);

    for (int i = 0; i < size; ++i)
    {
        tab[i] = distr(gen);
        std::cout << tab[i] << " ";
    }
}
int findMin(int* tab, const unsigned int size)
{
    int min=0;
    if (size > 0 && tab != nullptr)
    {
        min = tab[0];

        for (int i = 1; i < size; ++i)
        {
            if (tab[i] < min)
                min = tab[i];
        }
    }
    return min;
}


int main()
{
    std::cout << "Ile liczb wczytac?" << std::endl;
    unsigned int number = 0;
    std::cin >> number;

    if (number > 0)
    {
        int* tab = new int[number];
        readN(tab, number);
        std::cout << std::endl;
       // int min = findMin(tab, number);
        std::cout << "Najmniejsza liczba to: " << findMin(tab,number);
        delete[] tab;
    }
}
