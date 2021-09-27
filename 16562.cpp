#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
int N, M, k, pay[10001], tree[10001], tmp1, tmp2;
queue<pii> q;
int getRoot(int i) {
	return i == tree[i] ? i : tree[i] = getRoot(tree[i]);
}
void disjoint() {
	int n = 0;
	while (!q.empty() && n <= N - 1) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		if (getRoot(a) == getRoot(b)) continue;
		tree[getRoot(a)] = getRoot(b);
		n++;
	}
}

int main() {
	cin >> N >> M >> k;
	for (int i = 1; i <= N; i++) {
		cin >> pay[i];
		tree[i] = i;
	}
	for (int i = 1; i <= M; i++) {
		cin >> tmp1 >> tmp2;
		q.push(pii(tmp1, tmp2));
	}
	disjoint();
	
	int total=0;
	vector<int> root;
	for (int i = 1; i <= N; i++) 
		root.push_back(getRoot(i));
	sort(root.begin(), root.end());
	root.erase(unique(root.begin(), root.end()), root.end());
	for (int i = 0; i < root.size(); i++) {
		int mn = 10001;
		for (int j = 1; j <= N; j++) {
			if (root.at(i) == getRoot(j)) {
				if (pay[j] < mn)
					mn = pay[j];
			}
		}
		total += mn;
	}
	if (k - total < 0) cout << "Oh no";
	else cout << total;
	return 0;
}