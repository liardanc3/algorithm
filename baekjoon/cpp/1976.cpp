#include <bits/stdc++.h>
using namespace std;
int N, M, tmp;
int tree[201];
int getRoot(int i) {
	return i == tree[i] ? i : tree[i] = getRoot(tree[i]);
}


int main() {
	for (int i = 1; i <= 200; i++)
		tree[i] = i;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> tmp;
			if (tmp == 1) {
				if (getRoot(i) == getRoot(j)) continue;
				tree[getRoot(i)] = getRoot(j);
			}
		}
	}
	cin >> tmp;
	int root = getRoot(tmp);
	for (int i = 1; i < M; i++) {
		cin >> tmp;
		if (getRoot(tmp) != root) {
			cout << "NO"; return 0;
		}
	}
	cout << "YES";
	return 0;
}