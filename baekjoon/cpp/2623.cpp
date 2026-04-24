#include <bits/stdc++.h>
using namespace std;
int N, PD, in[1001], M, singer;
vector<int> vect[1001], tmp;
queue<int> q, ans;
void topo() {
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		ans.push(now);
		for (int i = 0; i < vect[now].size(); i++) {
			int next = vect[now][i];

			if (--in[next] == 0)
				q.push(next);
		}
	}
	if (ans.size() != N)
		cout << 0;
	else {
		while (!ans.empty()) {
			cout << ans.front() << '\n';
			ans.pop();
		}
	}
}

int main() {
	cin >> N >> PD;
	while (PD--) {
		cin >> M;
		while (M--) {
			cin >> singer;
			tmp.push_back(singer);
		}
		for (int i = 0; i < tmp.size() - 1; i++) {
			in[tmp.at(i + 1)]++;
			vect[tmp[i]].push_back(tmp.at(i + 1));
		}
		tmp.clear();
	}
	for (int i = 1; i <= N; i++) {
		if (in[i] == 0)
			q.push(i);
	}
	topo();
	return 0;
}