#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false); //gyorsabb input

    int qcount;
    cin >> qcount;

    int* nodes = new int[qcount+1]{};
    nodes[1] = 0;
    map<int, int> freqs; //value, frequency

    for(int i=1; i<=qcount; ++i) {
        int t, f; //igen es nem valasz utan kovetkezo kerdes
        cin >> t >> f;

        if (t <= qcount) nodes[t] = nodes[i] + 1; //kerdes
        else //kitalalando
        {
            if(freqs.count(nodes[i]+1) != 0) freqs[nodes[i]+1]++; //benne van mar a mapben?
            else freqs[nodes[i]+1] = 1;
        }
        if (f <= qcount) nodes[f] = nodes[i] - 1;
        else
        {
            if(freqs.count(nodes[i]-1) != 0) freqs[nodes[i]-1]++;
            else freqs[nodes[i]-1] = 1;
        }
    }

    //leggyakoribb es legkisebb erteku elem megkeresese
    pair<int, int> mostFreq = make_pair(0,0);
    for(auto a : freqs)
    {
        if(a.second > mostFreq.second ||
            (a.second == mostFreq.second && a.first < mostFreq.first))
            mostFreq = a;
    }

    cout << mostFreq.first << " " << mostFreq.second << endl;
}