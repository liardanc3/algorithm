#include <bits/stdc++.h>
using namespace std;
int N, M, arr[101][101]{ 0, };
void touch(int r, int c) {
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++)
			arr[i][j] = !arr[i][j];
	}
}
int main() {
	cin >> N >> M;
	string tmp;
	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		for (int j = 1; j <= M; j++) 
			arr[i][j] = tmp[j - 1]-'0';
	}
	int ans = 0;
	for (int i = N; i >= 1; i--) {
		for (int j = M; j >= 1; j--) {
			if (arr[i][j] == 1) {
				touch(i, j);
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}