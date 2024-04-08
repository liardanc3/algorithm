#include <bits/stdc++.h>
using namespace std;
int n, mx, arr[91];
string s;
vector<int> vect;
int main() {
	cin >> n;
	while (n--) {
		cin >> s;
		reverse(s.begin(), s.end());
		for (int i = s.size()-1; i >= 0; i--) {
			int now = s[i];
			arr[now] += pow(10, i);
		}
	}
	for (int i = 65; i <= 90; i++) {
		if (arr[i])
			vect.push_back(arr[i]);
	}
	sort(vect.rbegin(), vect.rend());
	for (int i = 0, j = 9; i < vect.size(); i++, j--) 
		mx += vect[i] * j;
	cout << mx;
	return 0;
}