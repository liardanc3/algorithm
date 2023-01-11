#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
vector<pii> vect;
int t, n, m, a, b, cnt, arr[1001];
bool cmp(const pii& a, const pii& b) {
	if(a.second!=b.second)
		return a.second < b.second;
	return a.first < b.first;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> t;
	while (t--) {
		[&]() {
			memset(arr, 0, sizeof(arr));
			vect.clear();
			cnt = 0;
			cin >> n >> m;
			for (int i = 0; i < m; i++) {
				cin >> a >> b;
				vect.push_back({ a,b });
			}
			sort(vect.begin(), vect.end(), cmp);
		}();
		for (int i = 0; i < vect.size(); i++) {
			int L = vect[i].first;
			int R = vect[i].second;
			for (int j = L; j <= R; j++) {
				if (arr[j]==0) {
					arr[j] = 1;
					cnt++;
					break;
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}