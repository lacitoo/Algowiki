#include <iostream>
#include <vector>
#include <queue>
#define MAX_N 200000
#define UNVISITED -1
using namespace std;
 
vector<int> nb[MAX_N];
int distA[MAX_N];
int distB[MAX_N];
 
int main(){
	ios_base::sync_with_stdio(false);
 
	int N, x;
	cin>>N>>x;
	--x;
 
	for(int i = 0; i < N-1; ++i){
		int a, b;
		cin>>a>>b;
		--a; --b;
		nb[a].push_back(b);
		nb[b].push_back(a);
	}
 
	fill(distA, distA+N, UNVISITED);
	fill(distB, distB+N, UNVISITED);
 
	queue<int> bfs;
	bfs.push(0);
	distA[0] = 0;
	while(!bfs.empty()){
		//cerr<<"A visits "<<bfs.front()+1<<" d: "<<distA[bfs.front()]<<"\n";
		for(int n : nb[bfs.front()]){
			if(distA[n] == UNVISITED){
				distA[n] = distA[bfs.front()] + 1;
				bfs.push(n);
			}
		}
		bfs.pop();
	}
 
	bfs.push(x);
	distB[x] = 0;
	int maxDist = distA[x];
	while(!bfs.empty()){
		//cerr<<"B visits "<<bfs.front()+1<<" d: "<<distB[bfs.front()]<<'\n';
		for(int n : nb[bfs.front()]){
			if(distB[n] == UNVISITED && distA[n] > distB[bfs.front()]+1){
				distB[n] = distB[bfs.front()]+1;
				bfs.push(n);
				if(distA[n] > maxDist)
					maxDist = distA[n];
			}
		}
		bfs.pop();
	}
 
	cout<<maxDist*2<<'\n';
	return 0;
}