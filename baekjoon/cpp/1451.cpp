#include <bits/stdc++.h>
#define int long long
using namespace std;

string tmp;
int N, M, arr[50][50], mx;
signed main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		for (int j = 0; j < M; j++)
			arr[i][j] = tmp[j] - '0';
	}

	// 가로 2줄
	if (N > 2) {
		for (int i = 0; i < N - 2; i++) {
			for (int j = i + 1; j < N - 1; j++) {
				int k = N - 1;

				int a = 0, b = 0, c = 0;

				for (int y = 0; y <= i; y++) {
					for (int x = 0; x < M; x++)
						a += arr[y][x];
				}
				for (int y = i + 1; y <= j; y++) {
					for (int x = 0; x < M; x++)
						b += arr[y][x];
				}
				for (int y = j+1; y <= k; y++) {
					for (int x = 0; x < M; x++)
						c += arr[y][x];
				}

				mx = max(mx, a * b * c);
			}
		}
	}

	// 세로 2줄
	if (M > 2) {
		for (int i = 0; i < M - 2; i++) {
			for (int j = i + 1; j < M - 1; j++) {
				int k = M - 1;

				int a = 0, b = 0, c = 0;

				for (int y = 0; y < N; y++) {
					for (int x = 0; x <= i; x++)
						a += arr[y][x];
				}
				for (int y = 0; y < N; y++) {
					for (int x = i + 1; x <= j; x++)
						b += arr[y][x];
				}
				for (int y = 0; y < N; y++) {
					for (int x = j + 1; x <= k; x++)
						c += arr[y][x];
				}

				mx = max(mx, a * b * c);
			}
		}
	}

	// 크로스
	if (N > 1 && M > 1) {
		for (int i = 0; i < N-1; i++) {
			for (int j = 0; j < M-1; j++) {

				int a1 = 0, a2 = 0, a3 = 0, a4 = 0;

				// 1사분면
				for (int y = 0; y <= i; y++) {
					for (int x = j + 1; x < M; x++)
						a1 += arr[y][x];
				}

				// 2사분면
				for (int y = 0; y <= i; y++) {
					for (int x = 0; x <= j; x++)
						a2 += arr[y][x];
				}

				// 3사분면
				for (int y = i + 1; y < N; y++) {
					for (int x = 0; x <= j; x++)
						a3 += arr[y][x];
				}

				// 4사분면
				for (int y = i + 1; y < N; y++) {
					for (int x = j + 1; x < M; x++)
						a4 += arr[y][x];
				}

				// 12, 3, 4
				mx = max(mx, (a1 + a2) * a3 * a4);
				// 14, 2, 3
				mx = max(mx, (a1 + a4) * a2 * a3);
				// 23, 1, 4
				mx = max(mx, (a2 + a3) * a1 * a4);
				// 34, 1, 2
				mx = max(mx, (a3 + a4) * a1 * a2);
			}
		}
	}
	cout << mx;
	return 0;
}