package src.main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class _9465 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int T, n, point;
    public static int[][] arr = new int[2][100001];
    public static int[][] dp = new int[2][100001];

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());

        while(T-- > 0){
            n = Integer.parseInt(br.readLine());

            for(int i = 0; i < 2; i++){
                String[] input = br.readLine().split(" ");
                for(int j = 1; j <= n; j++){
                    arr[i][j] = Integer.parseInt(input[j-1]);
                }
            }

            for(int i = 1; i <= n; i++){
                dp[0][i] = arr[0][i];
                dp[1][i] = arr[1][i];

                if(i-1 >= 1){
                    dp[0][i] = Math.max(dp[0][i], arr[0][i] + dp[1][i-1]);
                    dp[1][i] = Math.max(dp[1][i], arr[1][i] + dp[0][i-1]);
                }

                if(i-2 >= 1){
                    dp[0][i] = Math.max(dp[0][i], arr[0][i] + dp[0][i-2]);
                    dp[0][i] = Math.max(dp[0][i], arr[0][i] + dp[1][i-2]);

                    dp[1][i] = Math.max(dp[1][i], arr[1][i] + dp[0][i-2]);
                    dp[1][i] = Math.max(dp[1][i], arr[1][i] + dp[1][i-2]);

                }
            }

            sb.append(Math.max(dp[0][n], dp[1][n])).append("\n");
        }

        System.out.println(sb);
    }
}

