#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while (t--) {
        int h, w, n;
        cin >> h >> w >> n;
        int cnt = 0;
        for (int ww = 1; ww <= w; ww++) {
            for (int hh = 1; hh <= h; hh++) {
                cnt++;
                if (cnt == n) {
                    cout << hh;
                    if (ww < 10) cout << '0';
                    cout << ww << '\n';
                }
            }
        }
    }
    return 0;
}