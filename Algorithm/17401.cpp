#include <bits/stdc++.h>
#define int long long
#define DIV 1'000'000'007
using namespace std;

int T, N, D, M, a, b, c, ans[21][21], tmp[21][21], arr[101][21][21];

vector<vector<int>> operator *(const vector<vector<int>> a, const vector<vector<int>> b) {
	vector<vector<int>> ret;

	for (int i = 0; i < N; i++) {
		vector<int> v;
		for (int j = 0; j < N; j++) {
			int e = 0;
			for (int k = 0; k < N; k++) {
				e += ((a[i][k] % DIV) * (b[k][j] % DIV)) % DIV;
				e %= DIV;
			}
			v.push_back(e);
		}
		ret.push_back(v);
	}

	return ret;
}

vector<vector<int>> POW(vector<vector<int>> vect, int p) {
	if (p == 1)
		return vect;
	vector<vector<int>> mid = POW(vect, p / 2);
	mid = mid * mid;
	if (p % 2)
		return mid * vect;
	return mid;
}
signed main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	[&]() {
		cin >> T >> N >> D;
		for (int i = 0; i < T; i++) {
			cin >> M;
			for (int j = 0; j < M; j++) {
				cin >> a >> b >> c;
				arr[i][a][b] = c;
			}
		}
		for (int i = 1; i <= N; i++)
			ans[i][i] = 1;
	}();
	
	[&]() {
		for (int t = 0; t < min(T,D); t++) {
			memset(tmp, 0, sizeof(tmp));
			for (int root = 1; root <= N; root++) {
				for (int now = 1; now <= N; now++) {
					for (int next = 1; next <= N; next++) {
						tmp[root][next] += arr[t][now][next] * ans[root][now];
						tmp[root][next] %= DIV;
					}
				}
			}
			copy(&tmp[0][0], &tmp[20][21], &ans[0][0]);
		}
	}();
	[&]() {
		vector<int> v;
		vector<vector<int>> V;
		for (int i = 1; i <= N; i++) {
			v.clear();
			for (int j = 1; j <= N; j++)
				v.push_back(ans[i][j]);
			V.push_back(v);
		}
		int upper = D / T;
		if (upper == 0)
			return;
		int div = D % T;
		V = POW(V, upper);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				ans[i + 1][j + 1] = V[i][j];
		}
		for (int t = 0; t < div; t++) {
			memset(tmp, 0, sizeof(tmp));
			for (int root = 1; root <= N; root++) {
				for (int now = 1; now <= N; now++) {
					for (int next = 1; next <= N; next++) {
						tmp[root][next] += (arr[t][now][next] % DIV * ans[root][now] % DIV) % DIV;
						tmp[root][next] %= DIV;
					}
				}
			}
			copy(&tmp[0][0], &tmp[20][21], &ans[0][0]);
		}
	}();
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			cout << ans[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}