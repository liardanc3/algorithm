#include <bits/stdc++.h>
#include <assert.h>
#define int long long

using namespace std;

stack<int> st;
vector<int> vect[101];
int N, cost[101], total, visited[101], finished[101], cnt;
string tmp;
int dfs(int now) {
	int p = visited[now] = cnt++;
	st.push(now);
	for (int next : vect[now]) {
		if (!visited[next])
			p = min(p, dfs(next));
		else if (!finished[next])
			p = min(p, visited[next]);
	}
	if (p == visited[now]) {
		int mn = 1e9;
		while (st.top() != now) {
			mn = min(mn, cost[st.top()]);
			finished[st.top()] = 1;
			st.pop();
		}
		mn = min(mn, cost[st.top()]);
		finished[st.top()] = 1;
		st.pop();
		total += mn;
	}
	return p;
}
signed main() {
	[&]() {
		ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
		cin >> N;
		for (int i = 1; i <= N; i++)
			cin >> cost[i];
		for (int i = 1; i <= N; i++) {
			cin >> tmp;
			for (int j = 1; j <= N; j++) {
				if (tmp[j - 1] == '1')
					vect[i].push_back(j);
			}
		}
	}();
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			cnt = 1;
			dfs(i);
		}
	}
	cout << total;
	return 0;
}
