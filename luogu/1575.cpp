#include <bits/stdc++.h>
using namespace std;

map<string, int> id;
stack<int> o;
stack<int> v;

int main()
{
	id["false"] = 0;
	id["true"] = 1;
	id["not"] = 2;
	id["and"] = 3;
	id["or"] = 4;
	goto normal;

	err:
	cout << "error" << endl;
	return 0;

	normal:
	string tmp;
	while (cin >> tmp) {
		int c = id[tmp];
		if (c <= 1) v.push(c);
		else o.push(c);
	}
	while (!o.empty()) {
		int op = o.top(); o.pop();
		if (op == 2) {
			if (v.empty()) goto err;
			int val = v.top(); v.pop();
			v.push(!val);
		} else if (op == 3) {
			if (v.empty()) goto err;
			int v1 = v.top(); v.pop();
			if (v.empty()) goto err;
			int v2 = v.top(); v.pop();
			v.push(v1 && v2);
		} else {
			if (v.empty()) goto err;
			int v1 = v.top(); v.pop();
			if (v.empty()) goto err;
			int v2 = v.top(); v.pop();
			v.push(v1 || v2);
		}
	}
	if (v.empty()) goto err;
	int ans = v.top(); v.pop();
	if (!v.empty()) goto err;
	cout << (ans ? "true" : "false") << endl;
	return 0;
}