#include <bits/stdc++.h>
using namespace std;
int N, K, C, vect[10][500000], tok[10], len;
string tmp, ans = "";
int main() {
	fill(&vect[0][0], &vect[9][500000], -1);
	cin >> N >> K >> tmp;
	C = N - K;
	len = tmp.size();
	for (int i = 0; i < len; i++) {
		int now = tmp[i] - '0';
		vect[now][tok[now]++] = i;
	}
	memset(tok, 0, sizeof(tok));
	int idx = 0;
	while (C--) {
		bool flag = true;
		for (int i = 9; i >= 0 && flag; i--) {
			while (vect[i][tok[i]] != -1) {
				int _idx = vect[i][tok[i]];
				if (_idx < idx) 
					tok[i]++;
				else {
					if (_idx + C >= len)
						break;
					else {
						idx = _idx;
						ans += (char)(i + '0');
						tok[i]++;
						flag = false;
						break;
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}