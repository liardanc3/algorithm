#include <bits/stdc++.h>
#include <assert.h>
using namespace std;

set<int> visited;
string ret = "";
int t, n, m, tmp;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n;
		while (n--) {
			cin >> tmp;
			visited.insert(tmp);
		}
		cin >> m;
		while (m--) {
			cin >> tmp;
			if (visited.find(tmp) != visited.end())
				ret+="1\n";
			else
				ret+="0\n";
		}
		visited.clear();
	}
	cout << ret;
	return 0;
}
