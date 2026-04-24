#include <bits/stdc++.h>
using namespace std;

int N, t, y, x, arr[10][4], arr2[10][4], point;
void under(int tt, int r, int c) {
	if (tt == 1) {
		for (int i = r + 1; i < 10; i++) {
			if (arr[i][c]) {
				arr[i-1][c] = 1;
				break;
			}
			if (i == 9)
				arr[i][c] = 1;
		}
	}
	else if (tt == 2) {
		for (int i = r+1; i < 10; i++) {
			if (arr[i][c] || arr[i][c + 1]) {
				arr[i - 1][c] = 1;
				arr[i - 1][c + 1] = 1;
				break;
			}
			if (i == 9)
				arr[i][c] = 1, arr[i][c + 1] = 1;
		}
	}
	else {
		for (int i = r + 2; i < 10; i++) {
			if (arr[i][c]) {
				arr[i - 2][c] = 1;
				arr[i - 1][c] = 1;
				break;
			}
			if (i == 9)
				arr[8][c] = 1, arr[9][c] = 1;
		}
	}
	for (int i = 9; i >= 6; i--) {
		bool plus = true;
		for (int j = 0; j < 4; j++) {
			if (arr[i][j] == 0) {
				plus = false;
				break;
			}
		}
		if (plus) {
			point++;
			for (int k = i - 1; k >= 4; k--) {
				for (int j = 0; j < 4; j++)
					arr[k + 1][j] = arr[k][j];
			}
			i++;
		}
	}
	int a = 0;
	for (int i = 4; i <= 5; i++) {
		for (int j = 0; j < 4; j++) {
			if (arr[i][j]) {
				a++;
				break;
			}
		}
	}
	for (int i = 9; i >= 6; i--) {
		for (int j = 0; j < 4; j++) 
			arr[i][j] = arr[i - a][j];
	}
	for (int i = 4; i <= 5; i++) {
		for (int j = 0; j < 4; j++) {
			arr[i][j] = 0;
		}
	}
}
void side(int tt, int r, int c) {
	if (tt == 1) {
		for (int i = r + 1; i < 10; i++) {
			if (arr2[i][c]) {
				arr2[i - 1][c] = 1;
				break;
			}
			if (i == 9)
				arr2[i][c] = 1;
		}
	}
	else if (tt == 2) {
		for (int i = r + 1; i < 10; i++) {
			if (arr2[i][c] || arr2[i][c + 1]) {
				arr2[i - 1][c] = 1;
				arr2[i - 1][c + 1] = 1;
				break;
			}
			if (i == 9)
				arr2[i][c] = 1, arr2[i][c + 1] = 1;
		}
	}
	else {
		for (int i = r + 2; i < 10; i++) {
			if (arr2[i][c]) {
				arr2[i - 2][c] = 1;
				arr2[i - 1][c] = 1;
				break;
			}
			if (i == 9)
				arr2[8][c] = 1, arr2[9][c] = 1;
		}
	}
	for (int i = 9; i >= 6; i--) {
		bool plus = true;
		for (int j = 0; j < 4; j++) {
			if (arr2[i][j] == 0) {
				plus = false;
				break;
			}
		}
		if (plus) {
			point++;
			for (int k = i - 1; k >= 4; k--) {
				for (int j = 0; j < 4; j++)
					arr2[k + 1][j] = arr2[k][j];
			}
			i++;
		}
	}
	int a = 0;
	for (int i = 4; i <= 5; i++) {
		for (int j = 0; j < 4; j++) {
			if (arr2[i][j]) {
				a++;
				break;
			}
		}
	}
	for (int i = 9; i >= 6; i--) {
		for (int j = 0; j < 4; j++)
			arr2[i][j] = arr2[i - a][j];
	}
	for (int i = 4; i <= 5; i++) {
		for (int j = 0; j < 4; j++) {
			arr2[i][j] = 0;
		}
	}
}
int main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> N;
		while (N--) {
			cin >> t >> x >> y;
			under(t, x, y);
			side(t == 2 ? 3 : t == 3 ? 2 : 1, y, x);
		}
	}();
	cout << point << '\n';
	int cnt = 0;
	for (int i = 6; i < 10; i++) {
		for (int j = 0; j < 4; j++) {
			cnt += arr[i][j];
			cnt += arr2[i][j];
		}
	}
	cout << cnt;
	return 0;
}