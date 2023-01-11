#include <bits/stdc++.h>
using namespace std;
int N, dist[100][100]{ 0, }, mn = 2e9, src, dst, tmp;

void solve() {
	vector<int> vect;
	for (int i = 1; i <= N; i++) {
		if (src != i && dst != i) 
			vect.push_back(i);
	}
	sort(vect.begin(), vect.end());

	do  {
		int _dist = 0;
		bool flag = false;
	
		int now = dist[src][vect[0]];
		if (now == 1e8) continue;

		_dist += now;
		
		for (int i = 0; i < vect.size() - 1; i++) {
			now = dist[vect[i]][vect[i + 1]];
			if (now == 1e8) {
				flag = true;
				break;
			}
			_dist += now;
			if (i == vect.size() - 2) {
				now = dist[vect[i+1]][dst];
				if (now == 1e8) {
					flag = true;
					break;
				}
				_dist += now;

				now = dist[dst][src];
				if (now == 1e8) {
					flag = true;
					break;
				}
				_dist += now;
			}
		}
		if (flag) continue;
		mn = min(mn, _dist);

	} while (next_permutation(vect.begin(), vect.end()));

	return;
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++) {
			cin >> tmp;
			if (tmp == 0)
				dist[i][j] = 1e8;
			else dist[i][j] = tmp;
		}
	}
	if (N == 2) {
		cout << min(dist[1][2] + dist[2][1], dist[2][1] + dist[1][2]);
		return 0;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) continue;
			src = i, dst = j;
			solve();
		}
	}
	cout << mn;
	return 0;
}