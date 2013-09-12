
// 強連結成分分解
// test@uva247

const int N = 101;
bool adj[N][N];
int n;

void dfs(const int iNode, vector<int>& order, vector<bool>& visited)
{
	if (!visited[iNode]) {
		visited[iNode] = true;
		for(int i = 0; i < n; i++) {
			if (adj[iNode][i]) {
				dfs(i, order, visited);
			}
		}
		order.push_back(iNode);
	}
}


// components : 強連結成分
void scc(vector<vector<int> > &components)
{
	vector<bool> visited(n, false);
	vector<int> order;
	for(int i = 0; i < n; i++) {
		dfs(i, order, visited);
	}
	reverse(order.begin(), order.end());

	// グラフを反転
	for (int i=0; i < n; ++i) {
		for (int j=i+1; j < n; ++j) {
			swap(adj[i][j], adj[j][i]);
		}
	}

	visited.assign(n, false);
	for(int i = 0; i < n; i++) {
		if (visited[order[i]]) continue;
		components.push_back(vector<int>());
		dfs(order[i], components.back(), visited);
	}

	// 元に戻す
	for (int i=0; i < n; ++i) {
		for (int j=i+1; j < n; ++j) {
			swap(adj[i][j], adj[j][i]);
		}
	}
}



/*
// リストVer
// isn't tested

typedef vector<vector<Edge> > Graph;

void dfs(const int iNode, Graph &g, vector<int>& order, vector<bool>& visited)
{
	if (!visited[iNode]) {
		visited[iNode] = true;
		const Edges &edges = g[iNode];
		for(int i = 0; i < edges.size(); i++) {
			dfs(edges[i].dest, g, order, visited);
		}
		order.push_back(iNode);
	}
}


/// 強連結成分分解
void scc(Graph &g, vector<vector<int> > &components)
{
	const int n = g.size();

	vector<bool> visited(n, false);
	vector<int> order;
	for(int i = 0; i < n; i++) {
		dfs(i, g, order, visited);
	}
	reverse(order.begin(), order.end());


	// グラフを反転
	Graph rGraph(n);
	for (int i=0; i < n; ++i) {
		const Edges &edges = g[i];
		for (int j=0; j < edges.size(); ++j) {
			Edge e(edges[j].dest, edges[j].src);
			rGraph[edges[j].dest].push_back(e);
		}
	}

	visited.assign(n, false);
	for(int i = 0; i < n; i++) {
		if (visited[order[i]]) continue;
		components.push_back(vector<int>());
		dfs(order[i], rGraph, components.back(), visited);
	}

}
*/