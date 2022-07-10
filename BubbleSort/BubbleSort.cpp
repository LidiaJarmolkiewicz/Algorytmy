
#include <iostream>
void bubbleSort(int *tab, const unsigned int size)
{
    bool swapped=false;
    do
    {
        swapped = false;
        for (int i=0; i<size-1;++i)
        {
            if (tab[i]>tab[i+1])
            {
                int x=tab[i];
                tab[i ]=tab[i+1];
                tab[i+1] = x;
                swapped = true;
            }
        }
    } 
    while (swapped);
}
void bubbleSort2(int* tab, const unsigned int size)
{
    
    for (int k = 1; k < size ; ++k)
    {
        for (int i = 0; i < size - k; ++i)
        {
            if (tab[i] > tab[i + 1])
            {
                int x = tab[i];
                tab[i] = tab[i + 1];
                tab[i + 1] = x;

            }
        }
    }
}
int main()
{
    const unsigned int size = 10;
    int tab[size] = { 8, 3, 5, 4, 2, 9, 1, 7, 6, 0 };
    for (int i = 0; i < size; ++i)

    {
        std::cout << "[" << i << "]=" << tab[i] << std::endl;
    }
    std::cout <<"sortowanie pe³ne"<<std::endl;
    bubbleSort(tab, size);
    for (int i = 0; i < size; ++i)

    {
        std::cout << "[" << i << "]=" << tab[i] << std::endl;
    }
    std::cout << std::endl;
    std::cout << "sortowanie skrocone" << std::endl;
    bubbleSort2(tab, size);
    for (int i = 0; i < size; ++i)

    {
        std::cout << "[" << i << "]=" << tab[i] << std::endl;
    }
}
