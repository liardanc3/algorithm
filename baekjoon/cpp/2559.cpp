#include <bits/stdc++.h>
using namespace std;

int N, K, arr[100001], ps[100001], mx=-1e9;
int main() {
 	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		ps[i] = ps[i - 1] + arr[i];
		if (i - K >= 0) {
			ps[i] -= arr[i - K];
			mx = max(mx, ps[i]);
		}
	}
	cout << mx;
	return 0;
}
