#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
int n, m, tmp;
vector<int> vect;
signed main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		vect.push_back(tmp);
	}
	sort(vect.begin(),vect.end());
	int left = 1, right = vect[n-1]*m;

	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = 0;
		for (int i = 0; i < n; i++) 
			cnt += mid / vect[i];

		if (m < cnt) 
			right = mid - 1;
		else 
			left = mid + 1;
	}
	int mx = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		int div = right / vect[i];
		mx = max(mx, div * vect[i]);
		cnt += div;
	}
	if (cnt >= m) {
		cout << mx << ' ';
		return 0;
	}
	mx = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		int div = left / vect[i];
		mx = max(mx, div * vect[i]);
	}
	cout << mx << ' ';
	return 0;
}