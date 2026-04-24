#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
vector<pii> vect;

int N, x, y, mn = 1e9, ax, ay;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		vect.push_back({ x,y });
	}
	for (int i = 0; i < N; i++) {
		int mx = 0;
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			int dist = (vect[i].first - vect[j].first) * (vect[i].first - vect[j].first);
			dist += (vect[i].second - vect[j].second) * (vect[i].second - vect[j].second);
			
			if (mx < dist)
				mx = dist;
		}
		if (mx < mn) {
			ax = vect[i].first;
			ay = vect[i].second;
			mn = mx;
		}
	}
	cout << ax << ' ' << ay;
	return 0;
}