using namespace std;
#include <iostream>
#include <math.h>

int main()
{
	/*
	//Rossz1, már 22 számjegybõl álló számokat sem tud létrehozni
	int a, b, c;
	cin >> a >> b >> c;
	unsigned long long int seged = 1;
	do {
		seged = seged * a * b;
		cout << seged << " " << (trunc(log10(seged)) + 1) << "\n" ;
	} while ((trunc(log10(seged)) + 1) != c);
	*/
	
	for (int j = 0; j < 3; j++) /*while(1)*/{
		int a, b, c;
		cin >> a >> b >> c;
		unsigned long long int seged = (unsigned long long int)(a) * (unsigned long long int)(b);
		//cout <<"a: " << a << " b: " <<b  << " Seged szar: " << seged << "\n";
		if ((  c < (trunc(log10(a)) + 1)) || c < (trunc(log10(b)) + 1)) { cout << -1 << endl; }
		else {
			if ((c == (trunc(log10(b)) + 1) && c == (trunc(log10(a)) + 1)) || c < (trunc(log10(seged)) + 1))
			{
				int vane = 0;
				int i = 1;
				while ((trunc(log10(a * i)) + 1 <= c) && (trunc(log10(b * i)) + 1) <= c) {
					if ((a * i) % b == 0 && (trunc(log10(a * i)) + 1) == c) { cout << a * i << endl; vane = 1; break; }
					else if ((b * i) % a == 0 && (trunc(log10(b * i)) + 1) == c) { cout << b * i << endl; vane = 1; break; }
					i++;
				}
				if(vane == 0) { cout << -1 << endl; }
				
			}
			else {
				cout << seged;
				for (int i = 0; i < c - (trunc(log10(seged)) + 1); i++)
				{
					cout << 0;
				}
				cout << endl;
			}
			
		}
	}
}

