package src.main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class _17070 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int[][] arr = new int[18][18];
    public static int[][][][] dp = new int[18][18][18][18];
    public static int N, M;

    public static void main(String[] args) throws IOException {
        String[] input = br.readLine().split(" ");

        N = Integer.parseInt(input[0]);

        for(int i = 1; i <= N; i++) {
            input = br.readLine().split(" ");

            for(int j = 1; j <= N; j++){
                arr[i][j] = Integer.parseInt(input[j-1]);
            }
        }

        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                dp[i][j][N][N] = 1;
            }
        }

        System.out.println(dfs(1,1, 1, 2));
    }

    private static int dfs(int y1, int x1, int y2, int x2){
        if(dp[y1][x1][y2][x2] != 0){
            return dp[y1][x1][y2][x2];
        }

        int status = getStatus(y1, x1, y2, x2);

        if(status == 1){
            int ny1 = y2;
            int nx1 = x2;
            int ny2 = y2;
            int nx2 = x2 + 1;

            if(nx2 <= N && arr[ny2][nx2] == 0){
                dp[y1][x1][y2][x2] += dfs(ny1, nx1, ny2, nx2);
            }

            ny2 = y2 + 1;
            if(ny2 <= N && nx2 <= N && arr[ny2][nx2] == 0 && arr[ny2-1][nx2] == 0 && arr[ny2][nx2-1] == 0){
                dp[y1][x1][y2][x2] += dfs(ny1, nx1, ny2, nx2);
            }
        } else if(status == 2){
            int ny1 = y2;
            int nx1 = x2;
            int ny2 = y2 + 1;
            int nx2 = x2;

            if(ny2 <= N && arr[ny2][nx2] == 0){
                dp[y1][x1][y2][x2] += dfs(ny1, nx1, ny2, nx2);
            }

            nx2 = x2 + 1;
            if(ny2 <= N && nx2 <= N && arr[ny2][nx2] == 0 && arr[ny2-1][nx2] == 0 && arr[ny2][nx2-1] == 0){
                dp[y1][x1][y2][x2] += dfs(ny1, nx1, ny2, nx2);
            }
        } else {
            int ny1 = y2;
            int nx1 = x2;
            int ny2 = y2;
            int nx2 = x2 + 1;

            if(nx2 <= N && arr[ny2][nx2] == 0){
                dp[y1][x1][y2][x2] += dfs(ny1, nx1, ny2, nx2);
            }

            ny2 = y2 + 1;
            nx2 = x2;
            if(ny2 <= N && arr[ny2][nx2] == 0){
                dp[y1][x1][y2][x2] += dfs(ny1, nx1, ny2, nx2);
            }

            ny2 = y2 + 1;
            nx2 = x2 + 1;
            if(ny2 <= N && nx2 <= N &&  arr[ny2][nx2] == 0 && arr[ny2-1][nx2] == 0 && arr[ny2][nx2-1] == 0){
                dp[y1][x1][y2][x2] += dfs(ny1, nx1, ny2, nx2);
            }
        }

        return dp[y1][x1][y2][x2];
    }

    private static int getStatus(int y1, int x1, int y2, int x2){
        if(y1 == y2 && x1+1 == x2){
            return 1;
        }
        if(y1+1 == y2 && x1 == x2){
            return 2;
        }
        return 3;
    }
}

