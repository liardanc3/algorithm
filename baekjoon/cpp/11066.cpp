#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, k, dp[501][501], sum[501];
int dynamic(int L, int R) {
    if (dp[L][R] < 1e16) return dp[L][R];
    for (int i = L; i < R; i++) {
        int target = dynamic(L, i) + dynamic(i + 1, R) + sum[R] - sum[L - 1];
        if (target < dp[L][R]) {
            dp[L][R] = target;
        }
    }
    return dp[L][R];
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        fill(&dp[0][0], &dp[500][501], 1e16);
        cin >> k;
        for (int i = 1; i <= k; i++) {
            cin >> dp[i][i];
            sum[i] = sum[i - 1] + dp[i][i];
        }
        cout << dynamic(1, k) - sum[k] << '\n';
    }
    return 0;
}