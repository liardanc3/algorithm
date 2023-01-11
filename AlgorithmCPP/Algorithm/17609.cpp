#include <bits/stdc++.h>
using namespace std;
int t;
string tmp;
bool zero(string str) {
	for (int i = 0; i < str.size() / 2; i++) {
		if (str[i] != str[str.size() - 1-i])
			return false;
	}
	return true;
}
int one(int left,int right,int skip) {
	while (left<=right) {
		int L = tmp[left];
		int R = tmp[right];
		if (L != R) {
			if (skip) return 0;
			else {
				int ret = one(left + 1, right, 1);
				if (!ret) ret = one(left, right - 1, 1);
				return ret;
			}

		}
		left++, right--;
	}
	return 1;
}
int palindrome() {
	if (zero(tmp)) return 0;
	if (one(0,tmp.size()-1,0)) return 1;
	return 2;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> tmp;
		cout << palindrome() << '\n';
	}
	return 0;
}