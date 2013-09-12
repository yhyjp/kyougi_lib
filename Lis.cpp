
const int N = 1000;

// test@uva497
void lis(const vector<int> &num, vector<int> &result)
{
	int t[N], parent[N];
	for (int i=0; i < num.size(); ++i) {
		t[i] = 1;
		parent[i] = -1;
		for (int j=0; j < i; ++j) {
			if (num[i] > num[j] && t[i] < t[j]+1)  {
				t[i] = t[j]+1;
				parent[i] = j;
			}
		}
	}

	int maxi = 0;
	for (int i=0; i < num.size(); ++i) {
		if (t[maxi] < t[i]) maxi = i;
	}

	int p = maxi;
	while (p!=-1) {
		result.push_back(num[p]);
		p = parent[p];
	}
	reverse(result.begin(), result.end());
}
