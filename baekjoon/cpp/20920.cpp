#include <bits/stdc++.h>
using namespace std;

typedef pair<string, int> psi;
map<string, int> m;
vector<psi> vect;

bool cmp(const psi& a, const psi& b) {
	if (a.second != b.second)
		return a.second > b.second;
	if (a.first.size() != b.first.size())
		return a.first.size() > b.first.size();
	return a < b;
}

string tmp;
int N, M;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M;
	while (N--) {
		cin >> tmp;
		if (tmp.size() >= M)
			m[tmp]++;
	}
	for (auto it : m)
		vect.push_back({ it.first, it.second });
	sort(vect.begin(), vect.end(), cmp);
	for (psi ans : vect)
		cout << ans.first << '\n';
	return 0;
}