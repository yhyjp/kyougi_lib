//
// KMP法で文字列から文字列を探す
// O(n + m)
//
// verified@ UVa10298
//
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int N = 1000001; // 文字列の長さ
int table[N];

/**
 * word : 検索するワード
 */
void makeTable(const string &word)
{
	int i=2, j=0;
	table[0] = -1;
	table[1] = 0;

	while (i < word.length()) {
		if (word[i-1] == word[j]) {
			table[i] = j+1;
			++i;
			++j;
		}
		else if (j > 0) j = table[j];
		else {
			table[i] = 0;
			i = i + 1;
		}
	}
}

/**
 * str 内のどの位置で word が出現するかを返す。
 *
 * str : 検索対称の文字列
 * word : 検索するワード
 *
 * @reamark
 *  先に makeTable を呼ばなくてはいけない
 */
int kmp(const string &str, const string &word)
{
	int m = 0;
	int i = 0;
	while (m+i < str.length()) {
		if (word[i] == str[m+i]) {
			++i;
			if (i == word.length()) return m;
		}
		else {
			m = m + i - table[i];
			if (i > 0) i = table[i];
		}
	}
	return str.length();
}