#include <iostream>
#define max(a,b) (a>b?a:b)
using namespace std;

int dp[301] = { 0, };
int stair[301] = { 0, };
int check[301] = { 0, };

int dynamic(int cnt) {
	for (int i = 0; i <= cnt-3; i++) {
		if (check[i + 2] == 0) {
			dp[i + 3] = max(stair[i + 3] + dp[i + 2], stair[i + 3] + dp[i + 1]);
			if (dp[i + 3] == stair[i + 3] + dp[i + 2]) check[i + 3] = 1;
		}
		if (check[i + 2] == 1) {
			dp[i + 3] = max(stair[i + 3] + stair[i + 2] + dp[i], stair[i + 3] + dp[i + 1]);
			if (dp[i + 3] == stair[i + 3] + stair[i + 2] + dp[i]) check[i + 3] = 1;
		}
	}
	return dp[cnt];
}

int main() {
	int tmp,num; cin >> num;
	for (int i = 1; i <= num; i++) {
		cin >> tmp;
		stair[i] = tmp;
	}
	dp[0] = 0; dp[1] = stair[1];
	dp[2] = stair[1] + stair[2];
	check[1] = 0; check[2] = 1; check[3] = 0;
	cout << dynamic(num);
	return 0;
}

