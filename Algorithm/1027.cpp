#include <bits/stdc++.h>
using namespace std;
int N, mx;
double arr[51];
vector<int> vect[51];
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	for (int i = 1; i < N; i++) {
		double ay = arr[i];
		for (int j = i+1; j <= N; j++) {
			if (i == j) continue;

			double by = arr[j];

			double xlen = j - i;
			double ylen = by - ay;
			double tick = ylen / xlen;

			bool flag = true;
			for (int k = i + 1; k < j && flag; k++) {
				double xgap = k - i;
				double ytmp = ay + xgap * tick;

				if (ytmp <= arr[k])
					flag = false;
			}

			if (flag) {
				vect[i].push_back(j);
				vect[j].push_back(i);
			}
		}
	}
	for (int i = 1; i <= N; i++)
		mx = max(mx, (int)vect[i].size());
	cout << mx;
	return 0;
}