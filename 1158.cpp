#include <bits/stdc++.h>
using namespace std;
int main() {
	int N, K; cin >> N >> K;
	int idx = K-1;
	vector<int> vect;
	for (int i = 1; i <= N; i++)
		vect.push_back(i);
	string ans = "";
	ans += "<";
	while (!vect.empty()) {
		ans += to_string(vect[idx]);
		ans += ", ";
		vect.erase(vect.begin() + idx);
		if(!vect.empty())
			idx = (idx - 1 + K) % vect.size();
	}
	ans = ans.substr(0, ans.size() - 2);
	ans += ">";
	cout << ans;
	return 0;
}

