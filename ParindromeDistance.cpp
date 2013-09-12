// 文字を回文にするのに必要な手数を求める
// test@uva10739

#include <string> 
#include <algorithm>
using namespace std;

const int N = 1001;
int d[N][N]; // fill(&d[0][0], &d[N-1][N], 0);

// s[i]～s[j]
// call: parindromeDistance(s, 0, s.length()-1)
int parindromeDistance(const string &s, int i, int j)
{
	if (j-i < 1) return 0;
	if (d[i][j]!=0) return d[i][j];
	if (s[i]==s[j]) {
		d[i][j] = parindromeDistance(s, i+1, j-1);
		return d[i][j];
	}
	else {
		int a = parindromeDistance(s, i+1, j); // 左を削除
		a = min(a, parindromeDistance(s, i, j-1)); // 右を削除
		a = min(a, parindromeDistance(s, i+1, j-1)); // 文字を変更
		d[i][j] = (1 + a);
		return d[i][j];
	}
}
