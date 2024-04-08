#include <bits/stdc++.h>
using namespace std;

int t, N, arr[1001], c, visited[1001];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> t;
	while (t--) {
		c = 0;
		memset(visited, 0, sizeof(visited));
		cin >> N;
		for (int i = 1; i <= N; i++) 
			cin >> arr[i];
		for (int i = 1; i <= N; i++) {
			if (!visited[i]) {
				visited[i] = 1;
				int now = i;
				int next = arr[i];
				while (now != next) {
					visited[next] = 1;
					next = arr[next];
				}
				c++;
			}
		}
		cout << c << '\n';
	}


	return 0;
}
