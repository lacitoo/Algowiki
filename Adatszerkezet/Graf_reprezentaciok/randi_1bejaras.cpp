#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    iostream::sync_with_stdio(false);

    int cityc, eva, adam, goal, routec;
    cin >> cityc >> eva >> adam >> goal >> routec;

    vector<int>* adj = new vector<int>[cityc+1]; //index from 1

    for(int i=0; i<routec; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
    }


    /* PATHFINDING */

    int* prev = new int[cityc+1]{0};
    prev[goal] = -1;
    queue<int> q;
    q.push(goal);
    bool foundAdam = false, foundEva = false;
    vector<int> epath, apath;

    while(!q.empty() && (!foundEva || !foundAdam))
    {
        int a = q.front();
        q.pop();

        for(int c : adj[a]) //for each connected node
        {
            if(prev[c] != 0) continue;

            prev[c] = a;
            q.push(c);

            if(c == eva)
            {
                epath.push_back(eva);
                int current = prev[eva];

                while(current != 0 && current!= -1)
                {
                    epath.push_back(current);
                    current = prev[current];
                }

                foundEva = true;
            }
            else if(c == adam)
            {
                apath.push_back(adam);
                int current = prev[adam];

                while(current != 0 && current!= -1)
                {
                    apath.push_back(current);
                    current = prev[current];
                }

                foundAdam = true;
            }
        }
    }

    delete[] prev;

    if(!foundAdam || !foundEva)
    {
        cout << "0 0" << endl;
        return 0;
    }

    cout << epath.size() << " " << apath.size() << endl;
    for(auto a : epath) cout << a << " ";
    cout << endl;
    for(auto a : apath) cout << a << " ";
    cout << endl;
}