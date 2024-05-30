#include <bits/stdc++.h>
using namespace std;

int N, arr[11], oper[4], mn = 1e9, mx = -1e9;
void backtracking(int idx, int now) {
	if (idx == N-1) {
		mn = min(mn, now);
		mx = max(mx, now);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (oper[i]) {
			oper[i]--;
			switch (i) {
			case 0:
				backtracking(idx + 1, now + arr[idx + 1]);
				break;
			case 1:
				backtracking(idx + 1, now - arr[idx + 1]);
				break;
			case 2:
				backtracking(idx + 1, now * arr[idx + 1]);
				break;
			case 3:
				backtracking(idx + 1, now / arr[idx + 1]);
				break;
			}
			oper[i]++;
		}
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	for (int i = 0; i < 4; i++)
		cin >> oper[i];
	backtracking(0, arr[0]);
	cout << mx << '\n' << mn;
	return 0;
}