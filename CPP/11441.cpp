#include <bits/stdc++.h>
using namespace std;

int N, M, a, b, arr[100001];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i], arr[i] += arr[i - 1];
	cin >> M;
	while (M--) {
		cin >> a >> b;
		cout << arr[b] - arr[a - 1] << '\n';
	}
	return 0;
}