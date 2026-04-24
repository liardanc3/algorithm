#include <bits/stdc++.h>
using namespace std;

int T, N, L, mx;
vector<int> vect;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> N;
		vect.clear();
		mx = 0;
		for (int i = 0; i < N; i++) {
			cin >> L;
			vect.push_back(L);
		}
		sort(vect.begin(), vect.end());
		for (int i = 0; i < N - 2; i++)
			mx = max(mx, abs(vect[i] - vect[i + 2]));
		cout << mx << '\n';
	}
	return 0;
}