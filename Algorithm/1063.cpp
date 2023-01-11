#include <bits/stdc++.h>
using namespace std;
int arr[9][9]{ 0, }, N;
string king, stone, cmd;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> king >> stone >> N;
	int king_col = king[0] - 64;
	int king_row = king[1] - '0';
	int stone_col = stone[0] - 64;
	int stone_row = stone[1] - '0';
	int krn, kcn, srn, scn;
	arr[king_row][king_col] = 1;
	arr[stone_row][stone_col] = 2;
	while (N--) {
		cin >> cmd;
		int row = 0, col = 0;
		for (int i = 0; i < cmd.size(); i++) {
			if (cmd[i] == 'B') row--;
			if (cmd[i] == 'T') row++;
			if (cmd[i] == 'R') col++;
			if (cmd[i] == 'L') col--;
		}
		krn = king_row + row;
		kcn = king_col + col;
		srn = stone_row + row;
		scn = stone_col + col;
		if (krn < 1 || krn>8 || kcn < 1 || kcn>8) continue;
		if (arr[krn][kcn] != 2) {
			arr[krn][kcn] = 1;
			arr[king_row][king_col] = 0;
			king_row = krn;
			king_col = kcn;
			continue;
		}
		if (arr[krn][kcn] == 2) {
			if (1 <= srn && srn <= 8 && 1 <= scn && scn <= 8) {
				arr[srn][scn] = 2;
				arr[krn][kcn] = 1;
				arr[king_row][king_col] = 0;
				stone_row = srn;
				stone_col = scn;
				king_row = krn;
				king_col = kcn;
				continue;
			}
		}
	}
	cout << (char)(king_col + 64) << king_row << '\n';
	cout << (char)(stone_col + 64) << stone_row;
	return 0;
}