#include <bits/stdc++.h>
using namespace std;
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
	return vect[vect.size()-1];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string str;
	while (cin >> str) {
		if (str == ".") break;
		cout << str.size() / (str.size() - makeNext(str)) << '\n';
	}
	return 0;
}