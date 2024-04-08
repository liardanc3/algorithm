#include <bits/stdc++.h>
using namespace std;
map<int, int> tree;
map<int, int> ck;
vector<int> vect;
int getRoot(int i) {
	ck.clear();
	while (i != tree[i]) {
		if (ck[i] == 1)
			return -1;
		ck[i] = 1;
		i = tree[i];
	}
	return i;
}

bool test_tree() {
	if (vect.size() == 1)
		return false;
	for (int i = 0; i < vect.size()-1; i++) {
		int now = getRoot(vect.at(i));
		int next = getRoot(vect.at(i + 1));
		if (now == -1 || next == -1 || now != next) {
			return false;
		}
	}
	return true;
}

int main() {
	int u, v;
	int k = 1;
	while (cin >> u >> v) {
		tree.clear();
		vect.clear();
		vect.push_back(u);
		vect.push_back(v);
		if (u == 0 && v == 0) {
			cout << "Case " << k << " is a tree.\n";
			k++;
			continue;
		}
		if (u == -1 && v == -1)
			break;
		int flag = 0;
		if (tree.find(v) != tree.end() && flag==0) {
			cout << "Case " << k << " is not a tree.\n";
			flag = 1;
		}
		tree[v] = u;
		while (cin >> u >> v) {
			if (u == 0 && v == 0)
				break;
			if (tree.find(v) != tree.end() && flag==0) {
				cout << "Case " << k << " is not a tree.\n";
				flag = 1;
			}
			tree[v] = u;
			vect.push_back(u);
			vect.push_back(v);
		}
		sort(vect.begin(), vect.end());
		vect.erase(unique(vect.begin(), vect.end()), vect.end());
		for (int i = 0; i < vect.size(); i++) {
			if (tree.find(vect.at(i)) == tree.end()) {
				tree[vect.at(i)] = vect.at(i);
			}
		}
		if (flag == 0) {
			if (test_tree())
				cout << "Case " << k << " is a tree.\n";
			else cout << "Case " << k << " is not a tree.\n";
		}
		k++;
	}
	return 0;
}