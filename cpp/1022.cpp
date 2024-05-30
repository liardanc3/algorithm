#include <bits/stdc++.h>
using namespace std;
int r1, c1, r2, c2, arr[51][5], mx, y, x, s, num = 1;
bool flag = true;
string ans[51][5];
void start() {
	if (y < -5000 || y>5000 || x < -5000 || x>5000) {
		flag = false;
		return;
	}
	// 내부면 체크
	if (r1 <= y && y <= r2 && c1 <= x && x <= c2) {

		int trueY = y - r1;
		int trueX = x - c1;

		arr[trueY][trueX] = num;

		mx = max(mx, num);
	}


	// 오른쪽아래
	if (y == s && x == s) {
		x++;
		s++;
		num++;
		return;
	}

	// 오른쪽위
	if (y == -s && x == s) {
		//start(y, x - 1, s, num + 1);
		x--;
		num++;
		return;
	}

	// 왼쪽위
	if (y == -s && x == -s) {
		y++;
		num++;
		return;
	}

	// 왼쪽아래
	if (y == s && x == -s) {
		//start(y, x + 1, s, num + 1);
		x++;
		num++;
		return;
	}

	// 오른쪽줄
	if (x == s) {
		//start(y - 1, x, s, num + 1);
		y--;
		num++;
		return;
	}

	// 윗줄
	if (y == -s) {
		//start(y, x - 1, s, num + 1);
		x--;
		num++;
		return;
	}

	// 왼쪽줄
	if (x == -s) {
		//start(y + 1, x, s, num + 1);
		y++;
		num++;
		return;
	}

	// 아랫줄
	if (y == s) {
		//start(y, x + 1, s, num + 1);
		x++;
		num++;
		return;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> r1 >> c1 >> r2 >> c2;
	while (flag)
		start();
	int len = to_string(mx).size();
	for (int i = 0; i <= r2 - r1; i++) {
		for (int j = 0; j <= c2 - c1; j++) {
			string now = to_string(arr[i][j]);

			ans[i][j] = "";
			for (int k = 0; k < len - now.size(); k++)
				ans[i][j] += " ";
			ans[i][j] += now;
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}