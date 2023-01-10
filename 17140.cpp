#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int rarr[100][100], carr[100][100], r, c, k, rlen=3, clen=3, t, cnt[101], tmp;
vector<int> vect;
vector<pii> vect2;
void go() {
	if (rlen >= clen) {
		for (int i = 0; i < rlen; i++) {
			vect.clear(), vect2.clear();
			memset(cnt, 0, sizeof(cnt));
			for (int j = 0; j<100; j++)
				if(rarr[i][j]) vect.push_back(rarr[i][j]);
			sort(vect.begin(), vect.end());
			for (int j = 0; j < vect.size(); j++)
				cnt[vect[j]]++;
			for (int j = 1; j <= 100; j++) {
				if (cnt[j]) vect2.push_back({ cnt[j], j });
			}
			sort(vect2.begin(), vect2.end());
			for (int j = 0; j < 100; j++)
				rarr[i][j] = 0;
			for (int j = 0; j/2 < vect2.size(); j += 2) {
				rarr[i][j] = vect2[j / 2].second;
				rarr[i][j + 1] = vect2[j / 2].first;
			}
		}
		memset(carr, 0, sizeof(carr));
		clen = 0;
		for (int i = 0; i < 100; i++) {
			tmp = 0;
			for (int j = 0; j<100 && i<100; j++) {
				carr[j][i] = rarr[i][j];
				if (carr[j][i]) tmp++;
			}
			clen = max(clen, tmp);
		}
	}

	else {
		for (int i = 0; i < clen; i++) {
			vect.clear(), vect2.clear();
			memset(cnt, 0, sizeof(cnt));
			for (int j = 0; j<100; j++)
				if(carr[i][j]) vect.push_back(carr[i][j]);
			sort(vect.begin(), vect.end());
			for (int j = 0; j < vect.size(); j++)
				cnt[vect[j]]++;
			for (int j = 1; j <= 100; j++) {
				if (cnt[j]) vect2.push_back({ cnt[j],j });
			}
			sort(vect2.begin(), vect2.end());
			for (int j = 0; j < 100; j++)
				carr[i][j] = 0;
			for (int j = 0; j/2 < vect2.size(); j += 2) {
				carr[i][j] = vect2[j / 2].second;
				carr[i][j + 1] = vect2[j / 2].first;
			}
		}
		memset(rarr, 0, sizeof(rarr));
		rlen = 0;
		for (int i = 0; i < 100; i++) {
			tmp = 0;
			for (int j = 0; j<100 && i<100; j++) {
				rarr[j][i] = carr[i][j];
				if(rarr[j][i]) tmp++;
			}
			rlen = max(rlen, tmp);
		}
	}
}
int main() {
	cin >> r >> c >> k, r--, c--;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> rarr[i][j];
			carr[j][i] = rarr[i][j];
		}
	}
		
	while (t <= 100 && rarr[r][c] != k) {
		t++;
		go();
	}

	if (t == 101) cout << -1;
	else cout << t;
	return 0;
}