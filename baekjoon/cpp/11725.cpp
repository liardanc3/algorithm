#include <bits/stdc++.h>
using namespace std;
int ans[100001]{ 0, };
int ck[100001]{ 0, };
vector<int> vect[100001];

int dfs(int root) {
	for (int j = 0; j < vect[root].size(); j++) {
		if (ans[vect[root].at(j)] == 0) {
			ans[vect[root].at(j)] = root;
			dfs(vect[root].at(j));
		}
	}
	return 0;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, tmp1, tmp2; cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> tmp1 >> tmp2;
		vect[tmp1].push_back(tmp2);
		vect[tmp2].push_back(tmp1);
	} ans[1] = -1;
	dfs(1);
	for (int i = 2; i <= n; i++)
		cout << ans[i] << '\n';
	return 0;
}