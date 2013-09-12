#include <iostream>
#include <string>
#include <utility>
#include <cctype>
using namespace std;

typedef pair<int, const char*> parsed;

parsed expr(const char *p);
parsed term(const char *p);
parsed fact(const char *p);


parsed expr(const char *p)
{
	parsed r = term(p);
	while (*r.second=='+'||*r.second=='-') {
		char op = *r.second;
		int tmp = r.first;
		r = term(r.second+1);
		if (op=='+') r.first = tmp+r.first;
		else r.first = tmp-r.first;
	}
	return r;
}


parsed term(const char *p)
{
	parsed r = fact(p);
	while (*r.second=='*'||*r.second=='/') {
		char op = *r.second;
		int tmp = r.first;
		r = fact(r.second+1);
		if (op=='*') r.first = tmp*r.first;
		else r.first = tmp/r.first;
	}
	return r;
}

parsed fact(const char *p)
{
	if (isdigit(*p)) {
		int t = *(p++)-'0';
		while (isdigit(*p)) t = t*10 + *(p++)-'0';
		return parsed(t,p);
	}
	else if (*p=='(') {
		parsed r = expr(p+1);
		if (*r.second!=')') exit(0); // invalid input
		return parsed(r.first, r.second+1);
	}
	else {
		exit(0); // invalid input
	}
}

int main()
{
	string s;
	while (cin >> s) {
		cout << expr(s.c_str()).first << endl;
	}
	return 0;
}
