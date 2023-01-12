#include <bits/stdc++.h>
using namespace std;
int T, M, tmp, idx;
priority_queue<int> L;
priority_queue<int, vector<int>, greater<int>> R;
vector<int> cnt, arr;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> M;
		cnt.push_back(M / 2 + 1);
		for (int i = 1; i <= M; i++) {
			cin >> tmp;
			if (L.empty())
				L.push(tmp);
			else {
				if (tmp <= L.top()) {
					if (L.size() == R.size())
						L.push(tmp);
					else {
						R.push(L.top());
						L.pop();
						L.push(tmp);
					}
				}
				else {
					R.push(tmp);
					if (R.size() == L.size() + 1) {
						L.push(R.top());
						R.pop();
					}
				}
			}
			if (i % 2)
				arr.push_back(L.top());
		}
		while (!L.empty())
			L.pop();
		while (!R.empty())
			R.pop();
	}
	for (int i = 0; i < cnt.size(); i++) {
		int c = cnt[i];
		cout << c << '\n';
		for (int j=1; j <= c; j++) {
			cout << arr[idx++] << ' ';
			if (j % 10 == 0 && j+1!=c)
				cout << '\n';
		}
		cout << '\n';
	}
	return 0;
}