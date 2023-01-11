#include <iostream>
using namespace std;

int dps(int length, int width, int area[][50], int check[][50]) {
	if (length < 0 || length>49 || width < 0 || width>49)
		return 0;
	if (area[length][width] == 1) {
		if (check[length][width] == 0) {
			check[length][width] = 1;
			dps(length, width + 1,area,check);
			dps(length, width - 1,area,check);
			dps(length+1, width,area,check);
			dps(length-1, width,area,check);
			return 1;
		}
	}
	return 0;
}

int main() {
	int T; cin >> T;
	int width, length, count, ans, tmp_wid, tmp_len;
	for (int i = 0; i < T; i++) {
		int area[50][50] = { 0, };
		int check[50][50] = { 0, };
		cin >> width >> length >> count;
		ans = 0;
		for (int j = 0; j < count; j++) {
			cin >> tmp_wid >> tmp_len;
			area[tmp_len][tmp_wid] = 1;
		}
		for (int j = 0; j < length; j++) {
			for (int k = 0; k < width; k++)
				ans += dps(j, k, area, check);
		}
		cout << ans << "\n";
	}
}