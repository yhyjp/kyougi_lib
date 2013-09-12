// ˆÀ’èŒ‹¥–â‘è
// test@uva.live-archive3837

const int N = 28;

int prefer[N][N]; // ’j«‚ÌŒ‹¥‚µ‚½‚¢‡([0]={0},[][0]=0)
int fiancee[N]; // —«‚©‚çŒ©‚½Œ‹¥‘Šè([]=0)
int rank[N][N]; // —«‚ÌŒ‹¥‚µ‚½‚¢“x([][0]=N+1)
bool use[N];

// O(N^2)
void stableMarriage(int n)
{
	fill(fiancee, fiancee+N, 0);
	int next[N] = { 0 }; // ‰½”Ô–Ú‚ÉŒ‹¥‚µ‚½‚¢‘Šè‚ÆŒ‹¥‚µ‚½‚©

	for (int m=1; m < N; ++m) {
		if (use[m]==false) continue;
		for (int s=m; s!=0;) {
			++next[s];
			int w = prefer[s][next[s]];
			if (rank[w][s] < rank[w][fiancee[w]]) {
				 swap(fiancee[w], s);
			}
		}
	}
}
