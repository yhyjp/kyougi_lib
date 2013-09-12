// ‚QŸŒ³‚Ìmaximum-sum‚ğ‹‚ß‚é
// test@uva‚¢‚­‚Â‚©

#include <iostream>
#include <algorithm>
 
using namespace std;
 
int main(void)
{
	int N;
	cin >> N;
 
	int a[100][100];
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			cin >> a[i][j];

	int S = a[0][0]-1;
	for(int z = 0; z < N; z++) {
		int pr[100] = { 0 };
		for(int x = z; x < N; x++) {
			int t = 0;
			int s = a[x][0]-1;
			for (int i = 0; i < N; i++) {
				pr[i] = pr[i] + a[x][i];
				t = t + pr[i];
				if (t > s) s = t;
				if (t < 0) t = 0;
			}
			if (s > S) S = s;
		}
	}
 
	cout << S << endl;
 
	return 0;
}
