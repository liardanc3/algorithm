#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int N, arr[1000001], cnt[1000001], f[1000001], ans[1000001];

stack<pii> st;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	fill(&ans[0], &ans[1000001], -1);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		cnt[arr[i]]++;
	}
	for (int i = 1; i <= N; i++)
		f[i] = cnt[arr[i]];
	for (int i = 1; i <= N; i++) {
		int now = f[i];

		if (st.empty() || st.top().first >= now) 
			st.push({ now,i });
		else {
			while (!st.empty() && st.top().first < now) {
				pii p = st.top(); st.pop();
				ans[p.second] = arr[i];
			}
			st.push({ now,i });
		}
	}
	for (int i = 1; i <= N; i++)
		cout << ans[i] << ' ';
	return 0;
}