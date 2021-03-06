// 安定結婚問題
// test@uva.live-archive3837

const int N = 28;

int prefer[N][N]; // 男性の結婚したい順([0]={0},[][0]=0)
int fiancee[N]; // 女性から見た結婚相手([]=0)
int rank[N][N]; // 女性の結婚したい度([][0]=N+1)
bool use[N];

// O(N^2)
void stableMarriage(int n)
{
	fill(fiancee, fiancee+N, 0);
	int next[N] = { 0 }; // 何番目に結婚したい相手と結婚したか

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
