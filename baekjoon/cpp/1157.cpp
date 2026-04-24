#include <bits/stdc++.h>
using namespace std;
int cnt[200]{ 0, };
int main() {
	string str; cin >> str;
	for (int i = 0; i < str.size(); i++) {
		int now = str[i];
		if (now >= 97) now -= 32;
		cnt[now]++;
	}
	int mx = 0, mxidx = 0;
	for (int i = 65; i <= 90; i++) {
		if (cnt[i] > mx) {
			mx = cnt[i];
			mxidx = i;
		}
	}
	for (int i = 65; i <= 90; i++) {
		if (cnt[i] == mx && i!=mxidx) {
			cout << "?";
			exit(0);
		}
	}
	cout << (char)mxidx;
	return 0;
}