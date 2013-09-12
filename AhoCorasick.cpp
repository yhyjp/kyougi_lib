//
// Aho-Corasickで複数パターンの検索
// O(n + m)
//
// verified@ UVa10679
//
#include <iostream>
#include <string>
#include <queue>
#include <cstdio>
using namespace std;

const int C_LIM = 257; // charで表現出来るサイズ
const int W_LEN = 1001; // キーワード長
const int W_NUM = 1001; // キーワード数

struct Node
{
	Node *next[C_LIM];
	vector<int> out;
	vector<int> accept;

	Node() : out(), accept()
	{
		fill(next, next+C_LIM, (Node*)0);
	}

	void free()
	{
		for (int i=0; next[i]; ++i) {
			next[i]->free();
			delete next[i];
			next[i] = 0;
		}
	}
};

Node *root;

/**
 * p : オートマトンを作る為の文字列たち
 * pn : p の個数
 *
 * @remark
 *  'A'<= c <='z' (c:入力)
 */
void buildTree(char p[W_NUM][W_LEN], const int pn)
{
	// keyword tree & out function
	// O(|P1|+...+|Pn|) |Pi| : pattern length
	root = new Node();
	for (int i=0; i < pn; ++i) {
		Node *t = root;
		for (int j=0; p[i][j]; ++j) {
			const char c = p[i][j];
			if (t->next[c] == 0) {
				t->next[c] = new Node();
			}
			t = t->next[c];
		}
		t->accept.push_back(i);
	}

	// failture function
	queue<Node*> que;
	for (int c='A'; c <= 'z'; ++c) {
		if (root->next[c]) {
			root->next[c]->next[0] = root;
			que.push(root->next[c]);
		}
		else {
			root->next[c] = root;
		}
	}
	while (!que.empty()) {
		Node *t = que.front();
		que.pop();
		for (int c='A'; c <= 'z'; ++c) {
			if (t->next[c]) {
				que.push(t->next[c]);
				Node *r = t->next[0];
				while (r->next[c]==0) r = r->next[0];
				t->next[c]->next[0] = r->next[c];
			}
		}
	}
}

/**
 * base : 探す元になる文字列
 * root : 生成されたオートマトンのルート
 * result : 何回出現したかを記録
 *
 * @remark
 *   これを呼ぶ前に buildTree を呼んでおく。
 *   result の初期化を忘れない。
 */
void checkMatch(const char *base, Node *root, int *result)
{
	Node *v = root;
	const int n = strlen(base);
	for (int i=0; i < n; ++i) {
		const char c = base[i];
		while (!v->next[c]) v = v->next[0];
		v = v->next[c];
		for (int j=0; j < v->accept.size(); ++j) {
			++result[v->accept[j]];
		}
	}
}