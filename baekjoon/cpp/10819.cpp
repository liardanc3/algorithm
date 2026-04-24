#include <bits/stdc++.h>
using namespace std;
vector<int> vect;
int N, tmp, mx = 0;

void makeMX() {
	int ans = 0;
	for (int i = 0; i < vect.size()-1; i++) {
		ans += abs(vect[i] - vect[i + 1]);
	}
	mx = max(mx, ans);
}
int main() {
	cin >> N;
	while (N--) {
		cin >> tmp;
		vect.push_back(tmp);
	}
	sort(vect.begin(), vect.end());
	do {
		makeMX();
	} while (next_permutation(vect.begin(), vect.end()));
	cout << mx;
	return 0;
}