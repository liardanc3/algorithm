#include <bits/stdc++.h>
using namespace std;

queue<int> q;
int sum, N, X, mx, tmp, cnt;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	cin >> N >> X;
	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		sum += tmp;
		q.push(tmp);

		if (i > X) {
			sum -= q.front();
			q.pop();
		}

		if (i >= X) {
			if (sum == mx)
				cnt++;
			else if (sum > mx) {
				mx = sum;
				cnt = 1;
			}
		}
	}
	if (mx)
		cout << mx << '\n' << cnt;
	else
		cout << "SAD";
	return 0;
}