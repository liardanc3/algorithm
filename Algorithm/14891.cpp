#include <bits/stdc++.h>
using namespace std;
int top[4][8], k, num, d;
string state;
void ccw(int n, int L, int R);
void cw(int n, int L, int R);
void ccw(int n, int L, int R) {
	if (n < 3 && top[n + 1][6] != top[n][2] && !R)
		cw(n + 1, 1, 0);
	if (n > 0 && top[n - 1][2] != top[n][6] && !L)
		cw(n - 1, 0, 1);
	int tmp[8];
	copy(&top[n][0], &top[n][8], &tmp[0]);
	for (int i = 1; i <= 7; i++)
		top[n][i - 1] = tmp[i];
	top[n][7] = tmp[0];
}
void cw(int n, int L, int R) {
	if (n < 3 && top[n + 1][6] != top[n][2] && !R)
		ccw(n + 1, 1, 0);
	if (n > 0 && top[n - 1][2] != top[n][6] && !L)
		ccw(n - 1, 0, 1);
	int tmp[8];
	copy(&top[n][0],&top[n][8],&tmp[0]);
	for (int i = 0; i < 7; i++)
		top[n][i + 1] = tmp[i];
	top[n][0] = tmp[7];
}
int main() {
	for (int i = 0; i < 4; i++) {
		cin >> state;
		for (int j = 0; j < 8; j++)
			top[i][j] = state[j]-'0';
	}
	cin >> k;
	while (k--) {
		cin >> num >> d;
		if (d == 1)
			cw(num-1, 0, 0);
		else ccw(num-1, 0, 0);
	}
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		if (top[i][0]) sum += pow(2, i);
	}
	cout << sum;
	return 0;
}