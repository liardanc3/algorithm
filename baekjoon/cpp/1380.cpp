#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,t=0;
	while (cin >> n) {
		t++;
		if (n == 0) break;
		vector<string> vect;
		string tmp;
		cin.ignore();
		for (int i = 0; i < n; i++) {
			getline(cin, tmp);
			vect.push_back(tmp);
		}
		int arr[101]{ 0, };
		int k; char ch;
		for (int i = 0; i < 2 * n - 1; i++) {
			cin >> k >> ch;
			arr[k]++;
		}
		for (int i = 1; i <= n; i++) {
			if (arr[i] == 1) {
				cout << t << ' ' << vect[i - 1] << '\n';
				break;
			}
		}
	}
	return 0;
}