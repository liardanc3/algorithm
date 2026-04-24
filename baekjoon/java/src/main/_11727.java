import java.io.*;
import java.util.*;

public class _11727 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int N;
    public static int[] dp = new int[1001];

    public static void main(String[] args) throws IOException {
        dp[1] = 1; dp[2] = 3; dp[3] = 5;
        for(int i=4; i<=1000; i++){
            dp[i] = (dp[i-1] + 2*dp[i-2]) % 10007;
        }

        N = Integer.parseInt(br.readLine());
        System.out.println(dp[N]);

        // 1 3 5 11
        // dp[n-1] + 2*dp[n-2]

    }
}