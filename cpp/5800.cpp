#include <bits/stdc++.h>
using namespace std;

int N, a, tmp, mn, mx;
vector<int> vect;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	for(int i=1; i<=N; i++) {
		mn = 1e9, mx = -1;
		vect.clear();
		cin >> a;
		while (a--) {
			cin >> tmp;
			vect.push_back(tmp);
		}
		sort(vect.begin(), vect.end());
		cout << "Class " << i << '\n' << "Max " << vect[vect.size() - 1] << ", Min " << vect[0];
		int lgap = 0;
		for (int j = 0; j < vect.size()-1; j++) {
			lgap = max(lgap, vect[j + 1] - vect[j]);
		}
		cout << ", Largest gap " << lgap << '\n';
	}

	return 0;
}
