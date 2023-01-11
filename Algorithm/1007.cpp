#include <bits/stdc++.h>
using namespace std;
int T, N, arr[11];
double vec[21][2], sumY, sumX, mn;
void bt(int cnt, int start) {
	if (cnt == N / 2 + 1) {
		double sY = sumY, sX = sumX;
		for (int i = 1; i < cnt; i++)
			sY -= (vec[arr[i]][0] + vec[arr[i]][0]);
		for (int i = 1; i < cnt; i++)
			sX -= (vec[arr[i]][1] + vec[arr[i]][1]);
		
		double r = sqrt(pow(sY, 2) + pow(sX, 2));

		if (r < mn) mn = r;
		return;
	}
	for (int i = start; i <= N; i++) {
		arr[cnt] = i;
		cnt++;
		bt(cnt, i + 1);
		cnt--;
	}
}

int main() {
	cin >> T;
	while (T--) {
		sumY = 0; sumX = 0;
		mn = 1.7976931348623158e308;
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> vec[i][0] >> vec[i][1];
			sumY += vec[i][0]; sumX += vec[i][1];
		}
		if (N == 2)
			printf("%f\n", sqrt(pow(vec[1][0] - vec[2][0], 2) + pow(vec[1][1] - vec[2][1], 2)));
		else {
			bt(1, 1);
			printf("%f\n", mn);
		}
	}

	return 0;
}