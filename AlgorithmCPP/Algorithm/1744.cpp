#include <bits/stdc++.h>
using namespace std;

int n, tmp, dp[51][51], ck[51][51], ps[51];
vector<int> vect;

int dynamic(int left, int right) {
	if (left > right) return 0;
	if (ck[left][right])
		return dp[left][right];

	int ret = 0;
	for (int i = left; i <= right; i++)
		ret += vect[i];
	
	for (int i = left; i + 1 <= right; i++) {
		ret = max(ret, 
			dynamic(left,i-1) + (vect[i] * vect[i + 1]) + dynamic(i + 2, right)
		);
	}

	ck[left][right] = 1;
	return dp[left][right] = ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> tmp;
		vect.push_back(tmp);
	}
	sort(vect.begin(), vect.end());
	cout << dynamic(0, n - 1);
	return 0;
}