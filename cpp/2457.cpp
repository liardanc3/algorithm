#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
int vect[278];
int day[13][32];
int N, sm, sd, em, ed, d[]{ 0,31,28,31,30,31,30,31,31,30,31,30,31 }, ans, mn = 1e9, mx;

// 276
bool cmp(const pii& a, const pii& b) {
	if (a.first != b.first)
		return a.first < b.first;
	return a.second > b.second;
}
void init() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int cnt = 1;
	for (int m = 1; m <= 12; m++) {
		for (int dy = 1; dy <= d[m]; dy++) {
			day[m][dy] = cnt;
			if (3 <= m && m <= 11) cnt++;
		}
	}
	cin >> N;
	while (N--) {
		cin >> sm >> sd >> em >> ed;
		int d1 = day[sm][sd], d2 = day[em][ed];
		vect[d1] = max(vect[d1], d2);
	}
}
int main() {
	init();
	if (!vect[1])
		cout << 0;
	else {
		ans++;
		int right = vect[1];
		int top = right;
		for (int i = 1; i <= 276 && top < 276; i++) {
			if (vect[i] <= right)
				continue;
			bool flag = true;
			while (i <= 276 && i <= right) {
				top = max(top, vect[i]);
				flag = false;
				i++;
			}
			if (!flag) {
				i--;
				right = top;
				ans++;
			}
		}
		if (top == 276)
			cout << ans;
		else
			cout << 0;
	}
	return 0;
}