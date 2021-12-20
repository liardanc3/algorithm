#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	vector<bool> vect(pow(2, 20) + 1);
	int n, q, want, tmp; cin >> n >> q;
	while (q--) {
		cin >> want;
		tmp = want;
		while (want>1 && !vect[want])
			want /= 2;
		if (want == 1) {
			cout << 0 << '\n';
			vect[tmp] = true;
		}
		else {
			int first;
			while (want != 1) {
				if (vect[want])
					first = want;
				want /= 2;
			}
			cout << first << '\n';
		}
	}
}