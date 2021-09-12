#include <bits/stdc++.h>
using namespace std;
string S,tmp;
string xx[2000001];
int idx;
string plss(string a, string b) {
	string ans = "";
	if (a.size() > b.size())
		swap(a, b); // a°¡ÀÛÀ½
	int upper = 0;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	for (int i = 0; i < a.size(); i++) {
		int tmp = (a[i] - '0') + (b[i] - '0') + upper;
		upper = tmp / 10;
		ans += to_string(tmp % 10);
	}
	for (int i = a.size(); i < b.size(); i++) {
		int tmp = (b[i] - '0') + upper;
		upper = tmp / 10;
		ans += to_string(tmp % 10);
	}
	if (upper != 0)
		ans += to_string(upper);
	reverse(ans.begin(), ans.end());
	return ans;
}
string pls() {
	string X = "";
	for (int i = 0; i < idx; i++) {
		int now = 0, upper = 0;
		for (int j = i; j < idx; j++) {
			if (i == 0)
				reverse(xx[j].begin(), xx[j].end());
			now += xx[j][i] - '0';
		}
		string snow = to_string(now);
		for (int k = 0; k < i; k++) {
			snow += "0";
		}
		X = plss(snow, X);
	}
	return X;
}
void init() {
	S = "";
	cin >> tmp;
	for (int i = 0; i < tmp.size(); i++) {
		if (tmp[i] != '-') {
			S += tmp[i];
			xx[idx++] = S;
		}
		else
			reverse(S.begin(), S.end());
	}
}
int main() { 
	init();
	cout << pls();
	return 0;
}