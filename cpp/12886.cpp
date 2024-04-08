#include <bits/stdc++.h>
using namespace std;
int A, B, C;
int dp[1501][751];
void dynamic(int a, int b, int c) {
	if (a == b && a == c) {
		cout << 1;
		exit(0);
	}
	if (a < b) swap(a, b);
	if (a < c) swap(a, b);
	if (b < c) swap(b, c);

	if (dp[a][b])
		return;

	dp[a][b] = 1;

	// a,b 선택
	if (a != b) {
		if (a < b) dynamic(a + a, b - a, c);
		else dynamic(a - b, b + b, c);
	}

	// a,c 선택
	if (a != c) {
		if (a < c) dynamic(a + a, b, c - a);
		else dynamic(a - c, b, c + c);
	}

	// b,c 선택
	if (b != c) {
		if (b < c) dynamic(a, b + b, c - b);
		else dynamic(a, b - c, c + c);
	}

	return;
}
int main() {
	cin >> A >> B >> C;
	dynamic(A, B, C);
	cout << 0;
	return 0;
}