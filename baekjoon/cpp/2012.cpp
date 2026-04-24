#include <bits/stdc++.h>
#define int long long
using namespace std;

int N, tmp, cnt;
vector<int> vect;
signed main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	while (N--) {
		cin >> tmp;
		vect.push_back(tmp);
	}
	sort(vect.begin(), vect.end());
	for (int i = 1; i <= vect.size(); i++) 
		cnt += abs(i - vect[i-1]);
	cout << cnt;
	return 0;
}