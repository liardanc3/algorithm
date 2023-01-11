#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> tii;

// 남자1 여자0
int N, M, arr[1001], tree[1001], a, b, d;
char gen;

priority_queue<tii, vector<tii>, greater<tii>> pq;

int getRoot(int i) {
	return tree[i] == i ? i : tree[i] = getRoot(tree[i]);
}
void MST() {
	int cnt = 0, ans = 0;
	while (!pq.empty() && cnt < N - 1) {
		int a = get<1>(pq.top());
		int b = get<2>(pq.top());
		int w = get<0>(pq.top());
	
		pq.pop();

		if (getRoot(a) == getRoot(b)) continue;

		tree[getRoot(a)] = getRoot(b);
		cnt++;
		ans += w;
	}
	if (cnt == N - 1)
		cout << ans;
	else
		cout << -1;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		tree[i] = i;
	for (int i = 1; i <= N; i++) {
		cin >> gen;
		if (gen == 'M')
			arr[i] = 1;
	}
	for (int i = 1; i <= M; i++) {
		cin >> a >> b >> d;
		if(arr[a]!=arr[b])
			pq.push({ d,a,b });
	}
	MST();
	return 0;
}