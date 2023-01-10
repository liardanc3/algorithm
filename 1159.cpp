#include <bits/stdc++.h>
using namespace std;
int cnt[200]{ 0, };
int main() {
	int N; string str;
	cin >> N;
	while (N--) {
		cin >> str;
		char now = str[0];
		cnt[now]++;
	}
	string ans = "";
	for (int i = 97; i <= 122; i++) {
		if (cnt[i] >= 5) ans += (char)i;
	}
	if (ans == "")
		cout << "PREDAJA";
	else cout << ans;
	return 0;
}