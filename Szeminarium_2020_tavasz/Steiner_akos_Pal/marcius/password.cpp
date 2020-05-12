#include <iostream>
#include <string>
 
using namespace std;
 
void kovi(int);
 
int main()
{
    int n;
    cin >> n;
 
    string sub[n];
 
    for (int i = 0; i < n; i++)
    {
        cin >> sub[i];
    }
 
    char password[n + 2];
    int length = 0;
 
    int i = 0;
    while (i < n && length < n + 2)
    {
        password[n+2];
        password[0] = sub[i][0];
        password[1] = sub[i][1];
        password[2] = sub[i][2];
        length = 3;
 
        string aktsub[n];
        int aktlen = n;
 
        for (int j = 0; j < n; j++)
        {
            aktsub[j] = sub[j];
        }
 
        aktlen = aktlen - 1;
 
        for (int j = i; j < aktlen; j++)
        {
            aktsub[j] = aktsub[j + 1];
        }
 
        int j = 0;
        while (j < aktlen)
        {
            if (password[length - 2] == aktsub[j][0] && password[length - 1] == aktsub[j][1])
            {
                password[length] = aktsub[j][2];
                length = length + 1;
                aktlen = aktlen - 1;
 
                for (int k = j; k < aktlen; k++)
                {
                    aktsub[k] = aktsub[k + 1];
                }
                j = 0;
            }
            else
            {
                j = j + 1;
            }
        }
        i = i + 1;
    }
 
    if (length == n + 2)
    {
    cout << "YES" << endl;
    for (int i = 0; i < n + 2; i++)
    {
        cout << password[i];
    }
    cout << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
 
 
 
    return 0;
}