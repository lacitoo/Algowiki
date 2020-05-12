#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, P;
	cin >> N >> P;

	int max = 1;
	int current = P;
	int length = 0;

	vector<int> eddigiek;

	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		eddigiek.push_back(a);

		current -= a;
		if (current > 0)
		{
			length++;
		}
		else
		{
			if (length > max)
			{
				max = length;
			}

			current += eddigiek[0];
			eddigiek.erase(eddigiek.begin());

			length = 1;
		}
	}

	cout << max;

	return 0;
}