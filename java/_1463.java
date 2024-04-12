import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class _1463 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static int X;
    public static int[] dp = new int[1_000_001];

    public static void main(String[] args) throws IOException {
        X = Integer.parseInt(br.readLine());

        for(int i=2; i<=X; i++){
            dp[i] = Integer.MAX_VALUE;
        }

        for(int i=1; i<=X-1; i++){
            dp[i+1] = Math.min(dp[i+1], dp[i] + 1);
            if(2*i <= X){
                dp[2*i] = Math.min(dp[2*i], dp[i] + 1);
            }
            if(3*i <= X){
                dp[3*i] = Math.min(dp[3*i], dp[i] + 1);
            }
        }

        System.out.println(dp[X]);
    }
}
