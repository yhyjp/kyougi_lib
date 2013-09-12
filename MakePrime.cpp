
const int N = 1000001;

bool isPrime[N];
vector<int> prime;

void makePrime()
{
	prime.clear();
	fill(isPrime, isPrime+N, true);
	isPrime[0] = isPrime[1] = false;
	prime.push_back(2);
	for (int i=4; i < N; i+=2) isPrime[i]=false;
	for (int i=3; i < N; i+=2) {
		if (isPrime[i]) {
			prime.push_back(i);
			for (int j=i+i; j < N; j+=i) { 
				isPrime[j] = false;
			}
		}
	}
}
