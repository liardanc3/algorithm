#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
vector<pii> vect;
vector<int> lis, ans, update[100000];
int n, a, b, arr[500001], bidx2aidx[500001];
int main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> n;
		for(int i=0; i<n; i++) {
			cin >> a >> b;
			arr[a] = 1;
			bidx2aidx[b] = a;
			vect.push_back({ b,a });
		}
		sort(vect.begin(), vect.end());
	}();
	[&]() {
		for (pii p : vect) {
			int aidx = p.second;
			int bidx = p.first;

			if (lis.empty() || lis[lis.size() - 1] < aidx) {
				lis.push_back(aidx);
				update[lis.size() - 1].push_back(bidx);
			}
			else {
				int idx = lower_bound(lis.begin(), lis.end(), aidx) - lis.begin();
				lis[idx] = aidx;
				update[idx].push_back(bidx);
			}
		}
	}();
	[&]() {
		int right = update[lis.size() - 1][update[lis.size() - 1].size() - 1];
 		ans.push_back(bidx2aidx[right]);
		for (int i = lis.size() - 2; i >= 0; i--) {
			int idx = upper_bound(update[i].begin(), update[i].end(), right - 1) - update[i].begin();
			int bidx = update[i][idx-1];
			ans.push_back(bidx2aidx[bidx]);
			right = bidx;
		}
	}();
	[&]() {
		for (int i : ans)
			arr[i] = 0;
		cout << n - lis.size() << '\n';
		for (int i = 1; i <= 500000; i++)
			if (arr[i])
				cout << i << '\n';
	}();
	return 0;
}