import java.io.*;
import java.util.*;

public class _11726 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static long[] dp = new long[1010];
    public static int n;

    public static void main(String[] args) throws IOException {
        dp[0] = 1; dp[1] = 1; dp[2] = 2; dp[3] = 3; dp[4] = 5;
        for(int i=0; i<=1000; i++){
            dp[i+1] + dp[i];
            dp[i+2] += (dp[i] * 2);=
        }

        n = Integer.parseInt(br.readLine());
        System.out.println(dp[n]%10007);
    }

    private static long dynamic(int now){
        if(dp[now] == 0){
            dp[now] = (2 * dynamic(now - 2)) % 10007;
        }
        return dp[now];
    }
}