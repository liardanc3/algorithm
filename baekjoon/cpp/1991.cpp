#include <bits/stdc++.h>
using namespace std;
typedef pair<char, char> pc;
map<char, pc> tree;
void postorder(char s) {
	cout << s;
	if (tree[s].first != '.')
		postorder(tree[s].first);
	if (tree[s].second != '.')
		postorder(tree[s].second);
}
void inorder(char s) {
	if (tree[s].first != '.')
		inorder(tree[s].first);
	cout << s;
	if (tree[s].second != '.')
		inorder(tree[s].second);
}
void preorder(char s) {
	if (tree[s].first != '.')
		preorder(tree[s].first);
	if (tree[s].second != '.')
		preorder(tree[s].second);
	cout << s;
}

int main() {
	int n; cin >> n;
	char tmp1, tmp2, tmp3;
	while (n--) {
		cin >> tmp1 >> tmp2 >> tmp3;
		tree[tmp1] = pc(tmp2, tmp3);
	}
	postorder('A'); cout << '\n';
	inorder('A'); cout << '\n';
	preorder('A');
	return 0;
}