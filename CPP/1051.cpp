#include <bits/stdc++.h>
using namespace std;

string tmp;
int N, M, arr[50][50], mx, visited[50][50][50][50];
int findmax(int ytop, int ybottom, int xleft, int xright) {
	if (visited[ytop][ybottom][xleft][xright])
		return -1;
	visited[ytop][ybottom][xleft][xright] = 1;
	if (ytop >= N || ybottom < 0 || xleft >= M || xright < 0)
		return -1;
	if (ytop == ybottom && xleft == xright)
		return 1;
	
	int lt = arr[ytop][xleft];
	int lb = arr[ybottom][xleft];
	int rt = arr[ytop][xright];
	int rb = arr[ybottom][xright];

	if (lt == lb && lt == rt && lt == rb)
		return (ybottom - ytop + 1) * (xright - xleft + 1);
	else
		return max(
			max(findmax(ytop, ybottom - 1, xleft, xright - 1), findmax(ytop, ybottom - 1, xleft + 1, xright)),
			max(findmax(ytop + 1, ybottom, xleft, xright - 1), findmax(ytop + 1, ybottom, xleft + 1, xright))
			);
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		for (int j = 0; j < M; j++)
			arr[i][j] = tmp[j] - '0';
	}
	if (N < M) {
		for (int i = 0, j = i + N - 1; j < M; i++, j++)
			mx = max(mx, findmax(0, N-1, i, j));
	}
	else if (N > M) {
		for (int i = 0, j = i + M - 1; j < N; i++, j++)
			mx = max(mx, findmax(i, j, 0, M-1));
	}
	else
		mx = findmax(0, N-1, 0, M-1);
	cout << mx;
	return 0;
}
