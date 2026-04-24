#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<string> vect;
int n, k;
void dfs(int sum, string now) {
	if (sum >= n) {
		if(sum==n) 
			vect.push_back(now);
		return;
	}
	dfs(sum+1, now + "+1");
	dfs(sum+2, now + "+2");
	dfs(sum+3, now + "+3");
}
int main() {
	cin >> n >> k;
	dfs(0, "");
	if (vect.size() < k) cout << -1;
	else cout << vect[k-1].substr(1, vect[k-1].size());
	return 0;
}