#include <bits/stdc++.h>
using namespace std;
int kmp(string str, vector<int> vect) {
	string pat = str;
	str += str;
	for (int i = 1, j = 0; i < str.size(); i++) {
		while (j > 0 && str[i] != pat[j])
			j = vect[j - 1];
		if (str[i] == pat[j]) {
			if (j == pat.size() - 1)
				return i-j;
			else
				++j;
		}
	}
}
int makeNext(string str) {
	vector<int> vect;
	vect.push_back(0);
	int j = 0;
	for (int i = 1; i < str.size(); i++) {
		while (j > 0 && str[i] != str[j])
			j = vect[j - 1];
		if (str[i] == str[j])
			vect.push_back(++j);
		else
			vect.push_back(0);
	}
	return kmp(str,vect);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string str;
	while (cin >> str) {
		if (str == ".") break;
		cout << str.size() / makeNext(str) << '\n';
	}
	return 0;
}