#include <bits/stdc++.h>
#define int long long
using namespace std;

int k, w[2'250'100], mx, total, add;
void f(int h) {
	if (h == 0)
		return;
	for (int i = (1 << h); i < (1 << (h + 1)); i += 2) {
		int left = w[i];
		int right = w[i + 1];

		w[i] = max(left, right);
		w[i + 1] = max(left, right);

		w[i / 2] += w[i];
		add += abs(left - right);
	}
	f(h - 1);
}
signed main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> k;
	for (int i = 2; i < (1 << (k + 1)); i += 2) {
		cin >> w[i] >> w[i + 1];
		total += w[i] + w[i + 1];
	}
	f(k);
	cout << total + add;
	return 0;
}