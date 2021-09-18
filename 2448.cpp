#include <bits/stdc++.h>
using namespace std;
const int N_MAX = 3 * 1024;
char arr[N_MAX+1][2 * N_MAX + 10];
int N;
void draw(int y, int x, int n) {
	arr[y][x] = '*';
	for (int i = 1; i < n; i++) {
		arr[y + i][x + i] = '*';
		arr[y + i][x - i] = '*';
	}
	int cnt = 0;
	for (int i = x-n+1; i <= x+n-1; i++) {
		arr[y+n-1][i] = '*';
		cnt++;
		if (cnt % 6 == 0)
			arr[y + n - 1][i] = ' ';
	}
	if (n != 3) {
		draw(y, x, n / 2);
		draw(y+n/2, x-n/2, n / 2);
		draw(y+n/2, x+n/2, n / 2);
	}
}

int main() {
	fill(&arr[0][0], &arr[N_MAX][2 * N_MAX + 10], ' ');
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin >> N;		
	draw(1,N, N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 2 * N + 1; j++) {
			cout << arr[i][j];
		}
		if (i != N)
			cout << '\n';
	}
	return 0;
}