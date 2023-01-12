#include <bits/stdc++.h>
using namespace std;
vector<int> dp[1000001];
int ck[1000001],N;

void bfs() {
	queue<int> q;
	q.push(N);
	ck[N] = 1;
	dp[N].push_back(N);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		
		if (now % 3 == 0) {
			if (ck[now / 3] == 0) {
				q.push(now / 3);
				ck[now / 3] = 1;
				for (int i = 0; i < dp[now].size(); i++)
					dp[now / 3].push_back(dp[now].at(i));
				dp[now / 3].push_back(now / 3);
				if (now / 3 == 1) return;
			}
		}
		if (now % 2 == 0) {
			if (ck[now / 2] == 0) {
				q.push(now / 2);
				ck[now / 2] = 1;
				for (int i = 0; i < dp[now].size(); i++)
					dp[now / 2].push_back(dp[now].at(i));
				dp[now / 2].push_back(now / 2);
				if (now / 2 == 1) return;
			}
		}
		if (now - 1 >= 1) {
			if (ck[now - 1] == 0) {
				q.push(now - 1);
				ck[now - 1] = 1;
				for (int i = 0; i < dp[now].size(); i++)
					dp[now -1].push_back(dp[now].at(i));
				dp[now - 1].push_back(now - 1);
				if (now -1 == 1) return;
			}
		}
	}
}

int main() {
	cin >> N;
	bfs();
	cout << dp[1].size() - 1 << '\n';
	for (int i =0; i < dp[1].size(); i++)
		cout << dp[1].at(i) << ' ';
	return 0;
}