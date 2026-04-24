#include <bits/stdc++.h>
#define int long long
using namespace std;

int N, tmp, sum;
vector<int> vect;
signed main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	while (N--) {
		cin >> tmp;
		vect.push_back(tmp);
	}
	sort(vect.rbegin(), vect.rend());
	for (int i = 0; i < vect.size(); i++) {
		sum += max(vect[i] - i , 0LL);
	}
	cout << sum;
	return 0;
}
