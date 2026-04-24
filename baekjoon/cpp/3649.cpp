#include <bits/stdc++.h>
using namespace std;
int x, n, tmp, Lans_odd, Rans_odd, Lans_even, Rans_even;
vector<int> odd, even;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (1) {
		cin >> x >> n;
		if (cin.eof()) break;
		x *= 10000000;

		while (n--) {
			cin >> tmp;
			tmp % 2 ? odd.push_back(tmp) : even.push_back(tmp);
		}

		if (odd.size() < 2 && even.size() < 2)
			cout << "danger\n";
		else {
			if (odd.size() >= 2) {
				sort(odd.begin(), odd.end());
				if (!((odd[0] + odd[1]) > x || (odd[odd.size() - 1] + odd[odd.size() - 2]) < x)) {
					int L = 0, R = odd.size() - 1;
					while (L < R) {
						int sum = odd[L] + odd[R];
						if (sum == x) {
							Lans_odd = odd[L], Rans_odd = odd[R];
							break;
						}

						if (sum < x) L++;
						else R--;
					}
				}
			}
			if (even.size() >= 2) {
				sort(even.begin(), even.end());
				if (!((even[0] + even[1] > x) || (even[even.size() - 1] + even[even.size() - 2]) < x)) {
					int L = 0, R = even.size() - 1;
					while (L < R) {
						int sum = even[L] + even[R];
						if (sum == x) {
							Lans_even = even[L], Rans_even = even[R];
							break;
						}

						if (sum < x) L++;
						else R--;
					}
				}
			}
	
			bool odd_is_x = (Lans_odd + Rans_odd) == x;
			bool even_is_x = (Lans_even + Rans_even) == x;

			if (odd_is_x && even_is_x) {
				if (abs(Lans_even - Rans_even) > abs(Lans_odd - Rans_odd))
					cout << "yes " << Lans_even << " " << Rans_even << '\n';
				if (abs(Lans_even - Rans_even) < abs(Lans_odd - Rans_odd))
					cout << "yes " << Lans_odd << " " << Rans_odd << '\n';
			}
			else if (odd_is_x)
				cout << "yes " << Lans_odd << ' ' << Rans_odd << '\n';
			else if (even_is_x)
				cout << "yes " << Lans_even << ' ' << Rans_even << '\n';
			else
				cout << "danger\n";
		}

		Lans_odd = 0, Rans_odd = 0, Lans_even = 0, Rans_even = 0;
		odd.clear();
		even.clear();
	}
	return 0;
}