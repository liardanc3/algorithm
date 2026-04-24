#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
int A, B, C, aa, bb, cc;
vector<int> vect;
map<tii, int> dp;
void dfs(int a, int b, int c) {
	if (dp[{a, b, c}]) return;
	dp[{a, b, c}] = 1;

	if (a == 0) vect.push_back(c);

	// a->b
	aa = a, bb = b, cc = c;
	bb += aa;
	aa = 0;
	if (bb > B) {
		aa += bb - B;
		bb = B;
	}
	dfs(aa, bb, cc);

	// a->c
	aa = a, bb = b, cc = c;
	cc += aa;
	aa = 0;
	if (cc > C) {
		aa += cc - C;
		cc = C;
	}
	dfs(aa, bb, cc);

	// b->a
	aa = a, bb = b, cc = c;
	aa += bb;
	bb = 0;
	if (aa > A) {
		bb += aa - A;
		aa = A;
	}
	dfs(aa, bb, cc);

	// b->c
	aa = a, bb = b, cc = c;
	cc += bb;
	bb = 0;
	if (cc > C) {
		bb += cc - C;
		cc = C;
	}
	dfs(aa, bb, cc);

	// c->a
	aa = a, bb = b, cc = c;
	aa += cc;
	cc = 0;
	if (aa > A) {
		cc += aa - A;
		aa = A;
	}
	dfs(aa, bb, cc);

	// c->b
	aa = a, bb = b, cc = c;
	bb += cc;
	cc = 0;
	if (bb > B) {
		cc += bb - B;
		bb = B;
	}
	dfs(aa, bb, cc);

	return;
}
int main() {
	cin >> A >> B >> C;
	dfs(0, 0, C);
	sort(vect.begin(), vect.end());
	vect.erase(unique(vect.begin(), vect.end()),vect.end());
	for (int i : vect)
		cout << i << ' ';
	return 0;
}