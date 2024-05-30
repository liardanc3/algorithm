#include <bits/stdc++.h>
#include <assert.h>
using namespace std;

int t, r, c, lx, rx, ty, by;
string tmp;
int arr[10][10];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> t;
	while (t--) {
		memset(arr, 0, sizeof(arr));
		lx = 9, rx = 0, ty = 9, by = 0;
		cin >> r >> c;

		[&]() {
			for (int i = 0; i < r; i++) {
				cin >> tmp;
				for (int j = 0; j < c; j++) {
					arr[i][j] = (tmp[j] == '#') ? 1 : 0;
					if (arr[i][j]) {
						lx = min(lx, j);
						rx = max(rx, j);
						by = max(by, i);
						ty = min(ty, i);
					}
				}
			}
		}();

		if (rx - lx == by - ty) {
			int lt = arr[ty][lx];
			int rt = arr[ty][rx];
			int lb = arr[by][lx];
			int rb = arr[by][rx];

			// 한쪽 모서리만 깎인거 확인
			if (lt + rt + lb + rb == 3) {
				
				// 빈 공간 개수 
				int square_size = 0;
				for (int i = ty; i <= by; i++) {
					for (int j = lx; j <= rx; j++) {
						if (arr[i][j] == 0)
							square_size++;
					}
				}

				if ((int)sqrt(square_size) * (int)sqrt(square_size) != (int)square_size)
					cout << 0 << '\n';
				else {
					if (lt == 0) {
						int cream_tmp = 0;
						int sz = sqrt(square_size);
						for (int i = ty; i < ty + sz; i++) {
							for (int j = lx; j < lx + sz; j++) {
								if (arr[i][j] == 0)
									cream_tmp++;
							}
						}
						if (cream_tmp == square_size)
							cout << 1 << '\n';
						else
							cout << 0 << '\n';
					}
					else if (rt == 0) {
						int cream_tmp = 0;
						int sz = sqrt(square_size);
						for (int i = ty; i < ty + sz; i++) {
							for (int j = rx; j > rx-sz; j--) {
								if (arr[i][j] == 0)
									cream_tmp++;
							}
						}
						if (cream_tmp == square_size)
							cout << 1 << '\n';
						else
							cout << 0 << '\n';
					}
					else if (rb == 0) {
						int cream_tmp = 0;
						int sz = sqrt(square_size);
						for (int i = by; i > by - sz; i--) {
							for (int j = rx; j > rx - sz; j--) {
								if (arr[i][j] == 0)
									cream_tmp++;
							}
						}
						if (cream_tmp == square_size)
							cout << 1 << '\n';
						else
							cout << 0 << '\n';
					}
					else if(lb == 0){
						int cream_tmp = 0;
						int sz = sqrt(square_size);
						for (int i = by; i > by-sz; i--) {
							for (int j = lx; j < lx + sz; j++) {
								if (arr[i][j] == 0)
									cream_tmp++;
							}
						}
						if (cream_tmp == square_size)
							cout << 1 << '\n';
						else
							cout << 0 << '\n';
					}
					else
						assert(false);
				}
			}
			else
				cout << 0 << '\n';
		}
		else
			cout << 0 << '\n';
	}
	return 0;
}
