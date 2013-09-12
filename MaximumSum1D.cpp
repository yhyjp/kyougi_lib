// ŸŒ³‚Ìmaximum-sum‚ğ‹‚ß‚é
#include <iostream>
 
using namespace std;
 
int main( void )
{
	while (true) {
		int N;
		cin >> N;
		if (N==0) break;
 
		int a[5000];
		for(int i = 0; i < N; i++) cin >> a[i];

		int t = 0;
		int s = a[0]-1;
		for (int i = 0; i < N; i++) {
			t = t + a[i];
			if (t > s) s = t;
			if (t < 0) t = 0;
		}
		cout << s << endl;
	}

	return 0;
}