#include <bits/stdc++.h>
using namespace std;
int arr[10000][4];
int ck[10000];
queue<int> Q;
int bfs(int des) {
	int cnt = 0;
	while (!Q.empty()) {
		cnt++;
		int size = Q.size();
		for (int i = 0; i < size; i++) {
			int tmp = Q.front(); Q.pop();
			for (int j = 0; j < 4; j++) {
				if (arr[tmp][j] == des) {
					ck[arr[tmp][j]] = tmp;
					return 0;
				}
				else {
					if (ck[arr[tmp][j]] == -1) {
						ck[arr[tmp][j]] = tmp;
						Q.push(arr[tmp][j]);
					}
				}
			}
		}
	}
	return -1;
}
void init() {
	for (int i = 0; i < 10000; i++) {
		arr[i][0] = (2 * i) % 10000;
		arr[i][1] = (i - 1) == -1 ? 9999 : (i - 1);
		arr[i][2] = ((i / 100) % 10) * 1000 + ((i / 10) % 10) * 100 + (i % 10) * 10 + (i / 1000);
		arr[i][3] = (i % 10) * 1000 + (i / 1000) * 100 + ((i / 100) % 10) * 10 + (i / 10) % 10;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T, src, des; cin >> T;
	init();
	while (T--) {
		cin >> src >> des;
		fill(ck, &ck[10000], -1);
		ck[src] = -2;
		while (!Q.empty()) Q.pop(); Q.push(src);
		bfs(des);
		string ans = "";
		while (ck[des] != -2) {
			int aft = des;
			int bef = ck[des];
			if ((aft == bef - 1) || (aft == 9999 && bef == 0)) {
				ans += "S"; des = bef;
			}
			else if ((aft == (bef * 2) % 10000)) {
				ans += "D"; des = bef;
			}
			else if ((aft == ((bef / 100) % 10) * 1000 + ((bef / 10) % 10) * 100 + (bef % 10) * 10 + (bef / 1000))) {
				ans += "L"; des = bef;
			}
			else {
				ans += "R"; des = bef;
			}
		} reverse(ans.begin(), ans.end());
		cout << ans << '\n';
	}
	return 0;
}