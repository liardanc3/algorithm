#include <bits/stdc++.h>
using namespace std;
int mx, K;
string tmp;
void bt(int start, int k) {
	if (k == K || start >= tmp.size()-1) {
		if((K-k)%2==0)
			mx = max(mx, stoi(tmp));
		return;
	}
	bt(start + 1, k);
	for (int i = start+1; i < tmp.size(); i++) {
		swap(tmp[start], tmp[i]);
		if (tmp[0] != '0')
			bt(start + 1, k + 1);
		swap(tmp[start], tmp[i]);
	}
	return;
}
int main() {
	cin >> tmp >> K;
	if ((tmp.size() == 2 && tmp[1] == '0') || tmp.size()==1) {
		cout << -1;
		return 0;
	}
	bt(0, 0);
	cout << mx;
	return 0;
}