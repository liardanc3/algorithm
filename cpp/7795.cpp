#include <bits/stdc++.h>
using namespace std;

int T, A, B, a, b, cnt;
vector<int> vecta, vectb;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	while (T--) {
		cnt = 0;
		vecta.clear(), vectb.clear();
		cin >> A >> B;
		while (A--) {
			cin >> a;
			vecta.push_back(a);
		}
		sort(vecta.begin(), vecta.end());
		while (B--) {
			cin >> b;
			vectb.push_back(b);
		}
		sort(vectb.begin(), vectb.end());
		for (int b : vectb) {
			int idx = upper_bound(vecta.begin(), vecta.end(), b) - vecta.begin();
			if(idx < vecta.size())
				cnt += vecta.size() - idx;
		}
		cout << cnt << '\n';
	}
	return 0;
}