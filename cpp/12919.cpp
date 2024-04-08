#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> tii;

map<tii, int> visited;
string s, t;
void back(int start, int end, int reversed) {
	if (visited[{start, end, reversed}] == 1)
		return;
	visited[{start, end, reversed}] = 1;

	if (abs(start - end) + 1 == s.size()) {
		string tmp = s;
		if (reversed)
			reverse(tmp.begin(), tmp.end());
		if (t.substr(start, end - start + 1) == tmp) {
			cout << 1;
			exit(0);
		}
		return;
	}

	if (!reversed && t[end] == 'A') 
		back(start, end - 1, reversed);
	if (reversed && t[start] == 'A')
		back(start + 1, end, reversed);

	if (!reversed && t[start] == 'B')
		back(start + 1, end, !reversed);
	if (reversed && t[end] == 'B')
		back(start, end - 1, !reversed);
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> s >> t;
	back(0, t.size()-1, 0);
	cout << 0;
	return 0;
}