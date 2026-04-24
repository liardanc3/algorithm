#include <bits/stdc++.h>
using namespace std;

string a, b;
int cnt;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	getline(cin, a);
	getline(cin, b);
	for (int i = 0; i < a.size(); i++) {
		int start = i;
		int flag = 1;
		int end = 0;
		for (int j = 0; j < b.size() && i < a.size() && flag; j++) {
			if (a[i] == b[j]) {
				i++;
				if (j == b.size() - 1)
					end = 1;
			}
			else
				flag = 0;
		}
		if (flag && end)
			cnt++, i--;
		else
			i = start;
	}
	cout << cnt;
	return 0;
}
