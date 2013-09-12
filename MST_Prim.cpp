// test@uva10600

const int N = 101;
int n;
int adj[N][N];


// result : 最小全域木
// if (木が作れなかった) return -1
// else エッジの総コスト
int prim(Edges &result, const int n)
{
	int cost = 0;

	bool visit[N] = { 0 };
	priority_queue<Edge, vector<Edge>, greater<Edge> > que;

	visit[0] = true;
	for (int i=1; i < n; ++i) {
		if (adj[0][i]==0) continue;
		que.push(Edge(0, i, adj[0][i]));
	}

	while (que.empty()==false) {
		Edge now = que.top();
		que.pop();

		if (visit[now.dst]) continue;
		visit[now.dst] = true;
		result.push_back(now);
		cost += now.cost;

		for (int i=0; i < n; i++) {
			if (adj[now.dst][i]==0 || visit[i]) continue;
			que.push(Edge(now.dst, i, adj[now.dst][i]));
		}
	}

	for (int i=0; i < n; ++i) {
		if (visit[i]==false) return -1; // 木が作れていない
	}
	return cost;
}

// 2番目に安いMSTのコストを求める
int secondBestMST(Edges &mst, const int n)
{
	int secondBest = INT_MAX;
	for (int i=0; i < mst.size(); ++i) {
		int t = adj[mst[i].src][mst[i].dst];
		adj[mst[i].src][mst[i].dst] = adj[mst[i].dst][mst[i].src] = 0;

		Edges result;
		int cost = prim(result, n);
		
		adj[mst[i].src][mst[i].dst] = adj[mst[i].dst][mst[i].src] = t;

		if (cost==-1) continue; // 木が作れなかった
		secondBest = min(cost, secondBest);
		adj[mst[i].src][mst[i].dst] = adj[mst[i].dst][mst[i].src] = t;
	}
	return secondBest;
}

