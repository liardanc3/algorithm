#include <bits/stdc++.h>
using namespace std;
int n, tmp, m, cnt[51];
vector<int> vect, box;
int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		vect.push_back(tmp);
	}
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> tmp;
		box.push_back(tmp);
	}
	sort(vect.begin(), vect.end());
	sort(box.begin(), box.end());

	if (box[m-1] > vect[n - 1])
		cout << -1;
	else {
		int left = 1, right = m;
		while (left < right) {
			int mid = (left + right) / 2;
			memset(cnt, 0, sizeof(cnt));
			int j = 0;
			for (int i = 0; i < n && j<m; i++) {
				for (; j < m; j++) {
					if (cnt[i] < mid && box[j] <= vect[i]) 
						cnt[i]++;
					else break;
				}
			}

			if (j == m)
				right = mid;
			else left = mid + 1;
		}
		cout << right;
	}
	return 0;
}