import java.io.*;
import java.util.*;

public class _17626 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int[] dp = new int[50001];
    public static List<Integer> list = new ArrayList<>();
    public static int N, cnt;

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());

        for(int i=1; i*i<=N; i++){
            dp[i*i] = 1;
        }
        for(int i=1; i<=N; i++){
            dp[i] = dp[i] != 0 ? dp[i] : dp[i-1] + 1;
            for(int j=1; j*j<=i; j++){
                dp[i] = Math.min(dp[i], dp[i-j*j] + dp[j*j]);
            }
        }

        System.out.println(dp[N]);
    }
}