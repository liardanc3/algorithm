#include <bits/stdc++.h>
using namespace std;

int N, arr[100001], element[100001], mx, arrmx, arrmxidx, lft, rht;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> element[i];
		arrmx = max(arrmx, element[i]);
		if (arrmx == element[i])
			arrmxidx = i;
		arr[i] += element[i] + arr[i - 1];
	}

	// 国烹 盖坷弗率
	lft = 1;
	for (rht = 2; rht <= N - 1; rht++)
		mx = max(mx, arr[N] - element[lft] - element[rht] + arr[N] - arr[rht]);

	// 国烹 盖哭率
	rht = N;
	for (lft = N - 1; lft >= 2; lft--)
		mx = max(mx, arr[rht - 1] - element[lft] + arr[lft - 1]);

	// 国烹 啊款单
	mx = max(mx, arr[arrmxidx] - element[1] + arr[N] - arr[arrmxidx - 1] - element[N]);

	cout << mx;
	return 0;
}