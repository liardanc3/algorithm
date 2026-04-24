#include <bits/stdc++.h>
using namespace std;

string tmp1, tmp2;
int N, arr1[100000], arr2[100000], tmp[100000], mn = 1e9, cnt;
void bitflip(int idx) {
	if (idx - 1 >= 0)
		tmp[idx - 1] = !tmp[idx - 1];
	tmp[idx] = !tmp[idx];
	if (idx + 1 < N)
		tmp[idx + 1] = !tmp[idx + 1];
	cnt++;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N >> tmp1 >> tmp2;
	for (int i = 0; i < N; i++) {
		arr1[i] = tmp1[i] == '1' ? 1 : 0;
		arr2[i] = tmp2[i] == '1' ? 1 : 0;
	}
	copy(&arr1[0], &arr1[100000], &tmp[0]);
	for (int i = 1; i < N; i++) {
		if (tmp[i - 1] != arr2[i - 1])
			bitflip(i);
	}
	if (tmp[N - 1] == arr2[N - 1])
		mn = cnt;
	copy(&arr1[0], &arr1[100000], &tmp[0]);
	cnt = 0;
	bitflip(0);
	for (int i = 1; i < N; i++) {
		if (tmp[i - 1] != arr2[i - 1])
			bitflip(i);
	}
	if (tmp[N - 1] == arr2[N - 1])
		mn = min(mn, cnt);
	mn == 1e9 ? cout << -1 : cout << mn;
	return 0;
}