#include <bits/stdc++.h>
using namespace std;

int dfs(vector<int> vect[], int start, int check[]) {
	if (check[start]) return 0;
	check[start] = 1;
	for (int i = 0; i < vect[start].size(); i++) {
		if (check[vect[start].at(i)] == 0) {
			dfs(vect, vect[start].at(i), check);
		}
	}
	return 1;
}

int main() {
	int	count = 0; int ans = 0;
	int N, M, tmp1, tmp2; cin >> N >> M;
	vector<int> vect[1001];
	vector<int> tmp;
	int check[1001] = { 0, };
	for (int i = 0; i < M; i++) {
		cin >> tmp1 >> tmp2;
		tmp.push_back(tmp1);
		tmp.push_back(tmp2);
		vect[tmp1].push_back(tmp2);
		vect[tmp2].push_back(tmp1);
	}
	if (tmp.empty()) cout << N;
	else {
		for (int i = 0; i < tmp.size(); i++) {
			if (check[tmp[i]] == 0)
				count += dfs(vect, tmp[i], check);
		}
		for (int i = 1; i <= N; i++) {
			if (check[i] == 0)
				ans++;
		}
		cout << ans + count;
	}
	return 0;
}