#include <iostream>
using namespace std;
int* dp,* ck;

int dynamic(int n) {
	if (ck[n] == 1)
		return dp[n];
	else {
		dp[n] = dynamic(n-1) + dynamic(n-2);
		dp[n]%= 10007;
		ck[n] = 1;
	}
	return dp[n];
}

int main() {
	int n; cin >> n;
	dp = new int[n + 1]{ 0, };
	ck = new int[n + 1]{ 0, };
	dp[0] = 0; ck[0] = 1;
	dp[1] = 1; ck[1] = 1;
	if (n > 1) { dp[2] = 2; ck[2] = 1; }
	cout << dynamic(n);
	return 0;
}