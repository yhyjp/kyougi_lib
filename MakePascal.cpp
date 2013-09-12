
const int N = 21;
long long c[N][N];

void makePascal()
{
	fill(&c[0][0], &c[N-1][N], 0);
	for (int i=1; i < N; ++i) {
		c[i][1] = c[i][i] = 1;
		for (int j=2; j < i; ++j) {
			c[i][j] = c[i-1][j-1]+c[i-1][j];
		}
	}
}
