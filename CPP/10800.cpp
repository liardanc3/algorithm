#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> tii;

int N, c, s, color[200001], sum, ans[200001], idx, ps[2001], sz[2001], mn = 1e9;
vector<tii> vect;
bool cmp(const tii& a, const tii& b) {
	if (get<0>(a) != get<0>(b))
		return get<0>(a) > get<0>(b);
	if (get<1>(a) != get<1>(b))
		return get<1>(a) < get<1>(b);
	return get<2>(a) < get<2>(b);
}
void init() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> c >> s;
		vect.push_back({ s,c,i });
		sz[s]++;
		color[c] += s;
		mn = min(mn, s);
	}
	sort(vect.begin(), vect.end(), cmp);
	for (int i = 1; i <= 2000; i++)
		ps[i] = ps[i - 1] + sz[i] * i;
}
int main() {
	init();
	for (int i = 0; i < vect.size() - 1; i++) {
		s = get<0>(vect[i]);
		if (s == mn) break;
		c = get<1>(vect[i]);
		idx = get<2>(vect[i]);
		
		int ns = get<0>(vect[i+1]);
		int nc = get<1>(vect[i+1]);		
		int cnt = 1;
		while (s == ns && c == nc) {
			cnt++;
			ns = get<0>(vect[i + cnt]);
			nc = get<1>(vect[i + cnt]);
		}
			
		ans[idx] += ps[s - 1];
		if (ans[idx]) {
			ans[idx] -= (color[c] - cnt * s);
			color[c] -= cnt*s;
		}
		
		for (int j = i+1; j < i + cnt; j++) {
			int nidx = get<2>(vect[j]);
			ans[nidx] = ans[idx];
		}
		i += (cnt - 1);
	}
	for (int i = 1; i <= N; i++)
		cout << ans[i] << '\n';
	return 0;
}