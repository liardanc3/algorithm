#include <bits/stdc++.h>
using namespace std;
int arr[10][10]{ 0, }, N, M, mx = -1, now;
void makeSUM(int y, int x, int i, int j) {
	string sum = "";
	string rsum = "";
	int r, c;
	for (r = y, c=x; 1<=r && r <= N && 1<=c && c<=M; r += i,c+=j){ 
		sum += arr[r][c] + '0';
		int _sum = stoi(sum);
		double root = sqrt(_sum);
		if (floor(root) == root)
			mx = max(mx, _sum);

		reverse(sum.begin(), sum.end());
		_sum = stoi(sum);
		root = sqrt(_sum);
		if (floor(root) == root)
			mx = max(mx, _sum);

		reverse(sum.begin(), sum.end());

		if (j == 0 && i == 0) break;
	}
}
void makePN(int y, int x) {
	for (int i = -N; i <= N; i++) {
		if (y + i<1 || y + i>N) continue;
		for (int j = -M; j <= M; j++) {
			if (x + j<1 || x + j>M) continue;
			makeSUM(y, x, i, j);
		}
	}
}
int main() {
	cin >> N >> M;
	string tmp;
	for (int i = 1; i <= N; i++){
		cin >> tmp;
		for (int j = 1; j <= M; j++)
			arr[i][j] = tmp[j - 1]-'0';
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			makePN(i, j);
		}
	}
	cout << mx;
	return 0;
}