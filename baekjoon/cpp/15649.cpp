#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> vect;
int ck[9]{ 0, };
int arr[9]{ 0, };
int dfs(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		} cout << '\n';
		return 0;
	} 
	for (int i = 1; i <= N; i++) {
		if (ck[i] == 0) {
			arr[cnt] = i;
			ck[i] = 1; 
			dfs(cnt + 1);
			ck[i] = 0;
		}
	}
	return 0;
}

int main() {
	cin >> N >> M;
	dfs(0);
	return 0;
}