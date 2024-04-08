#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M;
	string S; string ans = "";
	string tmp; int tmp_index = -1;
	cin >> N >> M >> S;
	for (int i = 0; i < N; i++) {
		ans += "IO";
	} ans += "I";
	
	int count = 0, i; int index_count = 1;
	while (S.length() >= ans.length()) {
		i = 0;
		tmp_index = -1;
		tmp_index = S.find(ans);
		if (tmp_index == -1) {
			break;
		}
		count++;
		while (tmp_index+ans.length()+i+2<=S.length()) {
			if (S.substr(tmp_index + ans.length() + i, 2).compare("OI") == 0) {
				count++; i += 2;
			}
			else break;
		}
		if(S.compare("")!=0)
			S = S.substr(tmp_index + ans.length() + i, S.length() -tmp_index-ans.length()-i);
	}
	cout << count;
	return 0;
}