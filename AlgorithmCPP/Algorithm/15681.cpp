#include <bits/stdc++.h>
using namespace std;
int N, R, Q, U, V;
int tree[100001], ck[100001], sz[100001];
vector<int> line[100001], child[100001];
int get_sz(int n) {
	for (int i = 0; i < child[n].size(); i++) 
		sz[n] += get_sz(child[n].at(i));
	return sz[n];
}
void make_tree(int R) {
	for (int i = 0; i < line[R].size(); i++) {
		int L = line[R].at(i);
		if (ck[L] == 1) continue;
		ck[L] = 1;
		tree[L] = R;
		child[R].push_back(L);
		make_tree(L);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 1; i <= 100000; i++) {
		tree[i] = i;
		sz[i] = 1;
	}
	cin >> N >> R >> Q;
	for (int i = 1; i <= N - 1; i++) {
		cin >> U >> V;
		line[U].push_back(V);
		line[V].push_back(U);
	}
	ck[R] = 1;
	make_tree(R);
	get_sz(R);
	for (int i = 1; i <= Q; i++) {
		cin >> V;
		cout << sz[V] << '\n';
	}
	return 0;
}