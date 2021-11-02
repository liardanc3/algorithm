#include <bits/stdc++.h>
#define MIN -2e18
#define MAX 2e18
using namespace std;
typedef pair<int, int> pii;
int N, src, dst, M, from, to, w, pay[50];
long long d[50];
vector<pii> vect[50];
int main() {
	fill(&d[0], &d[50], MIN);
	cin >> N >> src >> dst >> M;
	for (int i = 0; i < M; i++) {
		cin >> from >> to >> w;
		vect[from].push_back({ to,w });
	}
	for (int i = 0; i < N; i++)
		cin >> pay[i];
	d[src] = pay[src];
	int range = 2 * N - 2;
	if (range < 1) range = 1;
	for (int i = 1; i <= range; i++) {
		for (int j = 0; j < N; j++) {
			if (d[j] == MIN) continue;
			for (int k = 0; k < vect[j].size(); k++) {
				int next = vect[j][k].first;
				int dist = -vect[j][k].second + pay[next];
			
				if (d[next] < 0LL + d[j] + dist) {
					d[next] = 0LL + d[j] + dist;

					if (i >= N)
						d[next] = MAX;
				}
			}
		}
	}
	if (d[dst] == MAX)
		cout << "Gee";
	else if (d[dst] == MIN)
		cout << "gg";
	else cout << d[dst];
	return 0;
}