#include <bits/stdc++.h>
using namespace std;
queue<int> Q;
int A, B;
int bfs(int s) {
	int cnt = 0;
	while (!Q.empty()) {
		cnt++;
		int size = Q.size();
		for (int i = 0; i < size; i++) {
			int tmp = Q.front(); Q.pop();
			if (tmp == B) return cnt;
			else {
				if (tmp <= 214748364 && tmp * 10 + 1 <= B)
					Q.push(tmp * 10 + 1);
				if (tmp * 2 <= 1073741823 && tmp * 2 <= B)
					Q.push(tmp * 2);
			}
		}
	}
	return -1;
}
int main() { 
	cin >> A >> B;
	Q.push(A);
	cout << bfs(A);
	return 0;
}