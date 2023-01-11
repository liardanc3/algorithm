#include <bits/stdc++.h>
using namespace std;
string a, b;
int sum;
map<char, int> m;
map<int, char> mrev;
map<string, int> m2;
map<int, string> m2rev;
map<string, int> dp;
map<char, int> dp1;
void f(string s, int idx, int tmp, int last) {
	if (idx == s.size()) {
		sum += tmp;
		return;
	}

	// 2개
	if (idx + 1 < (int)s.size()) {
		string sb = s.substr(idx, 2);

		int flag = 1;
		if (sb == "IV" && dp["IX"]) flag = 0;
		if (sb == "IX" && dp["IV"]) flag = 0;
		if (sb == "XL" && dp["XC"]) flag = 0;
		if (sb == "XC" && dp["XL"]) flag = 0;
		if (sb == "CM" && dp["CD"]) flag = 0;
		if (sb == "CD" && dp["CM"]) flag = 0;


		if (!dp[sb] && flag && m2[sb]>0) {
			dp[sb] = 1;
			f(s, idx + 2, tmp + m2[sb], m2[sb]);
			dp[sb] = 0;
		}
	}

	// 1개
	char now = s[idx];
	int num = m[now];

	if ((now == 'V' || now == 'L' || now == 'D') && dp1[now]!=1 && num <= last) {
		dp1[now]++;
		f(s, idx + 1, tmp + num, num);
		dp1[now]--;
	}

	if ((now == 'I' || now == 'X' || now == 'C' || now=='M') && dp1[now] != 3 && num <= last) {
		dp1[now]++;
		f(s, idx + 1, tmp + num, num);
		dp1[now]--;
	}
	
	return;
}
void toString() {

	// 1000자리
	int _1000 = sum / 1000;
	for (int i = 0; i < _1000; i++)
		cout << "M";
	sum -= _1000 * 1000;

	// 100자리
	int _100 = sum / 100;
	if (_100 == 9) {
		cout << "CM";
		sum -= 900;
	}
	else if (_100 == 1 || _100 == 2 || _100 == 3) {
		for (int i = 0; i < _100; i++)
			cout << "C";
		sum -= _100 * 100;
	}
	else if (_100 == 5) {
		cout << "D";
		sum -= 500;
	}
	else if (_100 == 4) {
		cout << "CD";
		sum -= 400;
	}
	else if (6 <= _100 && _100 <= 8) {
		cout << "D";
		for (int i = 0; i < _100 - 5; i++)
			cout << "C";
		sum -= (_100 * 100);
	}

	// 10자리
	int _10 = sum / 10;
	if (_10 == 4) {
		cout << "XL";
		sum -= 40;
	}
	else if (_10 == 9) {
		cout << "XC";
		sum -= 90;
	}
	else if (_10 == 1 || _10 == 2 || _10 == 3) {
		for (int i = 0; i < _10; i++)
			cout << "X";
		sum -= _10 * 10;
	}
	else if (_10 == 5) {
		cout << "L";
		sum -= 50;
	}
	else if (6 <= _10 && _10 <= 8) {
		cout << "L";
		for (int i = 0; i < _10 - 5; i++)
			cout << "X";
		sum -= _10 * 10;
	}

	// 1자리
	int _1 = sum % 10;
	if (_1 == 9) cout << "IX";
	else if (_1 == 4) cout << "IV";
	else if (_1 == 5) cout << "V";
	else if (_1 == 1 || _1 == 2 || _1 == 3) {
		for (int i = 0; i < _1; i++)
			cout << "I";
	}
	else if (6 <= _1 && _1 <= 8) {
		cout << "V";
		for (int i = 0; i < _1 - 5; i++)
			cout << "I";
	}

	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	m['M'] = 1000, m['D'] = 500, m['C'] = 100, m['L'] = 50, m['X'] = 10, m['V'] = 5, m['I'] = 1;
	mrev[1000] = 'M', mrev[500] = 'D', m[100] = 'C', m[50] = 'L', m[10] = 'X', m[5] = 'V', m[1] = 'I';
	m2["IV"] = 4, m2["IX"] = 9, m2["XL"] = 40, m2["XC"] = 90, m2["CD"] = 400, m2["CM"] = 900;
	m2rev[4] = "IV", m2rev[9] = "XL", m2rev[90] = "XC", m2rev[400] = "CD", m2rev[900] = "CM";
	
	cin >> a >> b;
	f(a, 0, 0, 10000);
	dp.clear();
	dp1.clear();
	f(b, 0, 0, 10000);

	cout << sum << '\n';
	toString();
	return 0;
}