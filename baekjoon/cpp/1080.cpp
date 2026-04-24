#include <bits/stdc++.h>
using namespace std;
int N, M, A[51][51]{ 0, }, B[51][51]{ 0, };
int main() {
	cin >> N >> M;
	string a, b;
	for (int i = 1; i <= N; i++) {
		cin >> a;
		for (int j = 1; j <= M; j++) 
			A[i][j] = a[j - 1]-'0';
	}
	for (int i = 1; i <= N; i++) {
		cin >> b;
		for (int j = 1; j <= M; j++)
			B[i][j] = b[j - 1]-'0';
	}
	if (N < 3 || M < 3) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (A[i][j] == B[i][j])
					continue;
				else {
					cout << -1;
					return 0;
				}
			}
		}
		cout << 0;
		return 0;
	}
	int cnt = 0;
	for (int i = 1; i <= N - 2; i++) {
		for (int j = 1; j <= M - 2; j++) {
			if (A[i][j] != B[i][j]) {
				for (int r = i; r < i + 3; r++) for (int c = j; c < j + 3; c++) {
					A[r][c] = !A[r][c];
				}
				cnt++;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (A[i][j] == B[i][j])
				continue;
			else {
				cout << -1;
				return 0;
			}
		}
	}
	cout << cnt;
	return 0;
}