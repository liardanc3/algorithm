#include <bits/stdc++.h>
using namespace std;
int arr[50][50]{ 0, }, cnt = 0;
int main() {
	int n, m;
	cin >> n >> m;
	string tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		for (int j = 0; j < m; j++) {
			char now = tmp[j];
			if (now == '-')
				arr[i][j] = 1;
			else arr[i][j] = -1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] != 0) {
				int now = arr[i][j];
				int idx = 0;
				if (now == 1) {
					while (j + idx < m && arr[i][j + idx] == now) {
						arr[i][j + idx] = 0;
						idx++;
					}
				}
				else if (now == -1) {
					while (i + idx < n && arr[i + idx][j] == now) {
						arr[i + idx][j] = 0;
						idx++;
					}
				}
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}