#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, M, tmp;
	cin >> N >> M;
	vector<int> tree;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		tree.push_back(tmp);
	}
	sort(tree.begin(), tree.end());
	int right = tree.at(N-1);
	int left = 0;
	int center; long long sum,sum_tmp;
	int height = 0;
	while (true) {
		sum = 0;
		center = (right + left) / 2;
		for (int i = 0; i <= N - 1; i++) {
			if (tree.at(i) > center)
				sum += tree.at(i)-center;
		}
		if (right<=left) {
			sum_tmp = 0;
			for (int i = 0; i <= N - 1; i++) {
				if (tree.at(i) > center + 1)
					sum_tmp += tree.at(i) - (center + 1);
			}
			if (sum_tmp >= M) height = center + 1;
			else height = center;
			break;
		
		}
		if (sum > M) 
			left = center + 1;
		if (sum < M)
			right = center - 1;
		if (sum == M) {
			height = center; break;
		}
		
	}
	cout << height;
	return 0;
}