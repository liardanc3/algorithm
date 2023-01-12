#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n, m, tmp, arr[51], visited[51], ans;
vector<int> vect;
vector<pii> dist;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		vect.push_back(tmp);
	}
	sort(vect.begin(), vect.end());

	for (int i = 1; i <= n; i++)
		arr[i] = 2 * vect[i-1];
	
	if (n <= m) {
		if (vect[0] * vect[n - 1] > 0) cout << max(abs(vect[0]), abs(vect[n - 1]));
		else cout << 2 * min(abs(vect[0]), abs(vect[n - 1])) + max(abs(vect[0]), abs(vect[n - 1]));
		return 0;
	}
	int idx = 0;
	for (int i = 1; i <= n; i++) {
		if (arr[i] > 0) {
			idx = i; break;
		}
	}
	for (int i = 1; i <= max(n-(m-1),idx); i++) {
		int mn = 1e9, mx = -1e9;
		for (int j = 0; j < m; j++) {
			if (j != 0 && arr[i + j] * arr[i + j - 1] < 0) break;
			mn = min(arr[i+j], mn);
			mx = max(arr[i+j], mx);
		}
		if (mn * mx > 0)
			dist.push_back({ max(abs(mx),abs(mn)),i });
		else
			dist.push_back({ abs(mx) + abs(mn),i });
	}
	sort(dist.rbegin(), dist.rend());

	for (int i = 0; i < dist.size(); i++) {
		pii now = dist[i];

		int start = now.second;
		bool flag = true;

		// 음수양수 짤라야함
		int plus = arr[start] > 0;
		for (int j = 0; j < m && flag && plus == arr[start+j] > 0; j++) {
			if (visited[start + j]) flag = false;
		}

		if (flag) {
			for (int j = 0; j < m && flag && plus == arr[start + j] > 0; j++)
				visited[start + j] = 1;
			ans += now.first;
		}
	}
	ans -= dist[0].first / 2;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			int mn = 1e9, mx = -1e9;
			int j;
			for (j = i; j <= n && !visited[j]; j++) {
				visited[j] = 1;
				mn = min(arr[j], mn);
				mx = max(arr[j], mx);
			}
			if (mn * mx > 0)
				ans += max(abs(mn), abs(mx));
			else
				ans += abs(mx) + abs(mn);
			i = j - 1;
		}
	}
	cout << ans;
	return 0;
}