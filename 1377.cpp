#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

vector<pii> origin;
vector<int> vect;
int N, tmp, mx;

int main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> tmp;
			origin.push_back({ tmp, i });
		}
		sort(origin.begin(), origin.end());
	}();
	for (int i = 0; i < origin.size(); i++) 
		mx = max(mx, origin[i].second - (i + 1));
	cout << mx + 1;
	return 0;
}