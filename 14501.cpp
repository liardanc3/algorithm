#include <bits/stdc++.h>
using namespace std;
int n, t[16], p[16], mx = 0;

void bt(int start, vector<int> vect) {
	int sum = 0;
	for (int i = 0; i < vect.size(); i++)
		sum += p[vect[i]];
	mx = max(mx, sum);

	for (int i = start; i <= n; i++) {
		if (i-1 + t[i] > n) continue;
		vect.push_back(i);
		bt(i + t[i], vect);
		vect.erase(vect.begin() + vect.size() - 1);
	}

	return;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> t[i] >> p[i];
	vector<int> vect;
	bt(1, vect);
	cout << mx;
	return 0;
}