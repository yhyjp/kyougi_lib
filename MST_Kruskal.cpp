// 最小全域木を求める
// (DisjointSetを使用)
// test@uva10034

struct Edge
{
	int src, dst;
	double cost;
	Edge(int s, int d, double c=0)
		: src(s), dst(d), cost(c)
	{}
	bool operator<(const Edge &e) const {
		return cost < e.cost;
	}
};

typedef vector<Edge> Edges;

// result : 最小全域木
// return : エッジの総コスト
double kruskal(Edges edge, Edges result, const int n)
{
	double cost = 0.0;
	DisjointSet ds;
	for (int i=0; i < n; ++i) ds.makeSet(i);
	sort(edge.begin(), edge.end());

	for (int i=0; i < edge.size(); ++i) {
		if (ds.findSet(edge[i].src) != ds.findSet(edge[i].dst)) {
			result.push_back(edge[i]);
			cost += edge[i].cost;
			ds.marge(edge[i].src, edge[i].dst);
		}
	}
	return cost;
}
