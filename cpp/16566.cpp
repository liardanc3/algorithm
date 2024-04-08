#include <bits/stdc++.h>
using namespace std;

vector<int> vect;
int N, M, K, tmp, tree[4000002];
int getNext(int i) {
	return tree[i] == i ? i : tree[i] = getNext(tree[i]);
}
int main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> N >> M >> K;
		for (int i = 1; i <= M; i++)
			tree[i] = i;
		for (int i = 0; i < M; i++) {
			cin >> tmp;
			vect.push_back(tmp);
		}
		sort(vect.begin(), vect.end());
	}();
	while (K--) {
		cin >> tmp;
		int idx = upper_bound(vect.begin(), vect.end(), tmp) - vect.begin();
		int element = vect[getNext(idx)];
		cout << element << '\n';
		tree[getNext(idx)] = getNext(getNext(idx)+1);
	}
	return 0;
}