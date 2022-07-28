#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii>> pq;

int N, L, tmp;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        pq.push({ tmp,i });
        while (pq.top().second <= i - L)
            pq.pop();
        cout << pq.top().first << ' ';
    }
    return 0;
}