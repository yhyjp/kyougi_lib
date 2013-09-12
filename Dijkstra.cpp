// dijkstra
// test@uva0423など

const int N = 1500;
int adj[N][N];
const int UNCONNECTED = -1;

struct Node {
	int n;
	int w;
	Node(int _n, int _w) : n(_n), w(_w) {}
	bool operator<(const Node &nd) const {
		return w > nd.w;
	}
};

// s-t間の最短距離を返す
// n = ノード数
// たどり着けなければ -1 を返す
int dijkstra(const int s, const int t, vector<int> &path, const int n)
{
	int cost[N];
	int parent[N]; // パス生成用
	bool visit[N] = { 0 };
	fill(cost, cost+N, INT_MAX);
	fill(parent, parent+N, -1);

	priority_queue<Node> node;
	node.push(Node(s, 0));
	cost[s] = 0;

	int dist = INT_MAX;
	while (!node.empty()) {
		Node now = node.top();
		node.pop();
		if (visit[now.n]) continue;
		visit[now.n] = true;
		if (now.n==t) {
			dist = now.w;
			break;
		}
		for (int i=0; i < n; ++i) {
			if (visit[i]) continue;
			if (adj[now.n][i]==UNCONNECTED) continue;
			int newCost = now.w+adj[now.n][i];
			if (cost[i] > newCost) {
				parent[i] = now.n;
				cost[i] = newCost;
				node.push(Node(i, newCost));
			}
		}
	}
	if (dist==INT_MAX) return -1;

	// パス生成
	int v = t;
	while (v!=-1) {
		path.push_back(v);
		v = parent[v];
	}
	reverse(path.begin(), path.end());
	return dist;
}








const int N = 501;
int adj[N][N];

struct Node {
	int n;
	int w;
	Node(int _n, int _w) : n(_n), w(_w) {}
	bool operator<(const Node &nd) const {
		return w > nd.w;
	}
};

int dijkstra(const int s, const int t, const int n)
{
	int cost[N];
	fill(cost, cost+N, INT_MAX);

	priority_queue<Node> node;
	node.push(Node(s, 0));

	while (!node.empty()) {
		Node now = node.top();
		node.pop();

		if (cost[now.n] != INT_MAX) continue;
		cost[now.n] = now.w;

		if (now.n==t) return now.w;

		for (int i=0; i < n; ++i) {
			if (cost[i]!=INT_MAX) continue;
			if (adj[now.n][i]==-1) continue;
			int newCost = now.w + adj[now.n][i];
			node.push(Node(i, newCost));
		}
	}
	return -1;
}