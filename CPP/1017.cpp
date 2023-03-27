#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
vector<pii> backup;

struct node {
	int next, capacity, revidx;
	node(int n, int c, int r) {
		next = n, capacity = c, revidx = r;
	}
}; vector<node> vect[2003], origin[2003];

void addedge(int s, int e, int c) {
	vect[s].push_back({ e,c,(int)vect[e].size() });
	vect[e].push_back({ s,0,(int)vect[s].size() - 1 });
}

vector<int> input, ans;
int n, tmp, prime[2001], level[2003], idx[2003], mx, removed[2003], match[2003];
int bfs() {
	memset(level, -1, sizeof level); level[0] = 1;
	queue<int> q; q.push(0);
	while (!q.empty()) {
		int now = q.front(); q.pop();

		for (node n : vect[now]) {
			int next = n.next;
			int capacity = n.capacity;

			if (level[next] == -1 && capacity > 0) {
				bool cond1 = now == 0 && next % 2 == 0;
				bool cond2 = now % 2 == 0 && next % 2 == 1;
				bool cond3 = now % 2 == 1 && next == 2002;
				
				if (cond1 || cond2 || cond3) {
					level[next] = level[now] + 1;
					q.push(next);
				}
			}
		}
	}
	return level[2002] == -1 ? 0 : 1;
}
int dfs(int now, int wat) {
	if (now == 2002) {
		cout << now;
		return wat;
	}
	for (int& i = idx[now]; i < vect[now].size(); i++) {
		int next = vect[now][i].next;
		int& capacity = vect[now][i].capacity;
		int& rcapacity = vect[next][vect[now][i].revidx].capacity;

		if (level[now] + 1 == level[next] && capacity > 0) {
			int blockflow = dfs(next, min(wat, capacity));

			if (blockflow > 0) {
				//match[now/2] = 1;
				capacity -= blockflow;
				rcapacity += blockflow;
				cout << " -> " << now/2;
				return blockflow;
			}
		}
	}
	return 0;
}
int main() {
	[&]() {
		fill(&prime[2], &prime[2001], 1);
		for (int i = 2; i * i <= 2000; i++) {
			if (!prime[i])
				continue;
			for (int j = 2 * i; j <= 2000; j += i)
				prime[j] = 0;
		}
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			input.push_back(tmp);
		}
		for (int i = 0; i < input.size() - 1; i++) {
			int src = input[i];
			int cnt = 0;
			addedge(0, 2 * src, 1);
			for (int j = i + 1; j < input.size(); j++) {
				int dst = input[j];
				addedge(2 * dst + 1, 2002, 1);
				if (prime[src + dst])
					addedge(2 * src, 2 * dst + 1, 1);
			}
		}
		for (int i = 0; i <= 2002; i++) {
			if (vect[i].empty())
				continue;
			origin[i].assign(vect[i].size(), { 0,0,0 });
			copy(vect[i].begin(), vect[i].end(), origin[i].begin());
		}
	}();
		
	bfs();
	memset(idx, 0, sizeof(idx));
	while (1) {
		int flow = dfs(0, 1e9);
		cout << '\n';
		if (!flow)
			break;
		mx += flow;
	}
	
	if (mx != n/2)
		cout << -1;
	else {
		[&]() {
			while (mx == n/2) {
				memset(match, 0, sizeof match);
				for (node n : vect[input[0]*2]) {
					int next = n.next;
					int capacity = n.capacity;

					if (next != 0 && capacity == 0) {
						removed[next] = 1;
					}
				}
				[&]() {
					for (int i = 0; i <= 2002; i++)
						copy(origin[i].begin(), origin[i].end(), vect[i].begin());
				}();
				
				mx = 0;
				for (int i = 0; i < vect[input[0] * 2].size(); i++) {
					int next = vect[input[0]*2][i].next;
					int& capacity = vect[input[0] * 2][i].capacity;

					if (removed[next]) 
						capacity = 0;
				}
				bfs();
				memset(idx, 0, sizeof(idx));
				while (1) {
					int flow = dfs(0, 1e9);
					cout << '\n';
					if (!flow)
						break;
					mx += flow;
				}
			}
		}();
		
		for (int i = 0; i <= 2001; i++) {
			if (removed[i])
				cout << i / 2 << ' ';
		}
	}
	return 0;
}