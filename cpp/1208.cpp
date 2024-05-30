#include <bits/stdc++.h>
#define zero 2000000 
using namespace std;
int N, S, tmp;
long long ans = 0;
vector<int> vect1, vect2;
int _m[8000010];
int *m = &_m[4000005];
void combination1(int idx, int sum) {
	if (idx == N/2) {
		m[sum]++;
		return;
	}
	combination1(idx + 1, sum);
	combination1(idx + 1, sum + vect1[idx]);
}
void combination2(int idx, int sum) {
	if (idx == N - N/2) {
		ans += m[S-sum];
		return;
	}
	combination2(idx + 1, sum);
	combination2(idx + 1, sum + vect2[idx]);
}
int main() {
	memset(_m, 0, sizeof(_m));
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> S;
	for (int i = 1; i <= N / 2; i++) {
		cin >> tmp;
		vect1.push_back(tmp);
	}
	for (int i = 1; i <= N - N / 2; i++) {
		cin >> tmp;
		vect2.push_back(tmp);
	}
	combination1(0, 0);
	combination2(0, 0);
	if (!S) ans--;
	cout << ans;
	return 0;
}