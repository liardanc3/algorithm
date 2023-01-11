#include <bits/stdc++.h>
using namespace std;
int h, w, x, y, tmp, arr[601][601]{ 0, };
int main() {
	cin >> h >> w >> x >> y;
	for (int i = 1; i <= h+x; i++) for (int j = 1; j <= w+y; j++) {
		cin >> arr[i][j];
	}
	for (int i = x; i <= h; i++) {
		for (int j = y; j <= w; j++) {
			arr[i][j] -= arr[i - x][j - y];
		}
	}
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}