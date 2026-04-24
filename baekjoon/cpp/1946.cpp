#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> pip;

vector<pip> vect;

int t, N, a, b, cnt;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> t;
	while (t--) {
		cnt = 0;
		vect.clear();
		[&]() {
			cin >> N;
			for (int i = 1; i <= N; i++) {
				cin >> a >> b;
				vect.push_back({ a + b,{a,b} });
			}
		}();
		sort(vect.rbegin(), vect.rend());
		for (int i = 0; i < N; i++) {
			for (int j = N-1; j > i && vect[i].first - 2 >= vect[j].first; j--) {
				if (vect[i].second.first > vect[j].second.first &&
					vect[i].second.second > vect[j].second.second) {
					cnt++;
					break;
				}
			}
		}
		cout << N - cnt << '\n';
	}

	return 0;
}