#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int main() {
	vector<pii> vect;
	int n, x, y, rank[51]{ 0, };
	fill(&rank[0], &rank[51], 1);
	cin >> n;
	while (n--) {
		cin >> x >> y;
		vect.push_back({ x,y });
	}
	for (int i = 0; i < vect.size(); i++) {
		int now_x = vect[i].first;
		int now_y = vect[i].second;
		for (int j = 0; j < vect.size(); j++) {
			if (i == j) continue;
			int next_x = vect[j].first;
			int next_y = vect[j].second;
			if (now_x < next_x && now_y < next_y)
				rank[i]++;
		}
	}
	for (int i = 0; i < vect.size(); i++)
		cout << rank[i] << ' ';

	return 0;
}