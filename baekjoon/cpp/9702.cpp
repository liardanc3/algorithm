#include <bits/stdc++.h>
using namespace std;
int T, n, tmp, cnt;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for(int i=1; i<=T; i++){
		vector<int> vect[501];
		cin >> n;
		for(int i=1; i<=n; i++) {
			cin >> tmp;
			for (int j = 1; j <= i; j++) {
				if (!vect[j].size() || vect[j][vect[j].size() - 1] < tmp)
					vect[j].push_back(tmp);
				else {
					int idx = lower_bound(vect[j].begin(), vect[j].end(), tmp) - vect[j].begin();
					vect[j][idx] = tmp;
				}
				cnt += vect[j].size();
			}
		}
		cout << "Case #" << i << ": " << cnt << '\n';
		cnt = 0;
	}
	return 0;
}