using namespace std;
#include <iostream>
#include <vector>
#include <string>

int main()
{
	string dns;
	cin >> dns;

	int mikK[4] = { 0 };
	for (int j = 0; j < dns.length(); j++) {
		if (dns[j] == 'A') { mikK[0]++; }
		else if (dns[j] == 'C') { mikK[1]++; }
		else if (dns[j] == 'G') { mikK[2]++; }
		else if (dns[j] == 'T') { mikK[3]++; }
	}
	if (mikK[0] == 0 || mikK[1] == 0 || mikK[2] == 0 || mikK[3] == 0) { cout << 0; }
	else {
		int max = 0;
		for (int i = 0; i < dns.length(); i++) {
			int mik[4] = { 0 };
			int db = 1;
			for (int j = i; j < dns.length(); j++) {
				if (dns[j] == 'A') { mik[0]++; }
				else if (dns[j] == 'C') { mik[1]++; }
				else if (dns[j] == 'G') { mik[2]++; }
				else if (dns[j] == 'T') { mik[3]++; }
				db++;
				if (mik[0] != 0 && mik[1] != 0 && mik[2] != 0 && mik[3] != 0) { if (db > max) { max = db; } break; }

			}
		}
		cout << max - 1;
	}

	
}
