#include <bits/stdc++.h>
using namespace std;
int N, tmp, pay[501], in[501], d[501];
vector<int> vect[501];
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> pay[i];
		while (cin >> tmp) {
			if (tmp == -1) break;
			vect[tmp].push_back(i);
			in[i]++;
		}
	}
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (in[i] == 0) {
			q.push(i);
			d[i] = pay[i];
		}
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < vect[now].size(); i++) {
			int next = vect[now][i];

			d[next] = max(d[next], d[now] + pay[next]);
			in[next]--;
			if (in[next] == 0)
				q.push(next);
		}
	}

	for (int i = 1; i <= N; i++)
		cout << d[i] << '\n';
	return 0;
}