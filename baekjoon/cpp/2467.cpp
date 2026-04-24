#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> tii;
int N, tmp, mn;
int water[100001];
int ans_L, ans_R, L, R;
void make_dp() {
	int befor = 2147483000;
	ans_L = 1; L = 1;
	ans_R = N; R = N;
	while (L < R && ans_L < ans_R) {
		if (water[L] + water[R] == 0) {
			ans_L = L; ans_R = R;
			return;
		}
			
		if (water[L] + water[R] < 0 && abs(water[L] + water[R]) < befor) {
			befor = abs(water[L] + water[R]);
			ans_R = R;
			ans_L = L;
			L++;
		}
		else if (water[L] + water[R] > 0 && abs(water[L] + water[R]) < befor) {
			befor = abs(water[L] + water[R]);
			ans_R = R;
			ans_L = L;
			R--;
		}
		else {
			if (water[L] + water[R] > 0)
				R--;
			else L++;
		}
	}
}
int main() {	
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> water[i];
	}
	make_dp();
	cout << water[ans_L] << ' ' << water[ans_R];
	return 0;
}