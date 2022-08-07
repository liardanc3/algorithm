#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
priority_queue<pii> pq;

vector<int> vect;
int N, M, arr[1000001];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	for (int i = M - (M - 1); i < M + (M - 1); i++)
		pq.push({ arr[i],i });
	for (int i = M + (M - 1), j = M; j <= N - M + 1; i++, j++) {
		if (i <= N)
			pq.push({ arr[i],i });
		while (j - pq.top().second >= M)
			pq.pop();
		vect.push_back(pq.top().first);
	}
	for (int i : vect)
		cout << i << ' ';
	return 0;
}