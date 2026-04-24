#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
vector<pii> vect;
int N, L, H, lx, rx, area;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	while (N--) {
		cin >> L >> H;
		vect.push_back({ H, L });
	}
	sort(vect.rbegin(), vect.rend());
	lx = vect[0].second;
	rx = vect[0].second;
	area += vect[0].first;
	for (int i = 1; i < vect.size(); i++) {
		pii now = vect[i];
		int height = now.first;
		int x = now.second;

		if (x > rx) {
			area += height * (x - rx);
			rx = x;
		}
		else if (x < lx) {
			area += height * (lx - x);
			lx = x;
		}
	}
	cout << area;
	return 0;
}