#include <iostream>
#include <math.h>
#include <string>

long long int least_common_multiple(long long int a, long long int b)
{
	long long int product = a * b;

	while (a != b)
	{
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	return product / a;

}

int how_many_digits(long long int n)
{
	int counter = 1;
	while (n >= 10)
	{
		n = n / 10;
		counter++;
	}
	return counter;
}

int main()
{
	for (int kor = 0; kor < 3; kor++)
	{
		int a, b;
		int digit;
		std::cin >> a >> b >> digit;
		long long int lcm = least_common_multiple(a, b);
		int ans_digit = how_many_digits(lcm);
		if (ans_digit == digit)
		{
			std::cout << lcm << std::endl;
		}
		else if (ans_digit > digit)
		{
			std::cout << -1 << std::endl;
		}
		else
		{
			int pow = digit - ans_digit;
			std::cout << lcm;

			std::string ans(pow, '0');
			std::cout << ans;
			/*
			for (int i = 0; i < pow; i++)
			{
				std::cout << 0;
			}
			*/
			std::cout << std::endl;
		}
	}
}