#include <bits/stdc++.h>
using namespace std;
int n, k, arr[201], ans, robot[101];
void step1() {
	for (int i = n; i >= 2; i--) {
		robot[i] = robot[i - 1];
	}
	robot[1] = 0;
	int tmp = arr[2 * n];
	for (int i = 2 * n; i >= 2; i--)
		arr[i] = arr[i - 1];
	arr[1] = tmp;
	robot[n] = 0;
}
void step2() {
	for (int i = n; i >= 2; i--) {
		if (robot[i-1] && !robot[i] && arr[i] > 0) {
			robot[i] = 1;
			robot[i - 1] = 0;
			arr[i]--;
		}
	}
	robot[n] = 0;
}
void step3() {
	if (arr[1]>0) {
		robot[1] = 1;
		arr[1]--;
	}
}
int step4() {
	int ret = 0;
	for (int i = 1; i <= 2 * n; i++) {
		if (arr[i] == 0)
			ret++;
	}
	return ret;
}
int main() {
	cin >> n >> k;
	for (int i = 1; i <= 2 * n; i++)
		cin >> arr[i];
	for (ans = 1;; ans++) {
		step1();
		step2();
		step3();
		int s4 = step4();
		if (s4 >= k) break;
	}
	cout << ans;
	return 0;
}