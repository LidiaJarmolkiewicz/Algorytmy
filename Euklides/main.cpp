
#include <iostream>

int NWD( int a=0 , int b=0 )
{

	if (a > 0 && b > 0)
	{
		int t = 0;
		if (a >= b)
		{
			while (b != 0)
			{
				t = b;
				b = a % b;
				a = t;
			}
			return a;

		}
		else
		{
			int temp = 0;
			temp = b;
			b = a;
			a = temp;
			while (b != 0)
			{
				t = b;
				b = a % b;
				a = t;
			}
			return a;

		}
	}
	else
	{
		std::cout << "podales nieprawidlowe liczby !" << std::endl;
		return 0;
	}

};
int NWW(unsigned int a = 0, unsigned int b = 0)
{
    if (NWD(a, b) > 0)
    {
        int x = 0;
        x = a * b / NWD(a,b);
        return x;
    }
   else
   {
        //std::cout << "dzielisz przez zero !" << std::endl;
        return 0;
    }
}
int main()
{
    int a = 0;
    int b = 0;
    std::cout << "podaj dwie liczby"<<std::endl;
    std::cin >> a;
    std::cin >> b;
    std::cout <<"najwiekszy wspolny dzielnik wynosi : " << NWD(a,b)<<std::endl;
    std::cout << "najwiekszy wspolna wielokrotnosc wynosi : " << NWW(a, b);
    return 0;
}
   
    
