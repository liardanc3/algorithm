#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

vector<int> vect, tubeidx[100001], edge[1000];
map<int,int> __start, __end;
int N, K, M, tmp, visited[1000][1000], ck[1000];
int main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> N >> K >> M;
		for (int i = 0; i < M; i++) {
			vect.clear();
			
			for (int j = 0; j < K; j++) {
				cin >> tmp;
				if (tmp == 1) __start[i] = 1;
				if (tmp == N) __end[i] = 1;
				
				vect.push_back(tmp);
				if (!tubeidx[tmp].empty()) {
					for (int k = 0; k < (int)tubeidx[tmp].size(); k++) {
						if (!visited[i][tubeidx[tmp][k]]) {
							edge[i].push_back(tubeidx[tmp][k]);
							visited[i][tubeidx[tmp][k]] = 1;
						}
						if (!visited[tubeidx[tmp][k]][i]) {
							edge[tubeidx[tmp][k]].push_back(i);
							visited[tubeidx[tmp][k]][i] = 1;
						}
					}
				}
				tubeidx[tmp].push_back(i);
			}
		}
	}();
	if (N == 1) {
		cout << 1;
		return 0;
	}
	[&]() {
		queue<int> q;
		for (int i = 0; i < M; i++) {
			if (__start[i] == 1) {
				q.push(i);
				ck[i] = 1;
			}
		}
		int cnt = 0;
		while (!q.empty()) {
			cnt++;
			int sz = q.size();
			while (sz--) {
				int now = q.front();

				q.pop();
				if (__end[now]==1) {
					cout << cnt+1;
					return;
				}
				for (int i = 0; i < (int)edge[now].size(); i++) {
					int next = edge[now][i];

					if (!ck[next]) {
						ck[next] = 1;
						q.push(next);
					}
				}
			}
		}
		cout << -1;
		return;
	}();
	return 0;
}