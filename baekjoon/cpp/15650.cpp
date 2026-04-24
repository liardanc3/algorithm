#include <bits/stdc++.h>
using namespace std;
int ck[9]{ 0, };
int arr[9]{ 0, };
int N, M;

int dfs(int start, int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << ' ';
		} cout << '\n';
		return 0;
	} 
	for (int i = start; i <= N; i++) {
		if (ck[i] == 0) {
			ck[i] = 1;
			arr[cnt++] = i;
			dfs(++start, cnt);
			ck[i] = 0;
			cnt--;
			start = arr[cnt];
		}
	}
	return 0;
}


int main() {
	cin >> N >> M;
	dfs(1, 0);
	return 0;
}