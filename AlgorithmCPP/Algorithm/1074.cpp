#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, r, c;
	cin >> N >> r >> c;
	int ans,ans_N;
	int ret = 0;
	int ans_left_limit = 0, ans_right_limit = (int)pow(2, N) * (int)pow(2, N) - 1;
	while (N > 0) {
		ans = (int)pow(2, N)* (int)pow(2, N);
		ans_N = (int)pow(2, N) / 2;
		if (r < ans_N) {
			ans_left_limit = 0;
			ans_right_limit = ans / 2 - 1;
			c < ans_N ?	ans_right_limit = ans/ 4 - 1 : ans_left_limit = ans / 4;
		}
		else{
			ans_left_limit = ans / 2;
			ans_right_limit = ans - 1;
			c < ans_N ?	ans_right_limit = 3 * ans / 4 - 1 : ans_left_limit = 3 * (ans / 4);
		}
		(ans_right_limit == ans - 1 || ans_left_limit == ans/2) ? r -= ans_N : 1;
		(ans_left_limit != 0 && ans_left_limit != ans/2) ? c -= ans_N : 1;
		ret += ans_left_limit;
		N--;
	}
	cout << ret;
	return 0;
}