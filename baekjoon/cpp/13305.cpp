#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef pair<int, int> pii;

int N, tmp, total, price;
vector<int> length;
priority_queue<pii, vector<pii>, greater<pii>> pq;
signed main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	length.push_back(0);
	for (int i = 1; i < N; i++) {
		cin >> tmp;
		length.push_back(tmp + length[i - 1]);
		total += tmp;
	}
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		pq.push({tmp,i});
	}
	while (total) {
		pii p = pq.top();
		pq.pop();

		if (total < length[p.second])
			continue;

		price += p.first * (total - length[p.second]);

		total = length[p.second];
	}
	cout << price;
	return 0;
}
