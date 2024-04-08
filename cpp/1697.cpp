#include <bits/stdc++.h>
#define INF 99999999
using namespace std;

int checking(int check[], int N, int K) {
	N + 1 <= 100000 ? check[N] = min(check[N], check[N + 1] + 1) : 0;
	N - 1 >= 0 ? check[N] = min(check[N], check[N - 1] + 1) : 0;
	N % 2 == 0 ? check[N] = min(check[N], check[N / 2] + 1) : 0;
	if (N + 1 <= 100000) 
		check[N + 1] = min(check[N + 1], check[N] + 1);
	if (N - 1 >= 0)
		check[N - 1] = min(check[N - 1], check[N] + 1);
	return check[K];
}

int main() {
	int N, K;
	int check[100001]{ 0, };
	fill(check, &check[100001], INF);
	cin >> N >> K;
	check[N] = 0;
	if (N > K) cout << N-K;
	else {
		for (int i = 0; i <= N - 1; i++) {
			check[i] = N - i;
		}
		while (N >= 0 && N <= 2 * K && N <= 100000) {
			checking(check, N, K);
			N++;
		}
		cout << check[K];
	}

	return 0;
}