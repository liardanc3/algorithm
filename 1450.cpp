#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> vect, vect1, vect2;
int N, C, tmp, sum, ans;

void f1(int left, int right, int sum) {
    for (int i = left+1; i <= right; i++) {
        vect1.push_back(sum + vect[i]);
        f1(i, right, sum + vect[i]);
    }
}
void f2(int left, int right, int sum) {
    for (int i = left + 1; i <= right; i++) {
        vect2.push_back(sum + vect[i]);
        f2(i, right, sum + vect[i]);
    }
}
signed main() {
    [&]() {
        cin >> N >> C;
        for (int i = 0; i < N; i++) {
            cin >> tmp;
            if (tmp > C)
                continue;
            vect.push_back(tmp);
            sum += tmp;
        }
        N = vect.size();
    }();
    if (!N)
        cout << 1;
    else if (sum <= C)
        cout << (int)pow(2, N);
    else {
        f1(-1, (N - 1) / 2, 0);
        vect1.push_back(0);
        f2((N - 1) / 2, N - 1, 0);
        vect2.push_back(0);
        sort(vect2.begin(), vect2.end());
        for (int left : vect1) {
            int right = C - left;
            int idx = upper_bound(vect2.begin(), vect2.end(), right) - vect2.begin();
            ans += idx;
        }
        cout << ans;
    }
    return 0;
}