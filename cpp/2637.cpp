#include <bits/stdc++.h>
#define FOR(i,n) for(int i=1; i<=n; i++)
int N, M, x, y, k, d[101][101], in[101];
int main() {
	std::cin >> N >> M;
	FOR(i,M) {
		std::cin >> x >> y >> k;
		d[x][y] = k;
		in[x]++;
	}
	FOR(i,N) FOR(j,N) FOR(k,N)
		d[k][j] += d[k][i] * d[i][j];
	FOR(i,N) if (!in[i])
		std::cout << i << ' ' << d[N][i] << '\n';
	return 0;
}