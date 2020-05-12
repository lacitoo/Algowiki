using namespace std;
#include <iostream>
#include <math.h>

int main()
{
	double n, cd, length;
	cin >> n >> length >> cd;
	double seged = ceil(((n - 1) + (n * length)) / cd);
	if(int(n) % 13 == 0){
		cd = (n-1)+(n-2);
		seged = ceil(((n - 1) + (n * length)) / cd);
		cout << seged;

		/*
		double a = (n * length) / seged;
		if (int(a) % 13 == 0) {
			a--;
			seged = ceil( cd / a);
		}
		cout << seged;
		*/
	}
	else { cout << seged; }
}

