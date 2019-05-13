#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int>* getShortestPath(vector<int>* adj, int cityc, int start, int goal){
    int* prev = new int[cityc+1]{0};
    prev[start] = -1;
    queue<int> q;
    q.push(start);

    while(!q.empty())
    {
        bool found = false;
        int a = q.front();
        q.pop();

        for(auto c : adj[a]) //for each connected
        {
            if(prev[c] != 0) continue;

            prev[c] = a;
            q.push(c);

            if(c == goal)
            {
                found = true;
                break;
            }
        }

        if(found){

            vector<int>* path = new vector<int>;
            path->push_back(goal);
            int c = prev[goal];

            while(c != 0 && c != -1)
            {
                path->push_back(c);
                c = prev[c];
            }

            delete[] prev;
            return path;
        }
    }
    //no route found

    delete[] prev;
    return new vector<int>{goal};
}



int main(){
    iostream::sync_with_stdio(false);

    int cityc, eva, adam, goal, routec;
    cin >> cityc >> eva >> adam >> goal >> routec;

    vector<int>* adj = new vector<int>[cityc+1]; //index from 1

    for(int i=0; i<routec; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    vector<int>* epath = getShortestPath(adj, cityc, eva, goal);
    vector<int>* apath = getShortestPath(adj, cityc, adam, goal);

    if(apath->size() == 1 || epath->size() == 1)
    {
        cout << "0 0" << endl;
        return 0;
    }

    cout << epath->size() << " " << apath->size() << endl;
    for(auto it = epath->rbegin(); it != epath->rend(); ++it) cout << *it << " ";
    cout << endl;
    for(auto it = apath->rbegin(); it != apath->rend(); ++it) cout << *it << " ";
    cout << endl;
}