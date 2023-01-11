#include <bits/stdc++.h>
using namespace std;
int n, m, tmp, arr[9];
vector<int> vect;
int bt(int start, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return 0;
	}
	for (int i = start; i < vect.size(); i++) {
		arr[cnt++] = vect.at(i);
		bt(i, cnt);
		cnt--;
	}
	return 0;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		vect.push_back(tmp);
	} sort(vect.begin(), vect.end());
	vect.erase(unique(vect.begin(), vect.end()), vect.end());
	bt(0, 0);
	return 0;
}