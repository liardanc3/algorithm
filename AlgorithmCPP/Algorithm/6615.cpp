#include <bits/stdc++.h>
#define int long long
using namespace std;

int A, B;
vector<int> vect1, vect2;

signed main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	while (cin >> A >> B) {
		if (!A && !B) break;
		vect1.clear(), vect2.clear();
		vect1.push_back(A), vect2.push_back(B);
		while (A > 1) {
			if (A % 2)
				A = A * 3 + 1;
			else 
				A /= 2;
			vect1.push_back(A);
		}
		while (B > 1) {
			if (B % 2)
				B = B * 3 + 1;
			else
				B /= 2;
			vect2.push_back(B);
		}
		reverse(vect1.begin(), vect1.end());
		reverse(vect2.begin(), vect2.end());
		int i;
		for (i = 0; i<vect1.size() && i<vect2.size(); i++) {
			int a = vect1[i];
			int b = vect2[i];
			if (a != b) {
				break;
			}
		}
		i--;
		cout << vect1[vect1.size() - 1] << " needs " << vect1.size() - i-1 << " steps, ";
		cout << vect2[vect2.size() - 1] << " needs " << vect2.size() - i-1 << " steps, ";
		cout << "they meet at " << vect1[i] << '\n';
	}
	return 0;
}