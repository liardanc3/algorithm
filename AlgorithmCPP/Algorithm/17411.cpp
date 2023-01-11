#include <bits/stdc++.h>
#define DIV 1'000'000'007
using namespace std;

typedef pair<int, int> pii;
vector<int> lis, vect[1000000];

int N, tmp, arr[1000002];
int dynamic(int idx, int now) {
	if (idx == 0)
		return 1;

	int ret = 0;

	int nextidx = upper_bound(vect[idx - 1].begin(), vect[idx - 1].end(), now - 1) - vect[idx - 1].begin();
	for (int i = 0; i < nextidx; i++) {
		if (arr[vect[idx - 1][i]] < arr[now]) {
			ret += dynamic(idx - 1, vect[idx - 1][i]);
			ret %= DIV;
		}
	}
	
	return ret;
}
int main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> tmp;
			arr[i] = tmp;
			if (lis.empty() || lis[lis.size() - 1] < tmp) {
				lis.push_back(tmp);
				vect[lis.size() - 1].push_back(i);
			}
			else {
				int idx = lower_bound(lis.begin(), lis.end(), tmp) - lis.begin();
				int origin = lis[idx];
				while (idx + 1 < lis.size() && lis[idx + 1] == origin)
					idx++;
				lis[idx] = tmp;
				vect[idx].push_back(i);
			}
		}
		arr[1000001] = 2e9;
	}();
	cout << lis.size() << ' ' << dynamic(lis.size(), 1000001);
	return 0;
}