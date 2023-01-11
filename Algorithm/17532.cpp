#include <bits/stdc++.h>
using namespace std;
int tree[300001],N;
void init() {
	for (int i = 0; i <= 300000; i++)
		tree[i] = i;
}
int getRoot(int i) {
	if (i != tree[i])
		tree[i] = getRoot(tree[i]);
	return tree[i];
}
int main() {
	init();
	cin >> N;
	int tmp1, tmp2;
	for (int i = 0; i < N-2; i++) {
		cin >> tmp1 >> tmp2;
		tree[getRoot(tmp2)] = getRoot(tmp1);
	}
	for (int i = 1; i <= N; i++)
		tree[i] = getRoot(i);
	vector<int> vect;
	for (int i = 1; i <= N; i++)
		vect.push_back(tree[i]);
	sort(vect.begin(), vect.end());
	vect.erase(unique(vect.begin(), vect.end()), vect.end());
	for (int i = 0; i < vect.size(); i++)
		cout << vect[i] << ' ';
}