#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
using namespace std;
string str, pat;
int nxt[1000000]{ 0, }, cnt = 0;
void makeNext() {
	int dn = 0;
	for (int up = 1; up < pat.size(); up++) {
		while (dn > 0 && pat[up] != pat[dn])
			dn = nxt[dn - 1];
		if (pat[up] == pat[dn])
			nxt[up] = ++dn;
	}
}
void kmp() {
	int j = 0;
	vector<int> idx;
	for (int i = 0; i < str.size(); i++) {
		while (j > 0 && str[i] != pat[j])
			j = nxt[j - 1];

		if (str[i] == pat[j]) {
			if (j == pat.size() - 1) {
				cnt++;
				idx.push_back(i - pat.size() + 2);
				// 21-7+2
				j = nxt[j];
			}
			else j++;
		}
	}
	cout << cnt << '\n';
	for (int i = 0; i < idx.size(); i++) {
		cout << idx[i] << ' ';
	}
}
int main() {
	getline(cin, str);
	getline(cin, pat);
	makeNext();
	kmp();
	return 0;
}