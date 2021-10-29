#include <bits/stdc++.h>
using namespace std;
#define MX 4001
int A[MX], B[MX], C[MX], D[MX], n, sum;
long long ans = 0;
vector<int> vectL,vectR;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
		vectL.push_back(A[i] + B[j]);
		vectR.push_back(C[i] + D[j]);
	}
	sort(vectL.begin(), vectL.end());
	sort(vectR.begin(), vectR.end());
	int L = 0, R = n * n - 1;
	while (L < n * n && R >= 0) {
		int now = vectL[L] + vectR[R];
		if (now == 0) {
			int _L = L, _R = R;
			while (L < n*n && vectL[_L] == vectL[L]) L++;
			while (R >= 0 && vectR[_R] == vectR[R]) R--;
			ans += (1LL * (L - _L) * (_R - R));
			continue;
		}
		now > 0 ? R-- : L++;
	}
	cout << ans;
	return 0;
}