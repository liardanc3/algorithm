#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
ll N, x, y;
vector<pii> vect;
bool cmp(const pii A, const pii B) {
	return A.second < B.second;
}
ll DIST(int idx1, int idx2) {
	return (vect[idx2].first - vect[idx1].first) * (vect[idx2].first - vect[idx1].first)
		+ (vect[idx2].second - vect[idx1].second) * (vect[idx2].second - vect[idx1].second);
}
ll under3(int left, int right) {
	ll ret = 1e15;
	for (int i = left; i < right; i++) {
		for (int j = i + 1; j <= right; j++) 
			ret = min(ret, DIST(i, j));
	}
	return ret;
}
ll pass2(int left, int right, ll dist) {
	vector<pii> tmp;

	int mid = (left + right) / 2;

	for (int i = left; i <= right; i++) {
		ll gap = (vect[i].first - vect[mid].first) * (vect[i].first - vect[mid].first);

		if (gap <= dist)
			tmp.push_back(vect[i]);
	}

	sort(tmp.begin(), tmp.end(), cmp);
	
	for (int i = 0; i < tmp.size()-1; i++) {
		ll now = tmp[i].second;
		for (int j = i + 1; j < tmp.size(); j++) {
			ll next = tmp[j].second;

			dist = min(dist, (tmp[i].first - tmp[j].first) * (tmp[i].first - tmp[j].first)
				+ (tmp[i].second - tmp[j].second) * (tmp[i].second - tmp[j].second));
			
			if ((now - next) * (now - next) >= dist)
				break;
		}
	}

	return dist;
}
ll ClosestPair(int left, int right) {

	if (right - left <= 2)
		return under3(left, right);

	int mid = (left + right) / 2;

	ll LL = ClosestPair(left, mid);
	ll RR = ClosestPair(mid + 1, right);
	ll MM = pass2(left, right, min(LL, RR));

	return min(LL, min(RR, MM));
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		vect.push_back({ x,y });
	}
	sort(vect.begin(), vect.end());
	cout << ClosestPair(0, N - 1);
	return 0;
}