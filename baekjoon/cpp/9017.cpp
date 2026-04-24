#include <bits/stdc++.h>
using namespace std;

vector<int> vect;
int T, N, player[201], tmp, point[201], top4[201], player5[201], mn, tn, ans;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> T;
    while (T--) {
        vect.clear();
        memset(player, 0, sizeof player);
        memset(point, 0, sizeof point);
        memset(top4, 0, sizeof top4);
        memset(player5, 0, sizeof player5);
        mn = 1e9, tn = 0, ans = 0;

        cin >> N;
        while (N--) {
            cin >> tmp;
            vect.push_back(tmp);
            player[tmp]++;
            tn = max(tn, tmp);
        }

        for (int i = 0, r = 1; i < vect.size(); i++) {
            int now = vect[i];
            if (player[now] >= 6) {
                if (top4[now] < 4) {
                    top4[now]++;
                    point[now] += r;
                }
                else if(top4[now] == 4 && !player5[now])
                    player5[now] = r;
                r++;
            }
        }

        for (int i = 1; i <= tn; i++) {
            if (point[i] && point[i] < mn) {
                ans = i;
                mn = point[i];
            }
            else if (point[i] && point[i] == mn) {
                if (player5[i] < player5[ans])
                    ans = i;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}