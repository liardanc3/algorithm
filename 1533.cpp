#include <bits/stdc++.h>
#define int long long
#define DIV 1'000'003
using namespace std;

string tmp;
int N, S, E, T, arr[66][66];
vector<vector<int>> operator * (vector<vector<int>> a, vector<vector<int>> b) {
	vector<vector<int>> RET;
	for (int i = 0; i < N+ 4 * N; i++) {
		vector<int> ret;
		for (int j = 0; j < N+ 4 * N; j++) {
			int sum = 0;
			for (int k = 0; k < N+ 4 * N; k++) {
				sum += ((a[i][k] % DIV) * (b[k][j] % DIV)) % DIV;
			}
			sum %= DIV;
			ret.push_back(sum);
		}
		RET.push_back(ret);
	}
	return RET;
}
vector<vector<int>> operator + (vector<vector<int>> a, vector<vector<int>> b) {
	vector<vector<int>> RET;
	for (int i = 0; i < N + 4 * N; i++) {
		vector<int> ret;
		for (int j = 0; j < N + 4 * N; j++)
			ret.push_back((a[i][j] + b[i][j]) % DIV);
		RET.push_back(ret);
	}
	return RET;
}
vector<vector<int>> POW(vector<vector<int>> vect, int a) {
	if (a == 1)
		return vect;
	vector<vector<int>> RET = POW(vect, a / 2);
	RET = RET * RET;
	if (a % 2)
		RET = RET * vect;
	return RET;
}
signed main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	[&]() {
		cin >> N >> S >> E >> T;
		S--, E--;
		for (int i = 0; i < N; i++) {
			cin >> tmp;
			for (int j = 0; j < N; j++) {
				int m = tmp[j] - '0';
				if (m == 0) continue;
				if (m == 1)
					arr[i][j] = 1;
				else {
					arr[i][N + i * 4] = 1;
					if (m >= 3) {
						arr[N + i * 4][N + i * 4 + 1] = 1;
						if (m >= 4) {
							arr[N + i * 4 + 1][N + i * 4 + 2] = 1;
							if (m >= 5)
								arr[N + i * 4 + 2][N + i * 4 + 3] = 1;
						}
					}
					arr[N + i * 4 + m - 2][j] = 1;
				}
			}
		}
	}();
	
	vector<vector<int>> A, B;
	for (int i = 0; i < N + 4 * N; i++) {
		vector<int> a, b;
		for (int j = 0; j < N + 4 * N; j++) {
			if (i == j && i == S)
				a.push_back(1);
			else
				a.push_back(0);
			b.push_back(arr[i][j]);
		}
		A.push_back(a);
		B.push_back(b);
	}

	vector<vector<int>> vect = A * POW(B, T);
	cout << vect[S][E];
	return 0;
}