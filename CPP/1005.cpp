#include <bits/stdc++.h>
using namespace std;
int T, N, K, D[1001], X, Y, W, cnt[1001], in[1001];
queue<int> q;
int main() {
	cin >> T;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (T--) {
		vector<int> vect[1001];
		memset(in, 0, sizeof(in));
		memset(cnt, 0, sizeof(cnt));
		cin >> N >> K;
		for (int i = 1; i <= N; i++)
			cin >> D[i];
		for (int i = 0; i < K; i++) {
			cin >> X >> Y;
			vect[X].push_back(Y);
			in[Y]++;
		}
		cin >> W;

		for (int i = 1; i <= N; i++) {
			if (in[i] == 0) {
				q.push(i);
				cnt[i] = D[i];
			}
		}

		while (!q.empty()) {
			int now = q.front();
			q.pop();

			for (int i = 0; i < vect[now].size(); i++) {
				int next = vect[now].at(i);

				cnt[next] = max(cnt[next], cnt[now] + D[next]);
				in[next]--;
				if (in[next] == 0)
					q.push(next);
			}
		}
		cout << cnt[W] << '\n';
	}

	return 0;
}