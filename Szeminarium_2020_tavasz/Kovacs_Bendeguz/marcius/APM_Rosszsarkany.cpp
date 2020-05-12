using namespace std;
#include <iostream>
#include <math.h>

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	unsigned long long int seged = 1;
	do {
		seged = seged * a * b;
		cout << seged << " " << (trunc(log10(seged)) + 1) << "\n" ;
	} while ((trunc(log10(seged)) + 1) != c);
	

}

