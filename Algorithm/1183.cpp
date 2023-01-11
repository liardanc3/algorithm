#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll N, a, b;
vector<ll> gap;
vector<pii> vect;
int main() {
	cin >> N;
	for(int i=0; i<N; i++) {
		cin >> a >> b;
		vect.push_back({ a,b });
		gap.push_back(b - a);
	}
	sort(gap.begin(), gap.end());
	ll mn = 1e14, mncnt = 0;
	vector<ll> mnvect;
	for (int i = 0; i < gap.size(); i++) {
		ll now = 0, T = gap[i];
		for (int j = 0; j < N; j++) 
			now += abs((vect[j].first + T) - vect[j].second);
		if (mn == now) {
			mnvect.push_back(T);
			continue;
		}
		if (mn > now) {
			mn = now;
			mnvect.clear();
			mnvect.push_back(T);
			continue;
		}
	}
	sort(mnvect.begin(), mnvect.end());
	int start = mnvect[0], end = mnvect[mnvect.size() - 1];
	cout << end - start + 1;
	return 0;
}