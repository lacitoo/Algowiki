using namespace std;
#include <iostream>
#include <vector>
#include <string>

string dns;

int seged(int hossz) {
    for (int i = 0; i < dns.length() - hossz+1; i++) {
        int mik[4] = {0};
        for (int j = i; j < hossz+i; j++) {
            if (dns[j] == 'A') { mik[0]++; }
            else if(dns[j] == 'C') { mik[1]++; }
            else if (dns[j] == 'G') { mik[2]++; }
            else if (dns[j] == 'T') { mik[3]++; }
        }
        if (mik[0] == 0 || mik[1] == 0 || mik[2] == 0 || mik[3] == 0) { return 1; }
    }
    return 0;
}

int main()
{
    cin >> dns;
    int mik[4] = { 0 };
    for (int j = 0; j < dns.length(); j++) {
        if (dns[j] == 'A') { mik[0]++; }
        else if (dns[j] == 'C') { mik[1]++; }
        else if (dns[j] == 'G') { mik[2]++; }
        else if (dns[j] == 'T') { mik[3]++; }
    }
    if (mik[0] == 0 || mik[1] == 0 || mik[2] == 0 || mik[3] == 0) { cout << 0; }
    else {
        
        int hossz = 4;
        while (seged(hossz) != 0) { hossz++; }
        cout << hossz;
        

        /*int hossz = dns.length() / 2;
        int aktualis = hossz;
        int elozo = hossz;
        while (1) {
            if (seged(hossz) == 1) {
                hossz = hossz + hossz / 2;
                elozo = aktualis;
                aktualis = hossz;
            }
            else {
                hossz = hossz - hossz / 2;
                elozo = aktualis;
                aktualis = hossz;
                if()
            }
        }*/
    }
    
}

/*  int b = 4;
   
    }*/