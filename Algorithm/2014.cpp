#include <bits/stdc++.h>
#include <assert.h>
#define int long long
#define MX 2147483647
using namespace std;

typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii>> pq;
vector<int> vect;
int N, K, tmp, mx;

void solution() {
	
	pq.push({ 1,0 });

	for(int i=0; i<N; i++) {
		int now = pq.top().first;
		int idx = pq.top().second;
		
		pq.pop();

		for (int j = idx; j < K && now * vect[j] <= MX; j++) {
			int next = now * vect[j];
			
			if (pq.size()+i > N && mx < next)
				break;

			pq.push({ next,j });
			mx = max(mx, next);
		}
	}
	cout << pq.top().first;
	return;
}
signed main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> K >> N;
		for (int i = 1; i <= K; i++) {
			cin >> tmp;
			vect.push_back(tmp);
		}
	}();

	solution();
	return 0;
}