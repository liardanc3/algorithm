#include <bits/stdc++.h>
using namespace std;
int N, tmp, cnt, zero;
map<int, int> m, origin;
vector<int> vect;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	while (N--) {
		cin >> tmp;
		vect.push_back(tmp);
		m[tmp]++;
		origin[tmp]++;
		if (tmp == 0) zero++;
	}
	if (zero >= 3) {
		cnt += zero;
		m[0] = 0;
	}
	sort(vect.begin(), vect.end());
	vect.erase(unique(vect.begin(), vect.end()), vect.end());
	for (int i = 0; i < vect.size(); i++) {
		for (int j = i; j < vect.size(); j++) {
			if (i == j && origin[vect[i]] == 1) continue;
			int sum = vect[i] + vect[j];
			if (sum == 0 && vect[i] == 0 && vect[j] == 0) continue;
			if ((vect[i] == 0 || vect[j] == 0) && origin[sum] == 1) continue;
			cnt += m[sum];
			m[sum] = 0;
		}
	}
	cout << cnt;
	return 0;
}