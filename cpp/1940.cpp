#include <bits/stdc++.h>
using namespace std;

int N, M, arr[10'000'001], tmp, cnt;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		arr[tmp]++;
	}
	for (int i = 1; i <= M/2; i++) {
		if (i == M / 2 && M % 2 == 0)
			cnt += arr[M / 2] / 2;
		else if (arr[i] > 0 && arr[M - i] > 0)
			cnt += min(arr[i], arr[M - i]);
	}
	cout << cnt;
	return 0;
}
