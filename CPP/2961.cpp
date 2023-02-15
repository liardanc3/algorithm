#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
vector<pii> vect;

int n, s, b, mn = 1e9;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> s >> b;
		vect.push_back({ s,b });
	}
	for (int i = 1; i < 1<<n; i++) {
		int news = 1, newb = 0, idx = 0, bit = i;
		while (bit) {
			if (bit & 1) {
				news *= vect[idx].first;
				newb += vect[idx].second;
			}
			idx++;
			bit >>= 1;
		}
		mn = min(mn, abs(news - newb));
	}
	cout << mn;
	return 0;
}