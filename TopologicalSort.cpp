//***************************************************************
// DFSî≈ (path ÇÕãtèá)
// test@10350
//***************************************************************

const int N = 101;
bool adj[N][N];
int n;

void topologicalSort(int now, vector<int> &path, bool used[N])
{
	used[now] = true;
	for (int i=0; i < n; ++i) {
		if (used[i]) continue;
		if (adj[now][i]) topologicalSort(i, path, used);
	}
	path.push_back(now);
}

//***************************************************************
// å„ÇÎÇçÌÇ¡ÇƒÇ¢Ç≠î≈
// test@10350
//***************************************************************

const int N = 101;
bool adj[N][N];
int n;

void topologicalSort(vector<int> &path)
{
	queue<int> que;
	for (int i=0; i < n; ++i) {
		bool f = true;
		for (int j=0; j < n; ++j) {
			if (adj[j][i]) {
				f = false;
				break;
			}
		}
		if (f) que.push(i);
	}

	bool used[N] = { 0 };

	while (que.empty()==false) {
		int now = que.front();
		que.pop();

		if (used[now]) continue;
		used[now] = true;
		path.push_back(now);

		for (int i=0; i < n; ++i) adj[now][i] = false;
		for (int i=0; i < n; ++i) {
			bool f = true;
			for (int j=0; j < n; ++j) {
				if (adj[j][i]) {
					f = false;
					break;
				}
			}
			if (f) que.push(i);
		}
	} 
}