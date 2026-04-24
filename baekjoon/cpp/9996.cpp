#include <bits/stdc++.h>
using namespace std;

int N, flag;
string pat, str;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N >> pat;
	while (N--) {
		flag = 1;
		cin >> str;
		if (pat.size() > str.size()+1) {
			cout << "NE\n"; continue;
		}
		for (int i = pat.size() - 1, j = str.size() - 1; flag && i >= 0 && j >= 0; i--, j--) {
			if (pat[i] == '*')
				break;
			if (pat[i] == str[j])
				continue;
			else
				flag = 0;
		}
		for (int i = 0, j = 0; flag && i < pat.size() && j < str.size(); i++, j++) {
			if (pat[i] == '*')
				break;
			if (pat[i] == str[j])
				continue;
			else
				flag = 0;
		}
		if (flag)
			cout << "DA\n";
		else
			cout << "NE\n";
	}
	return 0;
}