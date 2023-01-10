#include <bits/stdc++.h>
using namespace std;
int L, C, arr[16]{ 0, }, visited[16]{ 0, };
vector<char> vect;
vector<string> ans;

void bt(int start, int now) {
	if (now == L) {
		int m = 0, j = 0;
		string _ans = "";
		for (int i = 0; i < now; i++) {
			char ch = vect[arr[i]];
			_ans += ch;
			if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
				m++;
			else j++;
		}
		if (m >= 1 && j >= 2)
			ans.push_back(_ans);
		return;
	}
	for (int i = start; i < C; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			arr[now] = i;
			bt(i + 1, now + 1);
			visited[i] = 0;
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	char tmp;
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		cin >> tmp;
		vect.push_back(tmp);
	}
	sort(vect.begin(), vect.end());
	bt(0, 0);
	for (string str : ans)
		cout << str << '\n';
	return 0;
}