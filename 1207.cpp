#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
vector<vector<vector<int>>> vect;
vector<int> permu;
int L, r, c, arr[11][11]{ 0, };
string tmp, fin = "";
void check(string ans) {
	for (int i = 0; i < fin.size(); i++) {
		if (ans[i] < fin[i]) {
			fin = ans;
			return;
		}
		else if (ans[i] > fin[i])
			return;
		else continue;
	}
	return;
}
void bt(int now) {
	for (int i = 1; i <= 5; i++)
		permu.push_back(i);
	do {
		bool possible = true;
		memset(arr, 0, sizeof(arr));
		for (int idx = 0; idx < 5 && possible; idx++) {
			int i = permu[idx] - 1;
			int y = 0, x = 0;
			int ylen = vect[i].size();
			int xlen = vect[i][1].size();
			for (int j = 1; j <= L - ylen + 2 && possible; j++) {
				for (int k = 1; k <= L - xlen + 2 && possible; k++) {
					int y = j, x = k;

					bool flag = true;

					for (int dy = y, yidx = 1; dy < y + ylen - 1 && flag; dy++, yidx++) {
						for (int dx = x, xidx = 1; dx < x + xlen - 1 && flag; dx++, xidx++) {
							if (arr[dy][dx] == 0)
								arr[dy][dx] = vect[i][yidx][xidx];
							else if (arr[dy][dx] != 0 && vect[i][yidx][xidx] != 0)
								flag = false;
						}
					}
					if (flag)
						j = 1e9, k = 1e9;
					else {
						for (int rr = 1; rr <= L; rr++) {
							for (int cc = 1; cc <= L; cc++) {
								if (arr[rr][cc] == i + 1)
									arr[rr][cc] = 0;
							}
						}
					}
				}
				if (j == L - ylen + 2)
					possible = false;
			}
		}
		if (possible) {
			string ans = "";
			bool ck = true;
			for (int i = 1; i <= L && ck; i++) {
				for (int j = 1; j <= L && ck; j++) {
					ans += (arr[i][j] + '0');
					if (arr[i][j] == 0)
						ck = false;
				}
			}
			if (ck)
				check(ans);
		}
	} while (next_permutation(permu.begin(), permu.end()));
	return;
}
void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> L;
	for (int i = 1; i <= 5; i++) {
		cin >> r >> c;
		vector<vector<int>> _v;
		vector<int> _tmp;
		_v.push_back(_tmp);
		for (int j = 0; j < r; j++) {
			cin >> tmp;
			vector<int> _t;
			_t.push_back(-1);
			for (int k = 0; k < c; k++) {
				if (tmp[k] == '.')
					_t.push_back(0);
				else _t.push_back(i);
			}
			_v.push_back(_t);
		}
		vect.push_back(_v);
	}
	for (int i = 1; i <= L; i++) for (int j = 1; j <= L; j++) {
		fin += '9';
	}
}
int main() {
	init();
	bt(0);
	if (fin[0] == '9')
		cout << "gg";
	else {
		int idx = 0;
		for (int i = 1; i <= L; i++) {
			for (int j = 1; j <= L; j++) {
				cout << fin[idx];
				assert(fin[idx] >= '1' && fin[idx] <= '5');
				idx++;
			}
			cout << '\n';
		}
	}
	return 0;
}