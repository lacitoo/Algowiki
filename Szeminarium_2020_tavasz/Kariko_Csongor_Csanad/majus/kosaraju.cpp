vector < vector<int> > g, gr; // g az eredeti gráf, gr a transzponáltja

vector<bool> used; // bejártuk-e már az adott csúcsot

vector<int> order, component; // order: az első fázis eredményeként kapott sorrend (itt növekvő sorrendben)
							  // component: ide gyűjtjük az aktuálisan bejárt komponens csúcsait (2. fázisban)


void dfs1 (int v) { // első fázis, topologikus sor felállítása

	used[v] = true;

	for (size_t i=0; i<g[v].size(); ++i)
		if (!used[ g[v][i] ])
			dfs1 (g[v][i]);

	order.push_back (v);
}


void dfs2 (int v) { // második fázis, 'v' komponensének bejárása

	used[v] = true;
	component.push_back (v);

	for (size_t i=0; i<gr[v].size(); ++i)
		if (!used[ gr[v][i] ])
			dfs2 (gr[v][i]);

}


int main() {

	int n;

	... n beolvasása ...

	while(true) {
		int a, b;

		... következő él (a,b) beolvasása ...

		g[a].push_back (b);
		gr[b].push_back (a);
	}


	used.assign (n, false);

	for (int i=0; i<n; ++i)
		if (!used[i])
			dfs1 (i);

	used.assign (n, false);

	for (int i=0; i<n; ++i) {
		int v = order[n-1-i];

		if (!used[v]) {
			dfs2 (v);

			... kiírjuk az aktuális komponenst: 'component' tartalmát ...

			component.clear();
		}
	}
}