#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

void floyd_warshall(int user[][101],int N) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) continue;
			for (int k = 1; k <= N; k++) {
				if (j==k) continue;
					user[j][k] = min(user[j][k], user[j][i] + user[i][k]);	
			}
		}
	}
}

int main() {
	int N, M, tmp1, tmp2, tmp=0;
	cin >> N >> M;
	int user[101][101];
	fill(&user[0][0], &user[N + 1][0], INF);
	for (int i = 0; i < M; i++) {
		cin >> tmp1 >> tmp2;
		user[tmp1][tmp2] = 1;
		user[tmp2][tmp1] = 1;
		user[tmp1][tmp1] = 0;
		user[tmp2][tmp2] = 0;
	}
	floyd_warshall(user,N);
	int ans; int min = INF;
	for (int i = 1; i <= N; i++) {
		ans = 0;
		for (int j = 1; j <= N; j++) 
			ans += user[i][j];
		if (ans < min) {
			min = ans;
			tmp = i;
		}
	}
	cout << tmp;
	return 0;
}