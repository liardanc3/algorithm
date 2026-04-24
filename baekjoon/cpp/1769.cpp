#include <bits/stdc++.h>
using namespace std;

int cnt;
string tmp;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> tmp;
	while (tmp.size() > 1) {
		int now = 0;
		for (int i = 0; i < tmp.size(); i++)
			now += tmp[i] - '0';
		cnt++;
		tmp = to_string(now);
	}
	cout << cnt << '\n';
	stoi(tmp) % 3 == 0 ? cout << "YES" : cout << "NO";
	return 0;
}
