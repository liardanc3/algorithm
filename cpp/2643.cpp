#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n, x, y;
vector<pii> point;
vector<int> vect;
bool cmp(pii &a, pii &b) {
	int x1 = a.first;
	int x2 = b.first;
	int y1 = a.second;
	int y2 = b.second;
	if (min(x1, y1) == min(x2, y2))
		return x1 + y1 <= x2 + y2;
	return min(x1, y1) < min(x2, y2);
}
int main() {
	cin >> n;
	while (n--) {
		cin >> x >> y;
		point.push_back({ x, y });
	}
	sort(point.begin(), point.end(), cmp);
	for (pii a : point) {
		int mx = max(a.first, a.second);
		if (!vect.size() || vect[vect.size() - 1] <= mx)
			vect.push_back(mx);
		else {
			int idx = upper_bound(vect.begin(), vect.end(), mx) - vect.begin();
			vect[idx] = mx;
		}
	}
	cout << vect.size();
	return 0;
}