//
// 逆ポーランド記法に変換
// test@uva727
//
string toPorlish(const string &str)
{
	string pld = "";
	stack<char> st;

	for (int i=0; i < str.length(); i++) {
		char now = str[i];
		if (isdigit(now)) {
			pld += now;
			continue;
		}
		else if (now==')') {
			while (true) {
				if (st.top()=='(') {
					st.pop();	break;
				}
				pld += st.top();
				st.pop();
			}
			continue;
		}
		else if (now=='(') {
			st.push(now);
			continue;
		}

		while (true) {
			if (st.empty() || st.top()=='(') {
				st.push(now);	break;
			}
			if ((now=='*' || now=='/') && (st.top()=='+' || st.top()=='-')) {
				st.push(now);	break;
			}
			else {
				pld += st.top();
				st.pop();
			}
		}
	}
	while (!st.empty()) {
		pld += st.top();
		st.pop();
	}
	return pld;
}
