#include <bits/stdc++.h>
using namespace std;
struct tree {
	int data;
	tree* left;
	tree* right;
};
void push_tree(tree* node, tree* add) {
	if (node->data > add->data) {
		if (node->left == NULL)
			node->left = add;
		else
			push_tree(node->left, add);
	}
	else {
		if (node->right == NULL)
			node->right = add;
		else
			push_tree(node->right, add);
	}
}
void preorder(tree* node) {
	if (node->left != NULL)
		preorder(node->left);
	if (node->right != NULL)
		preorder(node->right);
	cout << node->data << '\n';
}
int main() {
	int tmp;
	queue<int> Q;
	while (cin >> tmp) {
		Q.push(tmp);
	}
	tree root;
	root.data = Q.front();
	root.right = NULL; 
	root.left = NULL;
	Q.pop();
	while (!Q.empty()) {
		tree *tr = new tree;
		tr->data = Q.front();
		tr->right = NULL; tr->left = NULL;
		Q.pop();
		push_tree(&root,tr);
	} preorder(&root);
	return 0;
}