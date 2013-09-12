const int N = 1001;

void createPrime(vector<int> &prime)
{
	bool f[N];
	
	fill(f, f+N, true);
	f[0] = f[1] = false;
	
	for (int i=0; i < N; ++i) {
		if (f[i]) {
			for (int j=i+i; j < N; j+=i) {
				f[j] = false;
			}
		}
	}
	
	for (int i=0; i < N; ++i) {
		if (f[i]) {
			prime.push_back(i);
		}
	}
}

