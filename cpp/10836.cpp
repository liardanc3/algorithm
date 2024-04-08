#include <bits/stdc++.h>
using namespace std;

int M, N, arr[700 + 699], tmp, a, b, c, idx;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> M >> N;
	while (N--) {
		cin >> a >> b >> c;
		if (b && c) {
			arr[a]++;
			arr[a + b]++;
		}
		if (!b && c) {
			arr[a] += 2;
		}
		if (b && !c) {
			arr[a]++;
		}
	}
	for (int i = 1; i < 2 * M - 1; i++) {
		arr[i] += arr[i - 1];
	}
	for (int i = 0; i < M; i++) {
		cout << arr[M - 1 - i] + 1 << ' ';
		for (int j = 1; j < M; j++)
			cout << arr[M - 1 + j] + 1 << ' ';
		cout << '\n';
	}
	return 0;
}