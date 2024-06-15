package src.main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class _9663 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int N, answer;
    public static int[][] visited = new int[16][16];
    public static int[] dy = new int[]{-1, -1, -1};
    public static int[] dx = new int[]{-1, 0, 1};

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());

        backtracking(0, 0, 0);

        System.out.println(answer);
    }

    private static void backtracking(int y, int x, int cnt){
        if(cnt == N){
            answer++;
            return;
        }

        if(y+1<=N){
            for (int j = 1; j <= N; j++) {
                if (!isVisited(y + 1, j)) {
                    visited[y + 1][j] = 1;
                    backtracking(y + 1, j, cnt + 1);
                    visited[y + 1][j] = 0;
                }
            }
        }

    }

    private static boolean isVisited(int y, int x){
        boolean result = visited[y][x] == 1;

        for(int i=0; i<3 && !result; i++){
            int ddy = y + dy[i];
            int ddx = x + dx[i];

            while(1<=ddy&&ddy<=N&&1<=ddx&&ddx<=N&&!result){
                result = visited[ddy][ddx] > 0;

                ddy += dy[i];
                ddx += dx[i];
            }
        }

        return result;
    }
}

