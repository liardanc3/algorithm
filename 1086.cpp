#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

vector<string> str;
vector<int> vect;
string tmp;
int N, K, dp[100][1<<16], ans[100][1<<16], sz, digit;
int dynamic(int now, int len, int visited) {
	int needk = -1;
	for (int i = 0; i < K && needk == -1; i++) {
		if ((now + i) % K == 0)
			needk = i;
	}

	if (dp[needk][visited] != -1)
		return dp[needk][visited];

	int cnt = sz - len;
	for (int i = 1; i <= cnt; i++) {
		now *= (10 % K);
		now %= K;
	}

}

int main() {
	fill(&dp[0][0], &dp[15][1 << 16], -1);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		str.push_back(tmp);
		sz += tmp.size();
	}
	cin >> K;
	cout << dynamic()
	return 0;
}