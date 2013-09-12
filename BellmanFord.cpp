// Å’ZŒo˜H‚ğ‹‚ß‚é
// •‰‚ÌƒGƒbƒW‚à‰Â
// test@558
const int N = 101;
const int NULL_P = -1;

int adj[N][N];
int p[N];
int d[N];
int n;

void init(int s)
{
	for (int i=0; i < n; ++i) {
		d[i] = INT_MAX;
		p[i] = NULL_P;
	}
	d[s] = 0;
}

void relax(int u, int v)
{
	if (d[v] > d[u] + adj[u][v]) {
		d[v] = d[u] + adj[u][v];
		p[v] = u;
	}
}

// return : •‰‚Ì•Â˜H‚ª‚ ‚ê‚Î false
bool bellmanFord(int s)
{
	init(s);
	for (int i=0; i < n; ++i) {
		for (int j=0; j < n; ++j) {
			if (adj[i][j]==NULL_P) continue;
			relax(i, j);
		}
	}
	for (int i=0; i < n; ++i) {
		for (int j=0; j < n; ++j) {
			if (adj[i][j]==NULL_P) continue;
			if (d[j] > d[i] + adj[i][j]) {
				return false; // •‰‚Ì•Â˜H‚ğ‚Â
			}
		}
	}
	return true;
}
