#include <bits/stdc++.h>
using namespace std;

int N, tmp, mx;
vector<int> vect;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	while (N--) {
		cin >> tmp;
		vect.push_back(tmp);
	}
	sort(vect.rbegin(), vect.rend());
	for (int i = 0; i < vect.size(); i++) 
		mx = max(mx, i + 2 + vect[i]);
	cout << mx;
	return 0;
}
