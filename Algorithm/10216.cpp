#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int,int> ti;
int tree[3001];
int N;
int getRoot(int i) {
	if (i != tree[i])
		tree[i] = getRoot(tree[i]);
	return tree[i];
}
void init() {
	for (int i = 0; i <= 3000; i++)
		tree[i] = i;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T; cin >> T;
	while (T--) {
		vector<ti> enemy_info;
		enemy_info.clear();
		init();
		cin >> N;
		int x, y, r, root = 0;
		for (int i = 1; i <= N; i++) {
			cin >> y >> x >> r;
			enemy_info.push_back(ti(y, x, r));
		}
		for (int i = 0; i < enemy_info.size()-1; i++) {
			ti ti1 = enemy_info.at(i);
			int y1 = get<0>(ti1);
			int x1 = get<1>(ti1);
			int r1 = get<2>(ti1);
			for (int j = i+1; j < enemy_info.size(); j++) {
				ti ti2 = enemy_info.at(j);
				int y2 = get<0>(ti2);
				int x2 = get<1>(ti2);
				int r2 = get<2>(ti2);
				
				if (pow(y1 - y2, 2) + pow(x1 - x2, 2) <= pow(r2 + r1, 2)) {
					int get_i = getRoot(i);
					int get_j = getRoot(j);
					tree[get_j] = get_i;
				}
			}
		}
		for (int i = 0; i <= N; i++)
			tree[i] = getRoot(i);
		vector<int> uniq;
		uniq.clear();
		for (int i = 0; i < N; i++)
			uniq.push_back(tree[i]);
		sort(uniq.begin(), uniq.end());
		uniq.erase(unique(uniq.begin(), uniq.end()), uniq.end());
		cout << uniq.size() << '\n';
	}
	return 0;
}