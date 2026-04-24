#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int main() {
	int K; cin >> K;
	pii arr[46];
	arr[0] = { 1,0 };
	for (int i = 1; i <= 45; i++) {
		int A = arr[i - 1].first;
		int B = arr[i - 1].second;
		pii tmp = { B,A + B };
		arr[i] = tmp;
	}
	cout << arr[K].first << ' ' << arr[K].second;

	return 0;
}