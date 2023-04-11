#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> vect[9];
int N, arr[10][5][3], digit[10][5][3], arrtmp[5][3], total = 1, sum;
char tmp;
void f() {
	[&]() {
		for (int i = 0; i < N; i++) {
			for (int num = 0; num <= 9; num++) {
				copy(&arr[i][0][0], &arr[i][4][3], &arrtmp[0][0]);

				int cnt = 0;

				for (int y = 0; y < 5; y++) {
					for (int x = 0; x < 3; x++) {
						if (digit[num][y][x] == 1)
							arrtmp[y][x] = 0;
						if (arrtmp[y][x])
							cnt++;
					}
				}

				if (!cnt)
					vect[i].push_back(num);
			}
		}
	}();

	for (int i = 0; i < N; i++)
		total *= vect[i].size();

	if (total == 0)
		cout << -1;
	else {
		for (int i = N - 1, j = 0; i >= 0; i--, j++) {
			int upper = pow(10, i);

			for (int num : vect[j])
				sum += num * upper * total/vect[j].size();
		}

		double rate = (1.f * sum) / (total * 1.f);
		cout << fixed << setprecision(10) << rate;
	}
}
signed main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		[&]() {
			for (int i = 0; i <= 9; i++) {
				// raw 1
				if (i != 1) digit[i][0][0] = 1;
				if (i != 4 && i != 1) digit[i][0][1] = 1;
				digit[i][0][2] = 1;

				// raw 2
				if (i == 0 || i == 4 || i == 5 || i == 6 || i == 8 || i == 9)
					digit[i][1][0] = 1;
				if (i == 0 || i == 1 || i == 2 || i == 3 || i == 4 || i == 7 || i == 8 || i == 9)
					digit[i][1][2] = 1;

				// raw 3
				if (i == 0 || i == 2 || i == 3 || i == 4 || i == 5 || i == 6 || i == 8 || i == 9)
					digit[i][2][0] = 1;
				if (i == 2 || i == 3 || i == 4 || i == 5 || i == 6 || i == 8 || i == 9)
					digit[i][2][1] = 1;
				digit[i][2][2] = 1;

				// raw 4
				if (i == 0 || i == 2 || i == 6 || i == 8)
					digit[i][3][0] = 1;
				if (i == 0 || i == 1 || i == 3 || i == 4 || i == 5 || i == 6 || i == 7 || i == 8 || i == 9)
					digit[i][3][2] = 1;

				// raw 5
				if (i == 0 || i == 2 || i == 3 || i == 5 || i == 6 || i == 8 || i == 9)
					digit[i][4][0] = 1;
				if (i == 0 || i == 2 || i == 3 || i == 5 || i == 6 || i == 8 || i == 9)
					digit[i][4][1] = 1;
				digit[i][4][2] = 1;
			}
		}();
		
		cin >> N;
		for (int i = 0; i < 5; i++) {
			for (int j = 1; j <= 4 * N - 1; j++) {
				cin >> tmp;
				if (j % 4 == 0)
					continue;
				if (tmp == '#')
					arr[j / 4][i][j % 4 - 1] = 1;
			}
		}
	}();
	
	f();
	return 0;
}