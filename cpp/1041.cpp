#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
int a, b, c, d, e, f, n;
int min(vector<int> vect) {
	int mn = 1e9;
	for (int i : vect) mn = min(mn, i);
	return mn;
}
signed main() {
	cin >> n >> a >> b >> c >> d >> e >> f;

	if (n == 1) 
		cout << a + b + c + d + e + f - max(max(a, b), max(max(c, d), max(e, f)));
	else {
		// 3개 최소
	    // ace ade abc abd fbc fbd fed fec
		vector<int> tmp;
		tmp.push_back(a + c + e), tmp.push_back(a + d + e), tmp.push_back(a + b + c), tmp.push_back(a + b + d);
		tmp.push_back(f + b + c), tmp.push_back(f + b + d), tmp.push_back(f + e + d), tmp.push_back(f + e + c);
		int _3 = min(tmp);

		// 2개 최소
		// ab ac ad ae bc bd bf ce cf de df ef
		tmp.clear();
		tmp.push_back(a + b), tmp.push_back(a + c), tmp.push_back(a + d);
		tmp.push_back(a + e), tmp.push_back(b + c), tmp.push_back(b + d);
		tmp.push_back(b + f), tmp.push_back(c + e), tmp.push_back(c + f);
		tmp.push_back(d + e), tmp.push_back(d + f), tmp.push_back(e + f);
		int _2 = min(tmp);

		// 1개 최소
		// a b c d e f
		tmp.clear();
		tmp.push_back(a), tmp.push_back(b), tmp.push_back(c);
		tmp.push_back(d), tmp.push_back(e), tmp.push_back(f);
		int _1 = min(tmp);

		int ret = 0;
		ret += _3 * 4; // 맨위층 모서리 4개
		ret += _2 * (n - 2) * 4; // 맨위층 가장자리
		ret += _2 * (n - 1) * 4; // 전층 모서리 세로줄
		ret += _1 * (n - 2) * (n - 2); // 맨위층 1개짜리
		ret += _1 * (n - 1) * (n - 2) * 4; // 나머지 1개짜리
		cout << ret;
	}
	return 0;
}