#include <bits/stdc++.h>
#define int long long
using namespace std;

int N, tmp;
vector<int> vect;
signed main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	for(int i=0; i<N; i++) {
		cin >> tmp;
		vect.push_back(tmp);
	}
	sort(vect.begin(), vect.end());
	for (int i = N - 1; i >= 1; i--) {
		int k = vect[i];
		for (int j = i - 1; j >= 0; j--) {
			int z = vect[j];
			int yidx = j, xidx = 0;
			int y = vect[yidx];
			int x = vect[xidx];
			while (xidx <= yidx) {
				if (z + y + x == k ) {
					cout << k;
					return 0;
				}

				if (z + y + x < k)
					xidx++;
				else if (z + y + x > k)
					yidx--;

				y = vect[yidx];
				x = vect[xidx];
			}
		}
	}
	return 0;
}