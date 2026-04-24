#include <bits/stdc++.h>
using namespace std;
int N, arr[21][21], visited[21]{ 0, }, mn = 1e9;
vector<int> vect;
void bt(int start) {
	if (vect.size() != 0) {
		int group[21]{ 0, };
		for (int unit : vect)
			group[unit] = 1;
		vector<int> v1, v2;
		for (int i = 1; i <= N; i++) {
			if (group[i]) v1.push_back(i);
			else v2.push_back(i);
		}
		int team1 = 0, team2 = 0;
		for (int i = 0; i < v1.size()-1; i++) {
			for (int j = i + 1; j < v1.size(); j++) 
				team1 += arr[v1[i]][v1[j]] + arr[v1[j]][v1[i]];
		}
		for (int i = 0; i < v2.size() - 1; i++) {
			for (int j = i + 1; j < v2.size(); j++)
				team2 += arr[v2[i]][v2[j]] + arr[v2[j]][v2[i]];
		}
		mn = min(mn, abs(team1 - team2));
	}
	if (vect.size() + 1 != N) {
		for (int i = start; i <= N; i++) {
			if (visited[i]) continue;
			visited[i] = 1;
			vect.push_back(i);
			bt(i + 1);
			vect.erase(vect.begin() + vect.size() - 1);
			visited[i] = 0;
		}
	}
	return;
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) {
		cin >> arr[i][j];
	}
	bt(1);
	cout << mn;
	return 0;
}