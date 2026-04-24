#include <bits/stdc++.h>
using namespace std;

string ans;
int N, tmp;
priority_queue<int, vector<int>, greater<int>> R;
priority_queue<int> L;
int main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> N; N--;
		cin >> tmp;
		L.push(tmp);
		ans += to_string(tmp) + '\n';
		while (N--) {
			cin >> tmp;
			
			// 1 2 3 4   7 8 9
			if (L.size() == R.size()) {
				if (tmp <= R.top()) {
					L.push(tmp);
				}
				else {
					L.push(R.top());
					R.pop();
					R.push(tmp);
				}
			}
			else {
				if (tmp <= L.top()) {
					R.push(L.top());
					L.pop();
					L.push(tmp);
				}
				else {
					R.push(tmp);
				}
			}

			ans += to_string(L.top()) + '\n';
		}
	}();
	cout << ans;
	return 0;
}