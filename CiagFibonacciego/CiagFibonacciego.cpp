#include <iostream>
#include<string>

int main()
{
	int  n = 0;

	std::cout << "podaj szukany element ciagu" << std::endl;
	std::cin >> n;

	int a = 0;
	int sum = 0;
	int b = 1;
	if (n >= a)
	{
		std::cout << "kolejne wyrazy ciagu" << std::endl;
		for (int i = 1; i <= n; ++i)
		{
			sum = a + b;
			//std::cout << a << " "<< std::endl;
			a = b;
			b = sum;
			std::cout << a << " ";
		}
	}
	else
	{
		std::cout << " niewlasciwa liczba";
	}
	std::cout << std::endl;
	std::cout<<n << "y wyraz ciagu to: "<<a;
	return 0;
}
