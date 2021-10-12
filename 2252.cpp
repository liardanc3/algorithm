#include <bits/stdc++.h>
using namespace std;
int N, M, a, b, in[32001];
vector<int> vect[32001];
queue<int> q;

void topo() {
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		cout << now << ' ';
		for (int i = 0; i < vect[now].size(); i++) {
			int next = vect[now][i];

			if (--in[next] == 0)
				q.push(next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		vect[a].push_back(b);
		in[b]++;
	}
	for (int i = 1; i <= N; i++) {
		if (in[i] == 0)
			q.push(i);
	}
	topo();
	return 0;
}