void bfs(int start){
	queue<int> q;
	q.push(start);
	visited[start] = true;
	while(!q.empty()){
		int current = q.front();
		q.pop(); //torles
		for (int v : G[current]){ //szomszedok
			if(!visited[v]){
				q.push(v);
				visited[v] = true;
			}
		}
	}
}
