#include <bits/stdc++.h>
using namespace std;
int N, tmp, arr[1000001], mx;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		arr[tmp] = arr[tmp - 1] + 1;
		mx = max(mx, arr[tmp]);
	}
	cout << N - mx;
	return 0;
}