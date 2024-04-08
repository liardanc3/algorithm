#include <bits/stdc++.h>
using namespace std;

int N, C, sum;
vector<int> vect;
signed main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	while (N--) {
		cin >> C;
		vect.push_back(C);
	}
	sort(vect.rbegin(), vect.rend());
	for (int i = 0; i < vect.size(); i++) {
		if (i + 2 < vect.size()) {
			sum += vect[i] + vect[i + 1];
			i += 2;
		}
		else {
			while (i < vect.size()) {
				sum += vect[i];
				i++;
			}
		}
	}
	cout << sum;
	return 0;
}
