#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int arr[20][20], ck[20][20];
int fishstack = 0, now = 2, ans = 0;
int dx[] = { 0,-1,1,0 };
int dy[] = { -1,0,0,1 };
vector<pii> vect;
int bfs(int N) {
	int cnt = 0;
	while (!vect.empty()) {
		cnt++;
		int size = vect.size();
		sort(vect.begin(), vect.end());
		for (int i = 0; i < size; i++) {
			pii temp = vect.at(0); vect.erase(vect.begin());
			for (int j = 0; j < 4; j++) {
				int y = temp.first + dy[j];
				int x = temp.second + dx[j];
				if (x >= 0 && x < N && y >= 0 && y < N && arr[y][x] <= now && ck[y][x]==0) {
					vect.push_back(pii(y, x)); ck[y][x] = 1;
				}
			}
		}
		int tmp_size = vect.size();
		int check = 0;
		sort(vect.begin(), vect.end());
		for (int i = 0; i < tmp_size; i++) {
			pii temp = vect.at(i);
			int y = temp.first;
			int x = temp.second;
			if (arr[y][x] < now && arr[y][x] > 0) {
				check = 1;
				fishstack++;
				if (fishstack == now) {
					fishstack = 0;
					now++;
				}
				arr[y][x] = 0;
				i = tmp_size;
				vect.clear();
				vect.push_back(pii(y, x));
				memset(ck, 0, sizeof(ck));
				ans = cnt;
			}
		}
	}
	return ans;
}
int main() {
	int N, tmp; cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> tmp; arr[i][j] = tmp;
			if (tmp == 9) {
				arr[i][j] = 0;
				vect.push_back(pii(i, j));
			}
		}
	} 
	cout << bfs(N);
	return 0;
}