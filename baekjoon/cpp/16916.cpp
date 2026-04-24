#include <bits/stdc++.h>
using namespace std;
string text, pattern;
int nxt[1000000]{ 0, };
void makeNext() {
	int dn = 0;
	for (int up = 1; up < pattern.size(); up++) {
		while (dn > 0 && pattern[dn] != pattern[up])
			dn = nxt[dn - 1];
		if (pattern[up] == pattern[dn])
			nxt[up] = ++dn;
	}
}
bool kmp() {
	int dn = 0;
	for (int up = 0; up < text.size(); up++) {
		while (dn > 0 && text[up] != pattern[dn]) {
			dn = nxt[dn - 1];
		}
		if (pattern[dn] == text[up]) {
			if (dn == pattern.size() - 1) {
				return true;
			}
			else 
				dn++;
		}
	}
	return false;
}
int main() {
	cin >> text >> pattern;
	makeNext();
	kmp();
	cout << kmp();
	return 0;
}