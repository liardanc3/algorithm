#include <bits/stdc++.h>
using namespace std;

string A, B;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> A;
	for (int i = 0; i < A.size(); i++) {
		if (A[i] == '.') {
			B += '.';
			continue;
		}
		int cnt = 0;
		for (int j = i; j < A.size(); j++) {
			if (A[j] == 'X')
				cnt++;
			else
				break;
		}
		if (cnt % 4 == 0) {
			for (int j = 0; j < cnt; j++)
				B += 'A';
		}
		else if (cnt % 2 == 0) {
			for (int j = 0; j < cnt / 4; j++) for (int k = 0; k < 4; k++)
				B += 'A';
			B += "BB";
		}
		else {
			cout << -1;
			exit(0);
		}
		i += cnt - 1;
	}
	cout << B;
	return 0;
}
