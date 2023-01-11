#include <bits/stdc++.h>
using namespace std;
vector<int> vect(11);
int n, tmp, mx = 0;
void bt(int cnt, int sum, vector<int> vect) {
	if (vect.size()==2) {
		mx = max(mx, sum);
		return;
	}
	for (int i = 1; i < vect.size() - 1; i++) {
		vector<int> _vect = vect;
		int _tmp = _vect[i - 1] * _vect[i + 1];
		_vect.erase(_vect.begin() + i);
		bt(cnt + 1, sum+_tmp, _vect);
	}
}
int main() {
	vector<int> vect;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		vect.push_back(tmp);
	}
	bt(0, 0, vect);
	cout << mx;
	return 0;
}