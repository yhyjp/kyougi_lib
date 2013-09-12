//
// MaximumFlow を EdmondsKarp で求める
// O(E^2 * V)
//
// test@uva820
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

const int UNCONNECTED = 0;

const int N=101;
int adj[N][N];
int n;

int flow[N][N]; // u,v間のフロー
int cap[N][N]; // u,v間の許容量

typedef pair<int,int> Edge;
typedef vector<Edge> Edges;

// BFSで増加可能経路を求める
void getGf(int s, int t, Edges &gf, int &minFlow)
{
	gf.clear();

	int parent[N];
	fill(parent, parent+N, -1);
	queue<int> que;
	que.push(s);

	while (que.empty()==false) {
		int now = que.front();
		que.pop();
		if (now==t) break;
		for (int v=0; v < n; ++v) {
			if (cap[now][v]-flow[now][v]<=0 || parent[v]!=-1) continue;
			parent[v] = now;
			que.push(v);
		}
	}
	if (parent[t]==-1) return;

	minFlow = INT_MAX;
	int p = t;
	while (p!=s) {
		int c = cap[parent[p]][p]-flow[parent[p]][p];
		minFlow = min(minFlow, c);
		gf.push_back(Edge(parent[p], p));
		p = parent[p];
	}
}

// s から t までの最大フローを求める
int edmondsKarp(const int s, const int t)
{
	fill(&flow[0][0], &flow[n-1][n], 0);
	copy(&adj[0][0], &adj[n-1][n], &cap[0][0]);
	
	int cost = 0;
	int minFlow = 0;
	Edges gf;
	while (getGf(s, t, gf, minFlow), gf.empty()==false)
	{
		for (int i=0; i < gf.size(); ++i) {
			int u = gf[i].first;
			int v = gf[i].second;
			flow[u][v] += minFlow;
			flow[v][u] -= minFlow;
		}
		cost += minFlow;
	}
	return cost;
}
