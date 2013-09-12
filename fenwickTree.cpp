struct fenwickTree
{
  vector<int> x;

  fenwickTree(int n) : x(n, 0) { }

  int sum(int i, int j)
  {
    if (i == 0) {
      int S = 0;
      for (j; j >= 0; j = (j & (j + 1)) - 1) {
        S += x[j];
      }
      return S;
    }
    else {
      return sum(0, j) - sum(0, i-1);
    }
  }

  void add(int k, int a)
  {
    for (; k < x.size(); k |= k+1) {
      x[k] += a;
    }
  }
};
