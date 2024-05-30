#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int n, w, L, arr[1001], wsum, t, idx = 1;
deque<pii> deq;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> w >> L;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	
	while (++t) {

		// 맨앞차 다리밖으로 나올 수 있음
		if (!deq.empty() && deq.front().second + w == t) {
			wsum -= deq.front().first;
			deq.pop_front();
		}
			
		// 다리 무게 초과x
		if (idx <= n && deq.size() < w && wsum + arr[idx] <= L) {
			deq.push_back({ arr[idx],t });
			wsum += arr[idx];
			idx++;
		}

		if (idx == n + 1 && deq.empty()) {
			cout << t;
			break;
		}
	}
	return 0;
}