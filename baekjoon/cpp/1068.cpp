#include <bits/stdc++.h>
using namespace std;
int N, tmp, del, root;
int tree[50];

int getRoot(int i) {
	while (tree[i] != -1 && tree[i] != -2 && tree[i]!=i)
		i = tree[i];
	return i;
}
void init() {
	for (int i = 0; i <= 49; i++)
		tree[i] = i;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		tree[i] = tmp;
	}
	root = getRoot(1);
	cin >> del;
	tree[del] = -2;
}
int main() {
	init();
	int cnt = 0;
	if (tree[root] == -2) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < N; i++) {
		int find = 0;
		if (getRoot(i) != root)
			continue;
		for (int j = 0; j < N; j++) {
			if (tree[j] == i && getRoot(j)==root) {
				find = 1;
				break;
			}
		}
		if (find==0)
			cnt++; // 4 -> 
	}
	cout << cnt;

	return 0;
}