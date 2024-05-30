#include <bits/stdc++.h>
#define int long long
#define DIV 1'000'000'007
using namespace std;

int D;

vector<vector<int>> vect{
	{0,1,1,0,0,0,0,0},
	{1,0,1,1,0,0,0,0},
	{1,1,0,1,1,0,0,0},
	{0,1,1,0,1,1,0,0},
	{0,0,1,1,0,1,0,1},
	{0,0,0,1,1,0,1,0},
	{0,0,0,0,0,1,0,1},
	{0,0,0,0,1,0,1,0}
};

vector<vector<int>> mul(vector<vector<int>> a, vector<vector<int>> b) {
	vector<vector<int>> ret;
	
	for (int i = 0; i < 8; i++) {
		vector<int> tmp;
		for (int j = 0; j < 8; j++) {
			int sum = 0;
			for (int k = 0; k < 8; k++) {
				sum += (a[i][k] % DIV) * (b[k][j] % DIV);
				sum %= DIV;
			}
			tmp.push_back(sum);
		}
		ret.push_back(tmp);
	}

	return ret;
}

vector<vector<int>> POW(vector<vector<int>> now, int p) {
	if (p == 1)
		return now;

	vector<vector<int>> ret = POW(now, p / 2);
	ret = mul(ret, ret);
	
	if (p % 2)
		ret = mul(now, ret);

	return ret;
}

signed main() {
	cin >> D;
	vector<vector<int>> ret = POW(vect, D);
	cout << ret[0][0] % DIV;
	return 0;
}