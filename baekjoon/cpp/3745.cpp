#include <bits/stdc++.h>
using namespace std;
int n, tmp;
vector<int> vect;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (cin >> n) {
		vect.clear();
		if (cin.eof())
			break;
		while (n--) {
			cin >> tmp;
			if (!vect.size() || vect[vect.size() - 1] < tmp)
				vect.push_back(tmp);
			else {
				int idx = lower_bound(vect.begin(), vect.end(), tmp) - vect.begin();
				vect[idx] = tmp;
			}
		}
		cout << vect.size() << '\n';
	}
	return 0;
}