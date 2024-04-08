#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
vector<pii> chicken_idx;
vector<pii> home_idx;
vector<int> home_dist;
int N, M, tmp;
int btidx[14];
int ans;
int bt(int start, int cnt) {
	if (cnt == M) {
		fill(home_dist.begin(), home_dist.end(), 1e9);
		for (int i = 0; i < cnt; i++) {
			int cy = chicken_idx.at(btidx[i]).first;
			int cx = chicken_idx.at(btidx[i]).second;
			for (int j = 0; j < home_idx.size(); j++) {
				int hy = home_idx.at(j).first;
				int hx = home_idx.at(j).second;
				home_dist.at(j) = min(home_dist.at(j), abs(hy - cy) + abs(hx - cx));
			}
		}
		int distSUM = 0;
		for (int i = 0; i < home_dist.size(); i++) {
			distSUM += home_dist.at(i);
		}
		if (distSUM < ans) ans = distSUM;
		return 0;
	}
	for (int i = start; i < chicken_idx.size(); i++) {
		btidx[cnt] = i;
		cnt++;
		bt(i+1, cnt);
		cnt--;
	}
	return 0;
}
int main() {
	cin >> N >> M;
	ans = 1e9;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> tmp;
			if (tmp == 2)
				chicken_idx.push_back(pii(i, j));
			if (tmp == 1) {
				home_idx.push_back(pii(i, j));
				home_dist.push_back(0);
			}
		}
	}
	bt(0, 0);
	cout << ans;
	return 0;
}