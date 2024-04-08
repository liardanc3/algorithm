#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
map<int, pii> pos;

int arr[5][5], line, tmp;
void setarr(pii p) {
	arr[p.first][p.second] = 0;

	// 세로
	int cnt = 0;
	for (int i = 0; i < 5; i++) {
		if (arr[i][p.second] == 0)
			cnt++;
	}
	if (cnt == 5)
		line++;

	// 가로
	cnt = 0;
	for (int i = 0; i < 5; i++) {
		if (arr[p.first][i] == 0)
			cnt++;
	}
	if (cnt == 5)
		line++;

	// 대각1
	cnt = -1;
	for (int i = p.first, j = p.second; i < 5 && j < 5; i++, j++)
		if (arr[i][j] == 0) cnt++;
	for (int i = p.first, j = p.second; i >=0 && j >= 0; i--, j--)
		if (arr[i][j] == 0) cnt++;
	if (cnt == 5)
		line++;


	// 대각2 
	cnt = -1;
	for (int i = p.first, j = p.second; i < 5 && j >= 0; i++, j--)
		if (arr[i][j] == 0) cnt++;
	for (int i = p.first, j = p.second; i >= 0 && j < 5; i--, j++)
		if (arr[i][j] == 0) cnt++;
	if (cnt == 5)
		line++;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
			pos[arr[i][j]] = { i,j };
		}
	}
	for (int i = 0; i < 25; i++) {
		cin >> tmp;
		pii p = pos[tmp];
		if (line < 3) {
			setarr(p);
			if (line >= 3)
				cout << i + 1;
		}
	}
	return 0;
}
