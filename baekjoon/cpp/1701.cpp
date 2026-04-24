#include <bits/stdc++.h>
using namespace std;
int makeNext(string str) {
	int j = 0, nxt[5000]{ 0, };
	for (int i = 1; i < str.size(); i++) {
		while (j > 0 && str[i] != str[j])
			j = nxt[j - 1];
		if (str[i] == str[j])
			nxt[i] = ++j;
	}
	return *max_element(&nxt[0], &nxt[5000]);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int mx = 0;
	string str;
	cin >> str;
	for (int i = 0; i < str.size() - 1; i++) {
		string tmp = str.substr(i, str.size());
		mx = max(mx, makeNext(tmp));
	}
	cout << mx;
	return 0;
}