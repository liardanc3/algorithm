#include <bits/stdc++.h>
using namespace std;
int n, tmp, now;
vector<int> inorder;
vector<int> postorder;
int tree[100001];

void make_tree(int root_idx, int in_L, int in_R, int post_L, int post_R) {
	if (in_L >= in_R || post_L >= post_R) return;
	
	int left_range = root_idx - in_L;
	if (left_range != 0) {
		int left_root = postorder.at(post_L - 1 + left_range);
		int left_root_idx;
		for (int i = in_L; i < root_idx; i++) {
			if (inorder.at(i) == left_root) {
				left_root_idx = i;
				break;
			}
		}
		tree[now++] = left_root;
		make_tree(left_root_idx, in_L, root_idx - 1, post_L, post_L + left_range - 1);
	}
	
	int right_range = in_R - root_idx;
	if (right_range != 0) {
		int right_root = postorder.at(post_R - 1);
		int right_root_idx;
		for (int i = root_idx + 1; i <= in_R; i++) {
			if (inorder.at(i) == right_root) {
				right_root_idx = i;
				break;
			}
		}
		tree[now++] = right_root;
		make_tree(right_root_idx, root_idx + 1, in_R, post_L + left_range, post_R - 1);
	}
}

int main() {
	cin >> n;
	inorder.push_back(-1);
	postorder.push_back(-1);
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		inorder.push_back(tmp);
	}
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		postorder.push_back(tmp);
	}
	int root = postorder.at(postorder.size() - 1);
	int root_idx;
	for (int i = 1; i <= n; i++) {
		if (inorder.at(i) == root) {
			root_idx = i;
			break;
		}
	}
	now = 1;
	tree[now++] = root;
	make_tree(root_idx, 1, n, 1, n);
	for (int i = 1; i <= n; i++)
		cout << tree[i] << ' ';
	return 0;
}