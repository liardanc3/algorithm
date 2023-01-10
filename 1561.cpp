#include <bits/stdc++.h>
typedef long long ll;
using namespace std;	
int main() {
	vector<int> vect;
	int N, M, tmp;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> tmp;
		vect.push_back(tmp);
	}
	if (N <= M) {
		cout << N;
		return 0;
	}
	ll left = 1;
	ll right = 800000000000;
	//ll right = 15;
	ll ans = 0;
	while (left <= right) {
		ll mid = (left + right) / 2;
		ll cnt = 0;
		for (int i = 0; i < M; i++) {
			cnt += mid / vect[i] + 1;
		}
			
		if (cnt >= N) {
			right = mid - 1;	
		}
		else {
			left = mid + 1;
		}
	}
	int idx = -1;
	int cnt = 0;
	int ccnt = 0;
	stack<int> st;
	for (int i = 0; i < vect.size(); i++) {
		cnt += left / vect[i] + 1;
		if (left % vect[i] == 0)
			st.push(i + 1);
	}
	for (int i = 1; i <= cnt - N; i++) {
		st.pop();
	}
	cout << st.top();

	return 0;
}