#include <iostream>

using namespace std;


int tomb[100];

int max_(int a, int b, int c)
{
	int max_ = a;
	if (max_ < b)
	{
		max_ = b;
	}
	if (max_ < c)
	{
		max_ = c;
	}
	return max_;
}

int main()
{
    int n;

    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>tomb[i];
    }

    int a1 = 0;
	int b1 = 0;
	int c1 = 0;

	for (int i = 0; i < n; i++)
	{
		int c2 = c1;
		c2 = max_(a1, b1, c2);

		int a2 = 0;
		if (tomb[i] == 1 || tomb[i] == 3)
		{
			a2 = max_(a2, c1, b1) + 1;
		}

		int b2 = 0;
		if (tomb[i] == 2 || tomb[i] == 3)
		{
			b2 = max_(a1, c1, b2) + 1;
		}

		a1 = a2;
		c1 = c2;
		b1 = b2;

	}

	cout<<n-max_(a1, b1, c1)<<endl;


    return 0;
}
