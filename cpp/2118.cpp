#include <bits/stdc++.h>
using namespace std;

int N, tmp, sum[50000], limit, mx;
int main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> sum[i];
			if (i != 0)
				sum[i] += sum[i - 1];
		}
		limit = sum[N - 1] / 2;
	}();
	mx = N / 2;

	for (int i = N - 1; i >= 0; i--) {
		int gap = sum[i] - sum[N - 1] / 2;
		int left = 0, right = i;
		while (left <= right) {
			int mid = (left + right) / 2;

			int part1 = sum[i] - sum[mid];
			int part2 = sum[N - 1] - part1;
			mx = max(mx, min(part1, part2));

			if (part1 < limit)
				right = mid - 1;
			else
				left = mid + 1;
		}
	}
	
	cout << mx;
	return 0;
}