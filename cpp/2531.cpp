#include <bits/stdc++.h>
using namespace std;

int N, d, k, c, visited[3001], arr[33001], mx=1, cnt=1;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N >> d >> k >> c;
	visited[c] = 1;
	for (int i = k; i < k + N; i++)
		cin >> arr[i];
	for (int i = 1; i < k; i++)
		arr[i] = arr[N + i];

	for (int i = 1; i <= k; i++) {
		visited[arr[i]]++;
		if (visited[arr[i]] == 1)
			cnt++;
		mx = max(mx, cnt);
	}

	for (int i = k + 1; i <= N + k - 1; i++) {
		visited[arr[i - k]]--;
		if (visited[arr[i - k]] == 0)
			cnt--;
		visited[arr[i]]++;
		if (visited[arr[i]] == 1)
			cnt++;
		mx = max(mx, cnt);
	}

	cout << mx;
	return 0;
}