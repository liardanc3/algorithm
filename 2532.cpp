#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef pair<int, int> pii;
int N, n, L, R, cnt = 0;
vector<pii> vect;
vector<int> master;
map<pii, int> m;
bool cmp(const pii& v1, const pii& v2) {
    if (v1.second != v2.second)
        return v1.second < v2.second;
    return v1.first < v2.first;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> n >> L >> R;
        if (m.find({ 1e9 - L, R }) != m.end()) continue;
        vect.push_back({ 1e9 - L,R });
        m[{1e9 - L, R}] = 1;
    }
    sort(vect.begin(), vect.end(), cmp);
    for (int i = 0; i < vect.size(); i++) {
        if (!master.size() || master[master.size() - 1] <= vect[i].first)
            master.push_back(vect[i].first);
        else {
            int idx;
            int idx = lower_bound(master.begin(), master.end(), vect[i].first) - master.begin();
            int origin = master[idx];
            if (origin == vect[i].first)
                idx = upper_bound(master.begin(), master.end(), origin) - master.begin();
            master[idx] = vect[i].first;
        }
    }
    cout << master.size() + cnt;
    return 0;
}