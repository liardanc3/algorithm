#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, M, tmp;
	cin >> N >> M;
	vector<int> tree;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		tree.push_back(tmp);
	}
	sort(tree.rbegin(), tree.rend());
	int tree_h = 2147483000; int tree_tmp;
	int max = tree.at(0);
	int height = 0;
	for (int i = max; i >= 0; i--) {
		tree_tmp = 0; 
		for (int j = 0; j<N; j++) {
			if (i >= tree.at(j)) break;
			else tree_tmp += (tree.at(j) - i);
		}
		if (M <= tree_tmp && height < i && tree_h >= tree_tmp) {
			height = i; tree_h = tree_tmp;
			if (M == tree_h) break;
		}
	}
	cout << height;
	return 0;
}