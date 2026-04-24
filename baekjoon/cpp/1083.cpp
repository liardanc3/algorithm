#include <bits/stdc++.h>
using namespace std;

int n, tmp, s;
vector<int> vect;

void srt(int start, int end, int ss) {
	if (start >= end || ss == 0)
		return;
	int mx = 0, mxidx = -1;
	for (int i = start; i <= min(end, start+ss); i++) {
		mx = max(mx, vect[i]);
		if (mx == vect[i])
			mxidx = i;
	}
	while (mxidx != start) {
		swap(vect[mxidx], vect[mxidx - 1]);
		mxidx--;
		ss--;
	}
	srt(start + 1, end, ss);
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	while (n--) {
		cin >> tmp;
		vect.push_back(tmp);
	}
	cin >> s;
	srt(0, vect.size()-1, s);
	for (int i : vect)
		cout << i << ' ';
	return 0;
}