#include <bits/stdc++.h>
using namespace std;
int dp[21][2][3], door, L, R, n, use[21];
int dynamic(int l, int r, int cnt, int dist) {
	if (cnt == n + 1) return dist;
	int next = use[cnt];
	return min(dynamic(next, r, cnt + 1, dist+abs(next-l)), 
			   dynamic(l, next, cnt + 1,dist+abs(next-r)));
}
int main() {
	cin >> door >> L >> R >> n;
	for (int i = 1; i <= n; i++)
		cin >> use[i];
	cout << dynamic(L,R,1,0);
	return 0;
}