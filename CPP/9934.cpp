#include <bits/stdc++.h>
using namespace std;
vector<int> vect;
int tree[1024]; 
int k, tmp;

int make_tree(int now, int l, int r) {
	int mid = (l + r) / 2;
	tree[now] = vect.at(mid);
	if (l < r) {
		make_tree(2 * now, l, mid - 1);
		make_tree(2 * now + 1, mid + 1, r);
	}
	return 1;
}

void init() {
	for (int i = 1; i <= 1023; i++)
		tree[i] = i;
	
	cin >> k;
}
int main() {
	init();
	int size = pow(2, k) - 1;
	vect.push_back(-1);
	for (int i = 1; i <= size; i++) {
		cin >> tmp;
		vect.push_back(tmp);
	}
	make_tree(1, 1, size);
	int start = 1;
	for (int i = 1; i <= size; i++) {
		cout << tree[i] << ' ';
		if (i == start) {
			cout << '\n';
			start *= 2;
			start++;
		}
	}

	return 0;
}