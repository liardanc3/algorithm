#include <bits/stdc++.h>
using namespace std;
typedef pair<int, string> pis;
int N, age;
string name;
queue<string> q[201];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	while (N--) {
		cin >> age >> name;
		q[age].push(name);
	}
	for (int i = 1; i <= 200; i++) {
		while (!q[i].empty()) {
			cout << i << ' ' << q[i].front() << '\n';
			q[i].pop();
		}
	}
	return 0;
}