#include <bits/stdc++.h>
#define int long long
using namespace std;

string tmp, ans;
int C, N, Q, p[4001];
unordered_set<int> color, name;
signed main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		p[0] = 1;
		for (int i = 1; i <= 4000; i++) {
			p[i] = p[i - 1] * 27;
		}
		cin >> C >> N;
		for (int i = 0; i < C; i++) {
			cin >> tmp;
			int hash = 0;
			for (int j = 0; j < tmp.size(); j++)
				hash = hash + p[j] * (tmp[j] - '0' + 1);
			color.insert(hash);
		}
		for (int i = 0; i < N; i++) {
			cin >> tmp;
			reverse(tmp.begin(), tmp.end());
			int hash = 0;
			for (int j = 0; j < tmp.size(); j++)
				hash = hash + p[j] * (tmp[j] - '0' + 1);
			name.insert(hash);
		}
	}();
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		cin >> tmp;
		int hash1 = 0, hash2 = 0, flag = 0;
		for (int j = 0; j < tmp.size(); j++)
			hash1 += p[j] * (tmp[j] - '0' + 1);
		
		for (int j = 0; j < tmp.size() && !flag; j++) {
			hash1 -= p[tmp.size()-1-j] * (tmp[tmp.size() - 1 - j] - '0' + 1);
			hash2 += p[j] * (tmp[tmp.size() - 1 - j] - '0' + 1);
			
			if (color.find(hash1) != color.end() && name.find(hash2) != name.end())
				flag = 1;
		}
		flag ? cout << "Yes\n" : cout << "No\n";
	}
	return 0;
}