#include <bits/stdc++.h>
using namespace std;

int N, arr[400][400];
void print() {
	for (int i = 1; i <= 4 * N - 3; i++) {
		for (int j = 1; j <= 4 * N - 3; j++) {
			if (arr[i][j])
				cout << '*';
			else
				cout << ' ';
		}
		cout << '\n';
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	cin >> N;
	// 1 2 3 4  5  6
	// 1 5 9 13 17 21 

	// 4n-3
	for (int i = 1; i <= 4 * N - 3; i += 2)
		arr[(4 * N - 3) / 2 + 1][i] = 1;
	for (int i = 1; i <= (4 * N - 3) / 2; i += 2) {
		for (int j = i; j <= (4 * N - 3) - (i-1); j++)
			arr[i][j] = 1;
		for (int j = i; j <= (4 * N - 3) - (i - 1); j++)
			arr[4*N-3-(i-1)][j] = 1;
	}
	
	for (int i = 1; i <= 4 * N - 3; i += 2) {
		for (int j = i; j <= (4 * N - 3) - (i - 1); j++)
			arr[j][i] = 1;
		for (int j = i; j <= (4 * N - 3) - (i - 1); j++)
			arr[j][4 * N - 3 - (i - 1)] = 1;
	}

	print();


	return 0;
}
