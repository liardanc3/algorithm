#include <bits/stdc++.h>
using namespace std;
int N, point, P, tmp, rnk = 1, ans = -1;
vector<int> vect;
int main() {
	cin >> N >> point >> P;
	vect.push_back(2e9);
	vect.push_back(point);
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		vect.push_back(tmp);
	}
	sort(vect.rbegin(), vect.rend());

	for (int i = vect.size() - 1;; i--) {
		int now = vect[i];
		if (now == point) {
			if (i > P) cout << -1;
			else {
				for (int j = 1;; j++) {
					if (vect[j] == now) {
						cout << j;
						return 0;
					}

				}

			}

			return 0;
		}
	}
	return 0;
}