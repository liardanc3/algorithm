#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, ans = 0; cin >> n;
	string tmp;
	int visited[100]{ 0, };
	while (n--) {
		cin >> tmp;
		for (int i = 0; i < tmp.size(); i++) {
			if (visited[tmp[i] - '0'] == 1 && i > 0 && tmp[i] != tmp[i - 1])
				break;
			visited[tmp[i]-'0'] = 1;
			if (i == tmp.size() - 1)
				ans++;
		}
		memset(visited, 0, sizeof(visited));
	}
	cout << ans;
	return 0;
}