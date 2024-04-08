#include <bits/stdc++.h>
using namespace std;

vector<int> vect;

int t, n, a, sum;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> t;
	while (t--) {
		vect.clear(); sum = 0;
		cin >> n;
		for (int i = 0; i < 20; i++) {
			cin >> a;
			vect.push_back(a);
		}
		for (int i = 0; i < 20; i++) {
			for (int j = i + 1; j < 20; j++) {
				if (vect[i] > vect[j])
					sum++;
			}
		}
		cout << n << ' ' << sum << '\n';
	}
	return 0;
}