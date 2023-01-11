#include <bits/stdc++.h>
using namespace std;
int N, M, tmp;
vector<int> vect;
int ans[8];
int dfs(int start, int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << ans[i] << ' ';
		} cout << '\n';
		return 0;
	}
	for (int i = start; i < vect.size(); i++) {
		ans[cnt++] = vect.at(i);
		dfs(i, cnt);
		cnt--;
	}
	return 0;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		vect.push_back(tmp);
	} sort(vect.begin(), vect.end());
	dfs(0,0);
	return 0;
}