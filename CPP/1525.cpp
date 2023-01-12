#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> tii;
typedef pair<int, int> pii;
int dx[]{ -3,-1,1,3 };
map<string, int> ck;
int main() {
	string str = ""; char tmp;
	int ans = -1;
	for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) {
		cin >> tmp;
		str += tmp;
	}
	queue<string> q;
	q.push(str);
	while (!q.empty()) {
		ans++;
		int size = q.size();
		for (int i = 0; i < size; i++) {
			string now = q.front(); q.pop();
			if (now == "123456780") {
				cout << ans;
				return 0;
			}
			int x = -1;
			for (int j = 0; j < 9 && x == -1; j++) {
				if (now[j] == '0')
					x = j;
			}
			for (int j = 0; j < 4; j++) {
				
				int ddx = x + dx[j];
				
				if (j == 1 && (x == 0 || x == 3 || x == 6)) continue;
				if (j == 2 && (x == 2 || x == 5 || x == 8)) continue;

				if (0 <= ddx && ddx<=8) {

					string next = now;
					swap(next[x], next[ddx]);
					
					if (ck.find(next) != ck.end()) continue;

					ck.insert(pair<string, int>(next, 1));
					q.push(next);
				}
			}
		}
	}
	cout << -1;
	return 0;
}