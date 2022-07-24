#include <bits/stdc++.h>
#include <assert.h>
#include <fstream>
#include <time.h>
#define int long long
using namespace std;

typedef pair<int, int> pii;

int N, M, pi, qi, t, dp[19][1 << 19];
int buy[100001], sell[100001], w[100001], ck[19], dist[19][19];
int buys[100001][19], sells[100001][19], goods[100001];

vector<int> out[100001], in[19], send[19][19];
vector<pii> vect[19];

int TSP(int now, int visited, int depth) {
	if (dp[now][visited] != -1)
		return dp[now][visited];
	
	int origin[100001];
	copy(goods, goods + M+1, origin);

	dp[now][visited] = 0;
	for (int i = 0; i < depth - 1; i++) {
		for (int j = 0; j < send[ck[i]][now].size(); j++) {
			int product = send[ck[i]][now][j];
			if (goods[product]) {
				dp[now][visited] += w[product] * goods[product];
				goods[product] = 0;
			}
		}
	}
	
	if ((visited == (1 << (N + 1)) - 2)) {
		copy(origin, origin + M + 1, goods);
		return dp[now][visited];
	}
	
	for (int i = 0; i < in[now].size(); i++) 
		goods[in[now][i]]++;

	int sum = 0;
	for (int i = 1; i <= N; i++) {
		if (!(visited & 1 << i)) {
			int flag = 0 + (now == 0) * 1;
			for (int j = 0; j < depth && !flag; j++) {
				int num = ck[j];
				for (int k = 0; k < in[num].size() && flag; k++) {
					if (goods[in[num][k]])
						flag = 1;
				}
			}
			if (flag) {
				ck[depth] = i;
				sum = max(sum, TSP(i, visited + (1 << i), depth + 1));
			}
		}
	}

	dp[now][visited] += sum;
	copy(origin, origin + M + 1, goods);
	return dp[now][visited];
}

signed main() {
	clock_t start, end;
	[&]() {
		start = clock();
		ifstream cin;
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin.open("b.txt");
		memset(dp, -1, sizeof(dp));
		cin >> N >> M;
		assert(N < 18 || M < 100000);
		for (int i = 1; i <= M; i++)
			cin >> buy[i];
		for (int i = 1; i <= M; i++) {
			cin >> sell[i];
			w[i] = sell[i] - buy[i];
		}
		for (int i = 1; i <= N; i++) {
			cin >> pi;
			for (int j = 1; j <= pi; j++) {
				cin >> t;
				in[i].push_back(t);
				sells[i][t] = 1;
			}
			cin >> qi;
			for (int j = 1; j <= qi; j++) {
				cin >> t;
				out[t].push_back(i);
				buys[i][t] = 1;
			}
		}
	}();
	end = clock();
	cout << "입력 : " << (double)(end - start) << "ms\n";

	[&]() {
		for (int i = 1; i <= N; i++) {
			int start = i;
			for (int j = 0; j < in[i].size(); j++) {
				int product = in[i][j];
				for (int k = 0; k < out[product].size(); k++) {
					int end = out[product][k];
					dist[start][end] += w[product];
					send[start][end].push_back(product);
				}
			}
		}
	}();
	end = clock();
	cout << "간선추가 : " << (double)(end - start) << "ms\n";

	cout << TSP(0, 0, 0);
	cout << '\n' << (double)(end - start) << "ms\n";
	return 0;
}