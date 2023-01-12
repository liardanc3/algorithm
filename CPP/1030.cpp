#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int S, N, K, R1, R2, C1, C2;
int arr[50][50]{ 0, };
// 1 N*N N^2*N^2
void f(int y, int x, int s) {
	int gap = S - s;
	ll cnt = pow(N, gap);

	ll T = y * cnt;
	ll L = x * cnt;
	ll B = y * cnt + cnt - 1;
	ll R = x * cnt + cnt - 1;
	
	if (R2 < T || R1 > B || C2 < L || C1 > R) return;	

	//if (next_y > R2 || next_x > C2) return;
	
	if (s == S) {
		if(y-R1>=0 && x-C1>=0)
			arr[y - R1][x - C1] = 0;
		return;
	}
	int length = (N - K) / 2;

	// top
	for (int yy = 0; yy < length; yy++) {
		for (int xx = 0; xx < N; xx++)
			f(N * y + yy, N * x + xx, s + 1);
	}

	// bottom
	for (int yy = length+K; yy < N; yy++) {
		for (int xx = 0; xx < N; xx++)
			f(N * y + yy, N * x + xx, s + 1);
	}

	// left
	for (int yy = length; yy < length + K; yy++) {
		for (int xx = 0; xx < length; xx++)
			f(N * y + yy, N * x + xx, s + 1);
	}
	
	// right
	for (int yy = length; yy < length + K; yy++) {
		for (int xx = length+K; xx < N; xx++)
			f(N * y + yy, N * x + xx, s + 1);
	}
	
	return;
}

int main() {
	fill(&arr[0][0], &arr[49][50], 1);
	cin >> S >> N >> K >> R1 >> R2 >> C1 >> C2;
	f(0, 0, 0);
	for (int i = 0; i <= R2 - R1; i++) {
		for (int j = 0; j <= C2 - C1; j++)
			cout << arr[i][j];
		cout << '\n';
	}
	return 0;
}