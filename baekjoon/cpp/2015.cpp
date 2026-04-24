#include <bits/stdc++.h>
using namespace std;

int N, K, arr[200001];
long long cnt;
map<int, int> m;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];

		int now = arr[i];
		if (now == K)
			cnt++;

		cnt += m[now - K];

		m[arr[i]]++;
	}
	cout << cnt;
	return 0;
}