import java.io.*;
import java.util.*;

public class _9095 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static int T, n;
    public static int[] dp = new int[13];

    public static void main(String[] args) throws IOException {
        StringBuilder sb = new StringBuilder();

        dp[0] = 1;
        for(int i=0; i<10; i++){
            dp[i+1] += dp[i];
            dp[i+2] += dp[i];
            dp[i+3] += dp[i];
        }

        T = Integer.parseInt(br.readLine());
        while(T-- > 0){
            n = Integer.parseInt(br.readLine());

            sb.append(dp[n]).append("\n");
        }

        System.out.println(sb.toString());

    }

}