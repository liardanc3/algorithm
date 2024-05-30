#include <bits/stdc++.h>
using namespace std;

string tmp;
int N, origin[26], ck[26], cnt, sz, ret;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N >> tmp;
	sz = tmp.size(); N--;
	for (char ch : tmp)
		origin[ch - 'A']++;
	while (N--) {
		cin >> tmp;
		if (tmp.size() - 1 <= sz && sz <= tmp.size() + 1) {
			cnt = 0;
			memset(ck, 0, sizeof(ck));
			for (char ch : tmp)
				ck[ch - 'A']++;
			for (int i = 0; i < 26; i++)
				cnt += abs(ck[i] - origin[i]);
			if (cnt <= 2) {
				ret++;
				cout << tmp << '\n';
			}
		}	
	}
	cout << ret;
	return 0;
}