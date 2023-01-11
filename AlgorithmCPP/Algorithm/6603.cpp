#include <bits/stdc++.h>
using namespace std;
int n, tmp, arr[100]{ 0, };
vector<int> vect;
void bt(int start, int now) {
	if (now == 6) {
		for (int i = 0; i < now; i++)
			cout << vect[arr[i]] << ' ';
		cout << '\n';
		return;
	}
	for (int i = start; i < n; i++) {
		arr[now] = i;
		bt(i + 1, now + 1);
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (cin >> n) {
		if (n == 0) break;
		int cnt = 0;
		vect.clear();
		for(int i=0; i<n; i++) {
			cin >> tmp;
			vect.push_back(tmp);
		}
		bt(0, 0);
		cout << '\n';
	}
	return 0;
}