#include <bits/stdc++.h>
using namespace std;

int N, M, arr[22][22], visited[22][22], mx, tmp, flag;
int dy[]{ -1,0,0,1 }, dx[]{ 0,-1,1,0 };
void dfs(int y, int x) {
    if (arr[y][x] == 0) {
        flag = 1;
        return;
    }
        
    visited[y][x] = 1;
    tmp++;
    for (int i = 0; i < 4; i++) {
        int ddy = y + dy[i];
        int ddx = x + dx[i];
        if (arr[ddy][ddx] == 1)
            continue;

        if (1 <= ddy && ddy <= N && 1 <= ddx && ddx <= M && !visited[ddy][ddx]) 
            dfs(ddy, ddx);
    }
}
int main(){
    [&]() {
        ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
        cin >> N >> M;
        for (int i = 1; i <= N; i++) for (int j = 1; j <= M; j++)
            cin >> arr[i][j];
        for (int i = 0; i <= N + 1; i++) {
            if (i == 0 || i == N + 1) {
                for (int j = 0; j <= M + 1; j++)
                    arr[i][j] = 1;
            }
            else
                arr[i][0] = 1, arr[i][M + 1] = 1;
        }
    }();
   

    for (int y1 = 1; y1 <= N; y1++) {
        for (int x1 = 1; x1 <= M; x1++) {
            if (arr[y1][x1] != 0)
                continue;

            arr[y1][x1] = 1;
            for (int y2 = 1; y2 <= N; y2++) {
                for (int x2 = 1; x2 <= M; x2++) {
                    if (arr[y2][x2] != 0 || (y1 == y2 && x1 == x2))
                        continue;

                    arr[y2][x2] = 1;

                    memset(visited, 0, sizeof(visited));
                    int ttmp = 0;
                    for (int i = 1; i <= N; i++) {
                        for (int j = 1; j <= M; j++) {
                            if (arr[i][j] == 2 && !visited[i][j]) {
                                flag = 0;
                                tmp = 0;
                                dfs(i, j);
                                if (!flag) {
                                    ttmp += tmp;
                                }
                            }
                        }
                    }
                    mx = max(mx, ttmp);

                    arr[y2][x2] = 0;
                }
            }
            arr[y1][x1] = 0;
        }
    }

    cout << mx;
    return 0;
}