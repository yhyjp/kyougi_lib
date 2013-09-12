const int N=100;
const int W_MAX = 100*N*N;
int adj[N][N];

// test@uva821
void warshallFloyd()
{
	for (int i=0; i < N; ++i) {
		for (int j=0; j < N; ++j) {
			for (int k=0; k < N; ++k) {
				adj[j][k] = min(adj[j][k], adj[j][i] + adj[i][k]);
			}
		}
	}
}