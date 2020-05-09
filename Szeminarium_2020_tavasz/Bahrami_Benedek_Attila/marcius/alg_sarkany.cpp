#include <iostream>

long long int least_common_multiple(long long int a, long long int b)
{
	int i = 1;
	int k = 1;
	long long int multiple_of_a = a;
	long long int multiple_of_b = b;
	while (multiple_of_a * i != multiple_of_b * k)
	{
		if (multiple_of_a * i < multiple_of_b * k)
		{
			i++;
		}
		else
		{
			k++;
		}
	}
	return multiple_of_a * i;
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
			int mul = 1;
			int pow = digit - ans_digit;
			lcm *= mul;
			std::cout << lcm;
			for (int i = 0; i < pow; i++)
			{
				std::cout << 0;
			}
			std::cout << std::endl;
		}
	}
}