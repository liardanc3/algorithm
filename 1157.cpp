#include <bits/stdc++.h>
using namespace std;
int arr[123]{ 0, };
int main() {
	string s; cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] > 96)
			s[i] -= 32;
		arr[s[i]]++;
	}
	vector<int> vect;
	for (int i = 65; i <= 90; i++) {
		vect.push_back(arr[i]);
	}
	sort(vect.rbegin(), vect.rend());
	if (vect[0] == vect[1])
		cout << '?';
	else {
		for (int i = 65; i <= 90; i++) {
			if (vect[0] == arr[i])
				cout << (char)i;
		}
	}
	return 0;
}