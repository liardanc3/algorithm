#include <bits/stdc++.h>
using namespace std;
int n, visited[31][31];
double u, r, l, d, poss = 0;
void f(int k, int y, int x, double rate) {
	if (k == n) {
		poss += rate;
		return;
	}

	// r
	if (!visited[x + 1][y] && r>0) {
		visited[x + 1][y]++;
		f(k + 1, y, x + 1, rate * r);
		visited[x + 1][y]--;
	}

	// l
	if (!visited[x - 1][y] && l > 0) {
		visited[x - 1][y]++;
		f(k + 1, y, x - 1, rate * l);
		visited[x - 1][y]--;
	}

	// d
	if (!visited[x][y+1] && d>0) {
		visited[x][y + 1]++;
		f(k + 1, y+1, x, rate * d);
		visited[x][y + 1]--;
	}

	// u
	if (!visited[x][y-1] && u>0) {
		visited[x][y-1]++;
		f(k + 1, y-1, x, rate * u);
		visited[x][y-1]--;
	}
}
int main() {
	cin >> n >> r >> l >> d >> u;
	r /= 100, l /= 100, d /= 100, u /= 100;
	visited[15][15] = 1;
	f(0, 15, 15, 1);
	printf("%.10f", poss);
	return 0;
}