#include <bits/stdc++.h>
using namespace std;
int main() {
	map<string, int> m;
	m["c="] = 1, m["c-"] = 1, m["dz="] = 1;
	m["d-"] = 1, m["lj"] = 1, m["nj"] = 1;
	m["s="] = 1, m["z="] = 1;
	int ans = 0;
	string s; cin >> s;
	for (int i = 0; i < s.size(); i++) {
		string tmp = "";
		if (i == s.size() - 1) {
			ans++; 
			break;
		}
		tmp += s[i];
		tmp += s[i + 1];
		if (m.find(tmp) != m.end()) {
			ans++;
			i++;
		}
		else {
			if (i == s.size() - 1) {
				ans += 2;
				break;
			}
			tmp += s[i + 2];
			if (m.find(tmp) != m.end()) {
				ans++;
				i += 2;
			}
			else {
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}