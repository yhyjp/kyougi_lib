// n個の山(t1,t2,t3...tn)からなるNimゲームの勝ち負けを調べる
// test@uva10165

#include <iostream>
using namespace std;

int main()
{
	int n;
	while (cin>>n,n) {
		int x = 0;
		for (int i=0; i < n; ++i) {
			int t;
			cin >> t;
			x ^= t;
		}
		if (x) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
