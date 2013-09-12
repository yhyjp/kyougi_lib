// s-tŠÔ‚Ìk”Ô–Ú‚É’Z‚¢Œo˜H‚ğ‹‚ß‚é
// test@10740

const int N = 100;
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

// s-tŠÔ‚Ìk”Ô–Ú‚ÌÅ’Z‹——£‚ğ•Ô‚·
// n = ƒm[ƒh”
// ‚½‚Ç‚è’…‚¯‚È‚¯‚ê‚Î -1 ‚ğ•Ô‚·
int k_dijkstra(const int s, const int t, const int n, const int k)
{
	vector<int> cost[N];
	int visit[N] = { 0 };

	priority_queue<Node> node;
	node.push(Node(s, 0));

	while (!node.empty()) {
		Node now = node.top();
		node.pop();
		if (visit[now.n]==k) continue;
		visit[now.n]++;
		cost[now.n].push_back(now.w);
		if (now.n==t && cost[t].size()==k) {
			return  now.w;
		}
		for (int i=0; i < n; ++i) {
			if (visit[i]>=k) continue;
			if (adj[now.n][i]==UNCONNECTED) continue;
			int newCost = now.w+adj[now.n][i];
			node.push(Node(i, newCost));
		}
	}

	return -1;
}
