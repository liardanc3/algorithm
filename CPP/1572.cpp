#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef pair<int, int> pii;

priority_queue<pii> leftpq;
priority_queue<pii, vector<pii>, greater<pii>> rightpq;

vector<pii> vect;

int N, K, tmp, ans, leftsz, rightsz, position[250001];
signed main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> N >> K;
		for (int i = 0; i < N; i++) {
			cin >> tmp;
			vect.push_back({ tmp,i });
		}
	}();
	for (int i = 0; i < N; i++) {
		leftpq.push(vect[i]);
		leftsz++;

		while (!leftpq.empty() && leftpq.top().second < i + 1 - K)
			leftpq.pop();
		while (!rightpq.empty() && rightpq.top().second < i + 1 - K)
			rightpq.pop();

		while (!leftpq.empty() && !rightpq.empty() && leftpq.top() >= rightpq.top()) {
			rightpq.push(leftpq.top());
			position[leftpq.top().second] = 1;
			leftpq.pop();
			if(rightpq.top().second >= i+1-K)
				rightsz++, leftsz--;
		}
		while (rightsz > leftsz) {
			leftpq.push(rightpq.top());
			position[rightpq.top().second] = 0;
			rightpq.pop();
			if(leftpq.top().second >= i+1-K)
				rightsz--, leftsz++;
		}
		while (rightsz + 1 < leftsz) {
			rightpq.push(leftpq.top());
			position[leftpq.top().second] = 1;
			leftpq.pop();
			if(rightpq.top().second >= i+1-K)
				rightsz++, leftsz--;
		}
		// 3 : 
		// 3 : 4
		// 3 : 45
		while (!leftpq.empty() && leftpq.top().second < i + 1 - K)
			leftpq.pop();
		while (!rightpq.empty() && rightpq.top().second < i + 1 - K)
			rightpq.pop();

		if (i+1 >= K) {
			ans += leftpq.top().first;
			position[i + 1 - K] ? rightsz-- : leftsz--;
		}
			
	}
	cout << ans;
	return 0;
}