#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> ti;
queue<ti> q;
int arr[25][25]{ 0, };
int dp[25][25][4];
int dx[]{ 0,-1,1,0 };
int dy[]{ -1,0,0,1 };
int limit;
int bfs() {
    while (!q.empty()) {
        int size = q.size();
        for (int m = 0; m < size; m++) {
            int oy = get<0>(q.front());
            int ox = get<1>(q.front());
            int go2 = get<2>(q.front()); q.pop();
            for (int i = 0; i < 4; i++) {
                int y = oy + dy[i], x = ox + dx[i];
                if (y >= 0 && y < limit && x >= 0 && x < limit && arr[y][x] == 0) {
                    int tt = dp[y][x][i];
                    if (i == 0 || i == 3) {
                        if (go2 == 0 || go2 == 3 || go2 == -1) {
                            dp[y][x][i] = min(dp[y][x][i], dp[oy][ox][go2] + 100);
                        }
                        else dp[y][x][i] = min(dp[y][x][i], dp[oy][ox][go2] + 600);
                    }
                    else if (i == 1 || i == 2) {
                        if (go2 == 1 || go2 == 2 || go2 == -1) {
                            if (go2 == -1) 
                                dp[y][x][i] = min(dp[y][x][i], dp[oy][ox][0] + 100);
                            else 
                                dp[y][x][i] = min(dp[y][x][i], dp[oy][ox][go2] + 100);
                        }
                        else dp[y][x][i] = min(dp[y][x][i], dp[oy][ox][go2] + 600);
                    }
                    if(dp[y][x][i] < tt)
                        q.push(ti(y, x, i));
                }
            }
        }
    }
    return *min_element(&dp[limit-1][limit-1][0],&dp[limit-1][limit-1][4]);
}

int solution(vector<vector<int>> board) {
    fill(&dp[0][0][0], &dp[24][24][4], 2147483000);
    limit = board.size();
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            arr[i][j] = board[i].at(j);
        }
    } 
    dp[0][0][0] = 0; dp[0][0][1] = 0; dp[0][0][2] = 0; dp[0][0][3] = 0;
    q.push(ti(0, 0, -1));
    int answer = bfs();
    return answer;
}

int main() {
    vector<vector<int>> v;
    vector<int> tmp{ 0, 0, 0, 0, 0, 0 };
    v.push_back(tmp);
    vector<int> tmp1{ 0, 1, 1, 1, 1, 0 };
    v.push_back(tmp1);
    vector<int> tmp2{ 0, 0, 1, 0, 0, 0 };
    v.push_back(tmp2);
    vector<int> tmp3{ 1, 0, 0, 1, 0, 1 };
    v.push_back(tmp3);
    vector<int> tmp4{ 0, 1, 0, 0, 0, 1 };
    v.push_back(tmp4);
    vector<int> tmp5{ 0, 0, 0, 0, 0, 0 };
    v.push_back(tmp5);
    cout << solution(v);
}