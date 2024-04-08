#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
int N, M, tmp;
int arr[9][9];
int arrtmp[9][9];
int ck[9][9];
int dy[]{ -1,0,0,1 };
int dx[]{ 0,-1,1,0 };
vector<pii> vect;
vector<tii> block_idx;
int btidx[3];
int bt(int start, int cnt) {
	if (cnt == 3) {
		block_idx.push_back(tii(btidx[0], btidx[1], btidx[2]));
		return 0;
	}
	for (int i = start; i < vect.size(); i++) {
		btidx[cnt] = i;
		cnt++;
		bt(i+1, cnt);
		cnt--;
	}
	return 0;
}
int dfs(int y, int x) {
	ck[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int yy = y + dy[i];
		int xx = x + dx[i];
		if (yy <= N && yy >= 1 && xx <= M && xx >= 1 &&
			ck[yy][xx] == 0 && arrtmp[yy][xx] == 0) {
			arrtmp[yy][xx] = 2;
			dfs(yy, xx);
		}
	}
	return 0;
}
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> tmp;
			if (tmp == 0) {
				vect.push_back(pii(i, j));
			}
			arr[i][j] = tmp;
		}
	}
	// vect에서 3개씩 뽑는 조합 구현
	bt(0, 0);
	int mx = 0;
	for (int i = 0; i < block_idx.size(); i++) {
		tii idx = block_idx.at(i);

		int n1 = get<0>(idx);
		int n2 = get<1>(idx);
		int n3 = get<2>(idx);
		// arrtmp에 뽑은 3개로 벽추가 구현
		copy(&arr[0][0], &arr[0][0]+81, &arrtmp[0][0]);
		pii ptmp1 = vect.at(n1); 
		pii ptmp2 = vect.at(n2);
		pii ptmp3 = vect.at(n3);
		arrtmp[ptmp1.first][ptmp1.second] = 1;
		arrtmp[ptmp2.first][ptmp2.second] = 1;
		arrtmp[ptmp3.first][ptmp3.second] = 1;

		// arrtmp로 배열전부 dfs돌려서 감염시킴
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (arrtmp[i][j] == 2 && ck[i][j]==0)
					dfs(i, j);
			}
		}

		int tp = 0;
		for (int m = 1; m <= N; m++) {
			for (int k = 1; k <= M; k++) {
				if (arrtmp[m][k] == 0)
					tp++;
			}
		}
		if (tp > mx) mx = tp;
		memset(ck, 0, sizeof(ck));
	}
	
	cout << mx;
	// 배열에서 0갯수 max에 저장

	return 0;
}