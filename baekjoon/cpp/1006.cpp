#include <bits/stdc++.h>
#define int long long
using namespace std;

int T, N, W, arr[2][10001], dp[10001][3], mn;
string ans = "";
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> T;
    while (T--) {
        [&]() {
            mn = 1e9;
            cin >> N >> W;
            for (int i = 0; i < 2; i++) for (int j = 1; j <= N; j++)
                cin >> arr[i][j];
        }();

        [&]() {
            fill(&dp[0][0], &dp[10000][3], 1e9);
            dp[0][0] = 0, dp[0][1] = 0, dp[0][2] = 0;
            dp[1][0] = (arr[0][1] + arr[1][1] <= W) ? 1 : 2;
            dp[1][1] = 1;
            dp[1][2] = 1;
            for (int i = 2; i <= N; i++) {
                dp[i][0] = min(dp[i][0], dp[i - 2][0] + ((arr[0][i - 1] + arr[0][i] <= W) && (arr[1][i - 1] + arr[1][i] <= W) ? 2 : 4));
                dp[i][0] = min(dp[i][0], dp[i - 1][0] + ((arr[0][i] + arr[1][i] <= W) ? 1 : 2));
                dp[i][0] = min(dp[i][0], dp[i - 1][1] + (((arr[0][i - 1] + arr[0][i] <= W) || (arr[0][i] + arr[1][i] <= W)) ? 2 : 3));
                dp[i][0] = min(dp[i][0], dp[i - 1][2] + (((arr[1][i - 1] + arr[1][i] <= W) || (arr[0][i] + arr[1][i] <= W)) ? 2 : 3));

                dp[i][1] = min(dp[i][1], dp[i - 1][0] + 1);
                dp[i][1] = min(dp[i][1], dp[i - 1][2] + ((arr[1][i - 1] + arr[1][i] <= W) ? 1 : 2));

                dp[i][2] = min(dp[i][2], dp[i - 1][0] + 1);
                dp[i][2] = min(dp[i][2], dp[i - 1][1] + ((arr[0][i - 1] + arr[0][i] <= W) ? 1 : 2));
            }
            mn = min(mn, dp[N][0]);
        }();

        if (N == 1) {
            cout << mn << '\n';
            continue;
        }

        if (arr[0][N] + arr[0][1] <= W) {
            [&]() {
                fill(&dp[0][0], &dp[10000][3], 1e9);
                dp[0][0] = 0, dp[0][1] = 0, dp[0][2] = 0;
                dp[1][0] = 2;
                dp[1][2] = 1;
                for (int i = 2; i <= N; i++) {
                    if (i != 2)
                        dp[i][0] = min(dp[i][0], dp[i - 2][0] + ((arr[0][i - 1] + arr[0][i] <= W) && (arr[1][i - 1] + arr[1][i] <= W) ? 2 : 4));
                    dp[i][0] = min(dp[i][0], dp[i - 1][0] + ((arr[0][i] + arr[1][i] <= W) ? 1 : 2));
                    dp[i][0] = min(dp[i][0], dp[i - 1][1] + (((arr[0][i - 1] + arr[0][i] <= W) || (arr[0][i] + arr[1][i] <= W)) ? 2 : 3));
                    dp[i][0] = min(dp[i][0], dp[i - 1][2] + (((arr[1][i - 1] + arr[1][i] <= W) || (arr[0][i] + arr[1][i] <= W)) ? 2 : 3));

                    dp[i][1] = min(dp[i][1], dp[i - 1][0] + 1);
                    dp[i][1] = min(dp[i][1], dp[i - 1][2] + ((arr[1][i - 1] + arr[1][i] <= W) ? 1 : 2));

                    dp[i][2] = min(dp[i][2], dp[i - 1][0] + 1);
                    dp[i][2] = min(dp[i][2], dp[i - 1][1] + ((arr[0][i - 1] + arr[0][i] <= W) ? 1 : 2));
                }
                mn = min(mn, dp[N][1]);
            }();
        }
        
        if (arr[1][N] + arr[1][1] <= W) {
            [&]() {
                fill(&dp[0][0], &dp[10000][3], 1e9);
                dp[0][0] = 0, dp[0][1] = 0, dp[0][2] = 0;
                dp[1][0] = 2;
                dp[1][1] = 1;
                for (int i = 2; i <= N; i++) {
                    if (i != 2)
                        dp[i][0] = min(dp[i][0], dp[i - 2][0] + ((arr[0][i - 1] + arr[0][i] <= W) && (arr[1][i - 1] + arr[1][i] <= W) ? 2 : 4));
                    dp[i][0] = min(dp[i][0], dp[i - 1][0] + ((arr[0][i] + arr[1][i] <= W) ? 1 : 2));
                    dp[i][0] = min(dp[i][0], dp[i - 1][1] + (((arr[0][i - 1] + arr[0][i] <= W) || (arr[0][i] + arr[1][i] <= W)) ? 2 : 3));
                    dp[i][0] = min(dp[i][0], dp[i - 1][2] + (((arr[1][i - 1] + arr[1][i] <= W) || (arr[0][i] + arr[1][i] <= W)) ? 2 : 3));

                    dp[i][1] = min(dp[i][1], dp[i - 1][0] + 1);
                    dp[i][1] = min(dp[i][1], dp[i - 1][2] + ((arr[1][i - 1] + arr[1][i] <= W) ? 1 : 2));

                    dp[i][2] = min(dp[i][2], dp[i - 1][0] + 1);
                    dp[i][2] = min(dp[i][2], dp[i - 1][1] + ((arr[0][i - 1] + arr[0][i] <= W) ? 1 : 2));
                }
                mn = min(mn, dp[N][2]);
            }();
        }

        if (arr[0][N] + arr[0][1] <= W && arr[1][N] + arr[1][1] <= W) {
            [&]() {
                fill(&dp[0][0], &dp[10000][3], 1e9);
                dp[0][0] = 0, dp[0][1] = 0, dp[0][2] = 0;
                dp[1][0] = 2;
                for (int i = 2; i <= N-1; i++) {
                    if (i != 2)
                        dp[i][0] = min(dp[i][0], dp[i - 2][0] + ((arr[0][i - 1] + arr[0][i] <= W) && (arr[1][i - 1] + arr[1][i] <= W) ? 2 : 4));
                    dp[i][0] = min(dp[i][0], dp[i - 1][0] + ((arr[0][i] + arr[1][i] <= W) ? 1 : 2));
                    dp[i][0] = min(dp[i][0], dp[i - 1][1] + (((arr[0][i - 1] + arr[0][i] <= W) || (arr[0][i] + arr[1][i] <= W)) ? 2 : 3));
                    dp[i][0] = min(dp[i][0], dp[i - 1][2] + (((arr[1][i - 1] + arr[1][i] <= W) || (arr[0][i] + arr[1][i] <= W)) ? 2 : 3));

                    dp[i][1] = min(dp[i][1], dp[i - 1][0] + 1);
                    dp[i][1] = min(dp[i][1], dp[i - 1][2] + ((arr[1][i - 1] + arr[1][i] <= W) ? 1 : 2));

                    dp[i][2] = min(dp[i][2], dp[i - 1][0] + 1);
                    dp[i][2] = min(dp[i][2], dp[i - 1][1] + ((arr[0][i - 1] + arr[0][i] <= W) ? 1 : 2));
                }
                mn = min(mn, dp[N-1][0]);
            }();
        }
        
        cout << mn << '\n';
    }
    return 0;
}