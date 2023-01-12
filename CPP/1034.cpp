#include <bits/stdc++.h>
using namespace std;
int N, M, K, mx = 0;
string arr[51];
map<string, int> m;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string tmp;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		m[arr[i]]++;
	} 
	cin >> K;
	for (int i = 1; i <= N; i++) {
		string now = arr[i];
		int cnt = 0;
		for (int j = 0; j < now.size(); j++) {
			if (now[j] == '0') cnt++;
		}
		if (cnt <= K && cnt % 2 == K % 2)
			mx = max(mx, m[now]);
	}
	cout << mx;
	return 0;
}