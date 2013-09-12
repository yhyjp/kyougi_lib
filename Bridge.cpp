// ‹´‚ð—ñ‹“‚·‚é
// test@796

const int N = 1001;
bool adj[N][N];
int n;

int dfs(int st, int now, int visitTime[], int c, vector<pair<int,int> > &bridges)
{
	int ret = visitTime[now] = ++c;

	for (int i=0; i < n; ++i) {
		//if (!adj[now][i] && !adj[i][now]) continue;
		if (!adj[now][i]) continue;
		if (visitTime[i] != 0) {
			ret = min(ret, visitTime[i]);
			continue;
		}
		bool t1 = adj[now][i];
		bool t2 = adj[i][now];
		adj[now][i] = adj[i][now] = false;
		int up = dfs(st, i, visitTime, c, bridges);
		if (visitTime[i] <= up) {
			bridges.push_back(make_pair(min(now, i), max(now, i)));
		}
		ret = min(ret, up);
		adj[i][now] = t1;
		adj[now][i] = t2;
	}
	return ret;
}

void bridge(vector<pair<int,int> > &bridges)
{
	int visitTime[N] = { 0 };
	for (int i=0; i < n; ++i) {
		if (visitTime[i] != 0) continue;
		dfs(i, i, visitTime, 0, bridges);
	}
	sort(bridges.begin(), bridges.end());
}

