#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
vector<int> ck;
int ret[9]{ 0, };
int N, M;
int dfs(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << ret[i] << ' ';
		} cout << '\n';
		return 0;
	}
	for (int i = 0; i < arr.size(); i++) {
		if (ck.at(i)==0) {
			ck.at(i) = 1;
			ret[cnt++] = arr.at(i);
			dfs(cnt);
			cnt--;
			ck.at(i) = 0;
		}
	}
	return 0;
}
int main() {
	cin >> N >> M;
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		arr.push_back(tmp); ck.push_back(0);
	} sort(arr.begin(), arr.end());
	dfs(0);
	return 0;
}