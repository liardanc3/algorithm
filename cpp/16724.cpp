#include <bits/stdc++.h>
using namespace std;
int N, M, tree[1000 * 1000 + 1], ck[1000 * 1000 + 1];
string tmp;
int getRoot(int i) {
	if (ck[i] == 1) {
		return tree[i];
	}
	else {
		ck[i] = 1;
		return tree[i] = getRoot(tree[i]);
	}
}
int main() {
	for (int i = 0; i <= 1000 * 1000; i++)
		tree[i] = i;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		for (int j = 0; j < M; j++) {
			char direct = tmp.at(j);
			int now = i * M + (j + 1);
			
			int next = 0;
			if (tmp.at(j) == 'U')
				next = (i - 1) * M + (j + 1);
			if (tmp.at(j) == 'D')
				next = (i + 1) * M + (j + 1);
			if (tmp.at(j) == 'L')
				next = i * M + j;
			if (tmp.at(j) == 'R')
				next = i * M + (j + 2);
			tree[now] = next;
			
		}
	}
	for (int i = 1; i <= N * M; i++)
		tree[i] = getRoot(tree[i]);

	int cnt = 0;
	int visited[1000 * 1000 + 1]{ 0, };
	vector<int> ans;
	for (int i = 1; i <= N * M; i++) {
		if (visited[tree[i]] == 0) {
			visited[tree[i]] = 1;
			ans.push_back(tree[i]);
		}
	}
	cout << ans.size();
	return 0;
}