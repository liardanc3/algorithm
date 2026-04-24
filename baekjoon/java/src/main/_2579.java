import java.io.*;
import java.util.*;

public class _2579 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static int N;
    public static int[] arr = new int[303];
    public static int[][] dp = new int[303][3];

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());

        for(int i=1; i<=N; i++){
            arr[i] = Integer.parseInt(br.readLine());
        }

        for(int i=0; i<N; i++){

            dp[i+1][1] = Math.max(dp[i+1][1], dp[i][0] + arr[i+1]);
            dp[i+2][1] = Math.max(dp[i+2][1], Math.max(dp[i][0], Math.max(dp[i][1],dp[i][2])) + arr[i+2]);

            dp[i+1][2] = Math.max(dp[i+1][2], Math.max(dp[i][1], dp[i][0]) + arr[i+1]);

        }

        System.out.println(Math.max(dp[N][1], dp[N][2]));
    }
}
