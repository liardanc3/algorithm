#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, x, sum;
int arr[100001]{ 0, };
vector<ll> vect[200001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	int mx = 1;
	while (n--) {
		cin >> x;
		arr[x]++;
		mx = max(mx, arr[x]);
		vect[arr[x]].push_back(x);
	}
	for (int i = 1; i <= mx; i++)
		sort(vect[i].begin(), vect[i].end());
	
	for (int i = 1; i <= mx; i++) {
		int cnt = 1;
		if (vect[i].size() == 1)
			sum += vect[i][0];
		for (int j = 1; j < vect[i].size(); j++) {
			if (vect[i][j] - 1 == vect[i][j - 1]) {
				cnt++;
			}
			else {
				sum += 1LL * cnt * vect[i][j - 1];
				cnt = 1;
			}

			if (j == vect[i].size() - 1) {
				sum += cnt * vect[i][j];
			}
		}
	}
	cout << sum;

	return 0;
}
