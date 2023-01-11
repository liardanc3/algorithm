#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int r, c, k, yy1, x1, yy2, x2, visited[101][101], arr[101][101];
int dy[]{ -1,0,0,1 }, dx[]{ 0,-1,1,0 };
vector<int> vect;
void bfs(int i, int j) {
    visited[i][j] = 1;
    queue<pii> q;
    q.push({ i,j });
    int cnt = 1;
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int s = 0; s < 4; s++) {
            int ddy = y + dy[s];
            int ddx = x + dx[s];

            if (0 <= ddy && ddy < r && 0 <= ddx && ddx < c && !visited[ddy][ddx] && !arr[ddy][ddx]) {
                visited[ddy][ddx] = 1;
                q.push({ ddy,ddx });
                cnt++;
            }
        }
    }
    vect.push_back(cnt);
}
void init() {
    cin >> c >> r >> k;
    while (k--) {
        cin >> yy1 >> x1 >> yy2 >> x2;
        for (int i = yy1; i < yy2; i++) {
            for (int j = x1; j < x2; j++) {
                arr[i][j] = 1;
            }
        }
    }
}
int main() {
    init();
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (!visited[i][j] && !arr[i][j])
                bfs(i, j);
        }
    }
    cout << vect.size() << '\n';
    sort(vect.begin(), vect.end());
    for (int i : vect)
        cout << i << ' ';
}