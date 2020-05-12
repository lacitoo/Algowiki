#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, M, K;
	cin >> N >> M >> K;

	vector<int> array(N + 1);

	vector<vector<int>> parok(M);

	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		parok[i].push_back(a);
		parok[i].push_back(b);

		array[a]++;
		array[b]++;
	}

	for (int i = 1; i <= N; i++)
	{
		if (array[i] < K)
		{
			array[i] = 0;
			for (int j = 0; j < parok.size(); j++)
			{
				if (parok[j][0] == i)
				{
					array[parok[j][1]]--;
					parok.erase(parok.begin() + j);
					j--;
				}
				else if (parok[j][1] == i)
				{
					array[parok[j][0]]--;
					parok.erase(parok.begin() + j);
					j--;
				}
			}
		}
	}

	vector<int> all;

	for (int i = 1; i <= N; i++)
	{
		if (array[i] >= K)
		{
			all.push_back(i);
		}
	}

	cout << all.size() << endl;
	for (int i = 0; i < all.size(); i++)
	{
		cout << all[i] << " ";
	}
	cout << endl;

	return 0;
}
