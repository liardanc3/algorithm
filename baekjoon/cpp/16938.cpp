#include <bits/stdc++.h>
using namespace std;

int N, L, R, X, arr[16], cnt;
void bt(int idx, int limit, int sum, int pick) {
	if (pick && L <= sum && sum <= R)
		cnt++;
	if (sum > R || idx >= limit)
		return;

	// idx문제 비선택
	bt(idx + 1, limit, sum, 0);

	// idx문제 선택
	bt(idx + 1, limit, sum + arr[idx], 1);
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N >> L >> R >> X;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	sort(arr + 1, arr + N + 1);

	for (int left = 1; left <= N - 1; left++) {
		for (int right = N; right >= left+1; right--) {

			// 난이도 차이
			int difficulty = arr[right] - arr[left];
			if (difficulty < X)
				break;
			
			bt(left + 1, right, arr[left] + arr[right], 1);
		}
	}
	
	cout << cnt;
	return 0;
}