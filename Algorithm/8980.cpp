#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> tii;

vector<tii> vect;
int N, C, M, a, b, s, out[2001], mx;
bool cmp(const tii& a, const tii& b) {
	return get<1>(a) < get<1>(b);
}
int main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> N >> C >> M;
		for (int i = 0; i < M; i++) {
			cin >> a >> b >> s;
			vect.push_back({ a,b,min(C,s) });
		}
		sort(vect.begin(), vect.end(), cmp);
	}();
	for (int i = 0; i < vect.size(); i++) {
		int start = get<0>(vect[i]);
		int end = get<1>(vect[i]);
		int w = get<2>(vect[i]);

		int gap = 1e9;
		for (int j = start; j < end; j++) 
			gap = min(gap, C - out[j]);

		mx += min(w, gap);
		for (int j = start; j < end; j++)
			out[j] += min(w, gap);
	}
	cout << mx;
	return 0;
}