#include <bits/stdc++.h>
using namespace std;
int a, mx;
vector<int> vect, mxvect;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> a;
	for (int i = 0; i < a; i++) {
		vect.push_back(a);
		vect.push_back(a - i);
		while (vect[vect.size()-1] >= 0) 
			vect.push_back(vect[vect.size() - 2] - vect[vect.size() - 1]);
		if (vect.size() > mx) {
			mx = vect.size();
			mxvect = vect;
		}
		vect.clear();
	}
	cout << mx-1 << '\n';
	for (int i = 0; i < mxvect.size() - 1; i++)
		cout << mxvect[i] << ' ';
	return 0;
}
