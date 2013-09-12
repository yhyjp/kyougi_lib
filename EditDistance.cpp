#include <iostream>
#include <string> 
#include <algorithm>
using namespace std;
 
int main(void)
{
	string s1, s2;
	cin >> s1 >> s2;

	int d[100][100] = { 0 };
 
	for (int i=0; i <= s1.length(); i++) d[i][0] = i;
	for (int i=0; i <= s2.length(); i++) d[0][i] = i;
 
	for (int i=1; i <= s1.length(); i++) {
		for (int j=1; j <= s2.length(); j++) {
			d[i][j] = min( d[i-1][j]+1, d[i][j-1]+1 ); // •¶Žš‚Ì‘}“ü, •¶Žš‚Ìíœ
			d[i][j] = min( d[i-1][j-1]+(s1[i-1]!=s2[j-1]), d[i][j] ); // •¶Žš‚Ì’uŠ·
			cout << d[i][j] << " ";
		}
		cout << endl;
	}

	cout << d[s1.length()][s2.length()] << endl;

	return 0;
}
