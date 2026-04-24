#include <bits/stdc++.h>
using namespace std;
int N, d, k, c, arr[3000000], mx, sushi[3001], cnt, nxt;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> d >> k >> c;
	sushi[c]++;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	for (int i = 0; i < k; i++) {
		int dish = arr[i];
		sushi[dish]++;
	}
	for (int i = 1; i <= d; i++) {
		if (sushi[i])
			mx++;
	}
	nxt = k - 1;
	cnt = mx;
	for (int i = 1; i < N; i++) {
		sushi[arr[i - 1]]--;
		if (sushi[arr[i - 1]] == 0)
			cnt--;
		nxt = (nxt + 1) % N;
		int dish = arr[nxt];
		sushi[dish]++;
		if (sushi[dish] == 1)
			cnt++;
		mx = max(mx, cnt);
	}
	cout << mx;
	return 0;
}