#include <bits/stdc++.h>
using namespace std;
int arr[100][100];

void floyd_ws(int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
 				(arr[j][i] == 1 && arr[i][k] == 1) ? arr[j][k] = 1 : 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(arr, 0, sizeof(arr));
	int N, tmp; cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> tmp;
			arr[i][j] = tmp;
		}
	}
	floyd_ws(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) 
			cout << arr[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}