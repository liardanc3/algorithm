#include <bits/stdc++.h>
using namespace std;
int n, arr[21][21], mn = 1e9, visited[21]{ 0, };
vector<int> team(21);
void bt(int start, int now) {
	if(now-1 == n / 2) {
		int ck[21]{ 0, };
		for (int i = 1; i <= now; i++)
			ck[team[i]] = 1;
		int team1 = 0, team2 = 0;
		vector<int> v1, v2;
		for (int i = 1; i <= n; i++) {
			if (ck[i])
				v1.push_back(i);
			else v2.push_back(i);
		}
		for (int i = 0; i < v1.size()-1; i++) {
			for (int j = i + 1; j < v1.size(); j++) 
				team1 += arr[v1[i]][v1[j]] + arr[v1[j]][v1[i]];
		}
		for (int i = 0; i < v2.size() - 1; i++) {
			for (int j = i + 1; j < v2.size(); j++)
				team2 += arr[v2[i]][v2[j]] + arr[v2[j]][v2[i]];
		}
		mn = min(mn, abs(team1 - team2));
		return;
	}
	for (int i = start; i <= n; i++) {
		if (visited[i]) continue;
		visited[i] = 1;
		team[now++] = i;
		bt(i + 1, now);
		now--;
		visited[i] = 0;
	}
	return;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
		cin >> arr[i][j];
	}
	bt(1, 1);
	cout << mn;
	return 0;
}