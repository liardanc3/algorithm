#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n, a, b;
vector<pii> inp;
vector<int> vect1;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		inp.push_back({ a,b });
	}
	sort(inp.begin(), inp.end());
	for (int i = 1; i <= n; i++) {
		if (vect1.empty() || vect1[vect1.size() - 1] < inp[i-1].second)
			vect1.push_back(inp[i - 1].second);
		else {
			int idx = lower_bound(vect1.begin(), vect1.end(), inp[i - 1].second) - vect1.begin();
			vect1[idx] = inp[i - 1].second;
		}
	}
	cout << n-vect1.size();
	return 0;
}