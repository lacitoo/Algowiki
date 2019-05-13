#include <iostream>
#include <vector>
using namespace std;

class Node
{
    public:
        Node *left;
        Node *right;
        int num;
        int value;

        Node(Node *left, Node *right, int num, int value) : 
        left(left), right(right), num(num), value(value)
        {}
};

//értékek gyakorisága
class Freq{
    public:
        int freq;
        int val;

        Freq();
        Freq(int f, int v) : freq(f), val(v){};
};

vector<Freq> freqs;

//rekurzívan
void getLastLeaves(Node *n)
{
    if(n->left == NULL) //levél
    {
        //keressük az értéket a gyakoriságok között
        int i=0;
        while(i<freqs.size() && freqs[i].val != n->value) ++i;
        if(i == freqs.size()) freqs.push_back(Freq(1, n->value));
        else freqs[i].freq++;
    }
    else
    {
        getLastLeaves(n->left);
        getLastLeaves(n->right);
    }
    
}


int main()
{
    std::ios::sync_with_stdio(false); //gyorsabb input

    int qcount;
    cin >> qcount;

    Node* *nodes = new Node*[qcount*2+1];
    nodes[1] = new Node(NULL, NULL, 1, 0); //a gyoker nodeot elore letrehozzuk

    for(int i=1; i<=qcount; ++i)
    {
        int t, f; //igen es nem valasz utan kovetkezo kerdes
        cin >> t >> f;

        nodes[i]->left = new Node(NULL, NULL, t, nodes[i]->value+1);
        nodes[t] = nodes[i]->left;
        nodes[i]->right = new Node(NULL, NULL, f, nodes[i]->value-1);
        nodes[f] = nodes[i]->right;
    }

    getLastLeaves(nodes[1]); //freqs kitoltese

    //leggyakoribb es legkisebb erteku elem megkeresese
    Freq maxf = Freq(0,0);
    for(int i=0; i<freqs.size(); ++i)
    {
        if(freqs[i].freq > maxf.freq || (freqs[i].freq == maxf.freq && freqs[i].val < maxf.val))
        {
            maxf = freqs[i];
        }
    }

    cout << maxf.val << " " << maxf.freq << endl;
}