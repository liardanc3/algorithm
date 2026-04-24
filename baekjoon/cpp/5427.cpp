#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
queue<pii> fire;
int t, r, c, sy, sx, visited[1001][1001];
char arr[1001][1001];
int dy[]{ -1,0,0,1 }, dx[]{ 0,-1,1,0 };
void bfs() {
    visited[sy][sx] = 1;
    queue<pii> q;
    q.push({ sy,sx });
    int cnt = 0;
    while (!q.empty()) {
        cnt++;
        int size = q.size();
        for (int s = 0; s < size; s++) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int ddy = y + dy[i];
                int ddx = x + dx[i];

                if (ddy<1 || ddy>r || ddx<1 || ddx>c) {
                    cout << cnt << '\n';
                    return;
                }

                if (arr[ddy][ddx] == '#') continue;
                if (arr[ddy + 1][ddx] == '*') continue;
                if (arr[ddy - 1][ddx] == '*') continue;
                if (arr[ddy][ddx + 1] == '*') continue;
                if (arr[ddy][ddx - 1] == '*') continue;

                if (visited[ddy][ddx]) continue;

                q.push({ ddy ,ddx });
                visited[ddy][ddx] = 1;
            }
        }
        int sz = fire.size();
        while (sz--) {
            int y = fire.front().first;
            int x = fire.front().second;
            fire.pop();

            for (int k = 0; k < 4; k++) {
                int ddy = y + dy[k];
                int ddx = x + dx[k];

                if (1 <= ddy && ddy <= r && 1 <= ddx && ddx <= c && !visited[ddy][ddx] &&
                    arr[ddy][ddx] != '#') {
                    arr[ddy][ddx] = '*';
                    visited[ddy][ddx] = 1;
                    fire.push({ ddy,ddx });
                }
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return;
}
int main() {
    cin >> t;
    while (t--) {
        while (!fire.empty())
            fire.pop();
        memset(visited, 0, sizeof(visited));
        fill(&arr[0][0], &arr[1000][1001], '\0');
        cin >> c >> r;
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                cin >> arr[i][j];
                if (arr[i][j] == '*') {
                    fire.push({ i,j });
                    visited[i][j] = 1;
                }
                if (arr[i][j] == '@')
                    sy = i, sx = j;
            }
        }
        bfs();
    }

    return 0;
}