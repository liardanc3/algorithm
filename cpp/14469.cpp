#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
vector<pii> vect;

int n, a, b, t;
int main() {
	cin >> n;
	while (n--) {
		cin >> a >> b;
		vect.push_back({ a,b });
	}
	sort(vect.begin(), vect.end());
	t = vect[0].first;
	for (pii p : vect) {
		int start = p.first;
		int dt = p.second;

		t = max(t, start);

		t += dt;
	}
	cout << t;
	return 0;
}