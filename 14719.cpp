#include <bits/stdc++.h>
using namespace std;
int h, w, arr[501][501], tmp, cnt = 0;
int main() {
	cin >> h >> w;
	for (int i = 1; i <= w; i++) {
		cin >> tmp;
		for (int j = 1; j <= tmp; j++) 
			arr[j][i] = 1;
	}
	for (int i = 1; i <= h; i++) {
		int on = 0;
		for (int j = 1; j <= w; j++) {
			if (arr[i][j]) {
				if (on > 0) cnt += j - on - 1;
				on = j;
			}
		}
	}
	cout << cnt;
	return 0;
}