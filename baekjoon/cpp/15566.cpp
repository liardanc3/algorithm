#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, M, a, b, c, d, visited[16]{ 0, };
vector<int> topic[100];
vector<pii> edge[100];
vector<pii> flower;
vector<int> vect(16);
void bt(int idx) {
	if (idx == N+1) {
		for (int i = 1; i <= N; i++) {
			int start = i;
			for (int j = 0; j < edge[start].size(); j++) {
				int end = edge[start][j].first;
				int topi = edge[start][j].second;

				int start_W = topic[vect[start]][topi-1];
				int end_W = topic[vect[end]][topi - 1];

				if (start_W != end_W)
					return;
			}
		}
		cout << "YES\n";
		for (int i = 1; i <= N; i++)
			cout << vect[i] << ' ';
		exit(0);
	}
	for (int i = 1; i <= N; i++) {
		if (visited[i]) continue;
		if (flower[i].first != idx && flower[i].second != idx) continue;

		visited[i] = 1;
		vect.at(idx) = i;
		bt(idx + 1);
		visited[i] = 0;
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c >> d;
		topic[i + 1].push_back(a);
		topic[i + 1].push_back(b);
		topic[i + 1].push_back(c);
		topic[i + 1].push_back(d);
	}
	flower.push_back({ 0,0 });
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		flower.push_back({ a,b });
	}
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		edge[a].push_back({ b,c });
		edge[b].push_back({ a,c });
	}
	bt(1);
	cout << "NO";
	return 0;
}