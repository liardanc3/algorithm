#include <bits/stdc++.h>
using namespace std;
int N, K, visited[123]{ 0, }, mx = 0;
vector<string> vect;
void bt(int start, int now) {
	if (now == K) {
		int cnt = 0;
		for (int i = 0; i < vect.size(); i++) {
			string str = vect[i];
			for (int j = 0; j < str.size(); j++) {
				char chr = str[j];
				if (!visited[chr]) break;
				if (j == str.size() - 1) cnt++;
			}
		}
		mx = max(mx, cnt);
		return;
	}
	for (int i = start; i <= 122; i++) {
		if (visited[i]) continue;

		visited[i] = 1;
		bt(i + 1, now + 1);
		visited[i] = 0;
	}
	return;
}
int main() {
	string tmp;
	visited[97] = 1, visited[110] = 1;
	visited[116] = 1, visited[105] = 1, visited[99] = 1;
	cin >> N >> K;
	while (N--) {
		cin >> tmp;
		vect.push_back(tmp);
	}
	if (K < 5) 
		cout << 0;
	else {
		bt(98, 5);
		cout << mx;
	}
	return 0;
}