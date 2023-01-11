#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int M, N, L, tmp, x, y, cnt;
vector<pii> animal;
vector<int> shot;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> M >> N >> L;
	for (int i = 0; i < M; i++) {
		cin >> tmp;
		shot.push_back(tmp);
	}
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		animal.push_back({ y,x });
	}
	sort(shot.begin(), shot.end());
	
	for (int i = 0; i < animal.size(); i++) {
		y = animal[i].first;
		x = animal[i].second;

		int left = 0, right = shot.size() - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			int gap = abs(shot[mid] - x) + y;

			if (gap <= L) {
				cnt++;
				break;
			}
			else {
				if (shot[mid] > x)
					right = mid - 1;
				else
					left = mid + 1;
			}
		}
	}
	cout << cnt;
	return 0;
}