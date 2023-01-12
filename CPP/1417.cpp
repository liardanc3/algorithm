#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, tmp, arr[51];
vector<pii> vect;
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	int origin = arr[1];
	int mx = -1, mxidx = -1;
	while (mxidx != 1) {
		mx = -1, mxidx = -1;
		for (int i = 1; i <= N; i++) {
			if (mx <= arr[i]) {
				mx = arr[i];
				mxidx = i;
			}
		}
		if (mxidx != 1) {
			arr[1]++;
			arr[mxidx]--;
		}
	}
	cout << arr[1] - origin;
	return 0;
}