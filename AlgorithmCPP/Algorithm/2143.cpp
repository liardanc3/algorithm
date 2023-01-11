#include <bits/stdc++.h>
using namespace std;
long long t, n, m, tmp;
vector<int> nowA, nowB;
vector<int> vectA, vectB;
int main() {
	cin >> t;
	cin >> n;
	nowA.push_back(-1);
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		nowA.push_back(tmp);
	}
	cin >> m;
	nowB.push_back(-1);
	for (int i = 1; i <= m; i++) {
		cin >> tmp;
		nowB.push_back(tmp);
	}
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = i; j <= n; j++) {
			sum += nowA.at(j);
			vectA.push_back(sum);
		}
	}
	for (int i = 1; i <= m; i++) {
		int sum = 0;
		for (int j = i; j <= m; j++) {
			sum += nowB.at(j);
			vectB.push_back(sum);
		}
	}
	long long ret = 0;
	
	sort(vectA.begin(), vectA.end());
	sort(vectB.begin(), vectB.end());

	for (int i = 0; i < vectA.size(); i++) {
		int gap = t - vectA[i];
		long long up = upper_bound(vectB.begin(), vectB.end(), gap) - vectB.end();
		long long dn = lower_bound(vectB.begin(), vectB.end(), gap) - vectB.end();
		ret += up - dn;
	}
	cout << ret;
	return 0;
}