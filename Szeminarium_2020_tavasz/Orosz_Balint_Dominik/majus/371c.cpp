#include <iostream>
#include <algorithm>
 
using namespace std;
 
string recipe;
int nb, ns, nc;
int pb, ps, pc;
long long int money;
 
int B = 0, S = 0, C = 0;
long long int nulla = 0;
 
long long int f(const long long int x)
{
	return pb * ((B * x - nb > nulla) ? (B * x - nb) : nulla) +
		ps * ((S * x - ns > nulla) ? (S * x - ns) : nulla) +
		pc * ((C * x - nc > nulla) ? (C * x - nc) : nulla);
}
 
int main()
{
	cin >> recipe >> nb >> ns >> nc >> pb >> ps >> pc >> money;
 
	for (char ch : recipe)
	{
		switch (ch)
		{
		case 'B':
			B++;
			break;
		case 'S':
			S++;
			break;
		case 'C':
			C++;
			break;
		default:
			break;
		}
	}
 
	long long int result, x, fx;
	
	long long int a = nulla, b = money + 1000;
 
	while (a <= b)
	{
		x = a + (b - a) / 2;
		fx = f(x);
 
		if (fx == money)
		{
			result = x;
			break;
		}
		else if (fx > money)
		{
			b = x - 1;
		}
		else if (fx < money)
		{
			a = x + 1;
			result = x;
		}
	}
 
	cout << result << endl;
 
	return 0;
}