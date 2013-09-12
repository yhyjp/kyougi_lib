
// ハフマン符号を構成する

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

struct Node
{
	int n;
	int freq;
	int left, right;

	Node(int _n=0, int _f=0)
		: n(_n), freq(_f), left(-1), right(-1)
	{};
	bool operator>(const Node &node) const {
		if (freq !=node.freq) return (freq > node.freq);
		return false;
	}
};
typedef vector<Node> Nodes;

Node haffman(vector<Node> &node)
{
	priority_queue<Node, Nodes, greater<Node> > que;
	for (int i=0; i < node.size(); ++i) {
		que.push(node[i]);
	}

	int n = node.size();
	for (int i=0; i < n-1; ++i) {
		Node z;
		z.n = node.size();
		z.left = (que.top()).n; que.pop();
		z.right = (que.top()).n; que.pop();
		z.freq = node[z.left].freq + node[z.right].freq;
		node.push_back(z);
		que.push(z);
	}

	return que.top();
}

void print(int n, const Nodes &node, const vector<char> &cv)
{
	if (node[n].n < cv.size()) {
		cout << cv[node[n].n] << " : " << node[n].freq << endl;
		return;
	}
	else {
		cout << node[n].n << " : " << node[n].freq << endl;
	}
	
	cout << "left:" << endl;
	if (node[n].left >= 0) print(node[n].left, node, cv);
	cout << "right:" << endl;
	if (node[n].right >= 0) print(node[n].right, node, cv);
}

int main()
{
	vector<char> cv;
	Nodes node;
	cv.push_back('a');
	node.push_back(Node(node.size(), 45));
	cv.push_back('b');
	node.push_back(Node(node.size(), 13));
	cv.push_back('c');
	node.push_back(Node(node.size(), 12));
	cv.push_back('d');
	node.push_back(Node(node.size(), 16));
	cv.push_back('e');
	node.push_back(Node(node.size(), 9));
	cv.push_back('f');
	node.push_back(Node(node.size(), 5));

	int root = haffman(node).n;

	print(root, node, cv);

	return 0;
}