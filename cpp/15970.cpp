#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int N, a, b, dist;
vector<pii> vect;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	while (N--) {
		cin >> a >> b;
		vect.push_back({ b,a });
	}
	sort(vect.begin(), vect.end());

	for (int i = 0; i < vect.size(); i++) {
		pii p = vect[i];
		if (i == 0 || (i != 0 && vect[i - 1].first != p.first))
			dist += vect[i + 1].second - p.second;
		else if (p.first != vect[i - 1].first)
			dist += vect[i + 1].second - p.second;
		else if (i == vect.size()-1 || p.first != vect[i + 1].first)
			dist += p.second - vect[i - 1].second;
		else
			dist += min(p.second - vect[i - 1].second, vect[i + 1].second - p.second);
	}
	cout << dist;
	return 0;
}
