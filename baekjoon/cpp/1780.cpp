#include <bits/stdc++.h>
using namespace std;
int sum[3]{ 0, };
int *check(int row, int col, int range, short** array) {
	for (int i = row; i < row+range; i++) {
		for (int j = col; j < range+col; j++) {
			if (array[i][j] != array[row][col]) {
				for (int k = row; k < range+row; k += (range / 3)) {
					for (int s = col; s < range+col; s += (range / 3)) {
						check(k, s, range / 3, array);
					}
				}
				return 0;
			}
		}
	}
	sum[array[row][col] + 1] += 1;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k, tmp; cin >> k;
	short **array = new short * [k];
	for (int i = 0; i < k; i++) {
		array[i] = new short[k];
		for (int j = 0; j < k; j++) {
			cin >> tmp;
			array[i][j] = tmp;
		}
	}
	check(0, 0, k, array);
	cout << sum[0] << "\n" << sum[1] << "\n" << sum[2];
	return 0;
}