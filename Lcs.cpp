
// lcs
// test@uva10405

static const int MAX = 1001;
int t[MAX][MAX] = { 0 };

int lcs(const string &s1, const string &s2)
{
	for (int i=1; i <= s1.length(); i++) {
		for (int j=1; j <= s2.length(); j++) {
			t[i][j] = max(t[i-1][j], t[i][j-1]);
			if (s1[i-1]==s2[j-1]) {
				t[i][j] = max(t[i-1][j-1]+1, t[i][j]);
			}
		}
	}
	return t[s1.length()][s2.length()];
}