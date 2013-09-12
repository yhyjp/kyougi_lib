
class DisjointSet {
private:
	map<int, int> rank, parent;
public:
	DisjointSet() : rank(), parent() {}

	bool isExist(int x)
	{
		return (rank.find(x)!=rank.end());
	}
	
	void makeSet(int x)
	{
		parent[x] = x;
		rank[x] = 0;
	}

	void marge(int x, int y)
	{
		link(findSet(x), findSet(y));
	}

	int findSet(int x)
	{
		if (x!=parent[x]) {
			parent[x] = findSet(parent[x]);
		}
		return parent[x];
	}

	bool isSameSet(int x, int y)
	{
		if (x==y) return true;
		if (!isExist(x) || !isExist(y)) return false;
		return (findSet(x)==findSet(y));
	}

	void refreshParent()
	{
		map<int, int>::iterator itr = parent.begin();
		while (itr != parent.end()) {
			findSet(itr->first);
			++itr;
		}
	}

	int maxCount()
	{
		refreshParent();

		map<int, int> c;
		map<int, int>::iterator itr = parent.begin();
		int result = 0;
		while (itr != parent.end()) {
			++c[itr->second];
			result = max(c[itr->second], result);
			++itr;
		}
		return result;
	}

	int groupCount()
	{
		int c = 0;
		map<int, int>::iterator itr = parent.begin();
		while (itr!=parent.end()) {
			if (itr->first==itr->second) ++c;
			++itr;
		}
		return c;
	}

private:
	void link(int x, int y)
	{
		if (rank[x] >  rank[y]) {
			parent[y] = x;
		}
		else {
			parent[x] = y;
			if (rank[x]==rank[y]) rank[y]++;
		}
	}
};
