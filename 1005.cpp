#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> tii;
priority_queue<tii, vector<tii>, less<tii>> pq;
int T, N, K, tmp1, tmp2, F, pay[1001], tree[1001], mx;
vector<int> vect[1001];
int getRoot(int i) {
	while (i != tree[i])
		i = tree[i];
	return i;
}
void dfs(int start,int sum) {
	for (int i = 0; i < vect[start].size(); i++) {
		int next = vect[start].at(i);
		sum += pay[next];
		if (mx < sum) mx = sum;
		dfs(next, sum);
		sum -= pay[next];
	}
}

int main() {
	cin >> T;
	while (T--) {
		cin >> N >> K;
		for (int i = 1; i <= N; i++) {
			cin >> pay[i];
			vect[i].clear();
		}
		for (int i = 0; i < K; i++) {
			cin >> tmp1 >> tmp2;
			vect[tmp2].push_back(tmp1);
		}
		cin >> F;
		mx = pay[F];
		dfs(F, pay[F]);
		cout << mx << '\n';
	}
	return 0;
}