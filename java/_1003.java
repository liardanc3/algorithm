import java.io.*;
import java.sql.SQLOutput;
import java.util.*;
import java.util.stream.Collectors;

public class _1003 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static int T,N;
    public static int[][] dp = {
            {1, 0},
            {0, 1},
            {1, 1},
            {1, 2},
            {2, 3},
            {3, 5},
            {5, 8},
            {8, 13},
            {13, 21},
            {21, 34},
            {34, 55},
            {55, 89},
            {89, 144},
            {144, 233},
            {233, 377},
            {377, 610},
            {610, 987},
            {987, 1597},
            {1597, 2584},
            {2584, 4181},
            {4181, 6765},
            {6765, 10946},
            {10946, 17711},
            {17711, 28657},
            {28657, 46368},
            {46368, 75025},
            {75025, 121393},
            {121393, 196418},
            {196418, 317811},
            {317811, 514229},
            {514229, 832040},
            {832040, 1346269},
            {1346269, 2178309},
            {2178309, 3524578},
            {3524578, 5702887},
            {5702887, 9227465},
            {9227465, 14930352},
            {14930352, 24157817},
            {24157817, 39088169},
            {39088169, 63245986},
            {63245986, 102334155}
    };


    public static void main(String[] args) throws IOException {
        StringBuilder sb = new StringBuilder();

        //dynamic(40);

        T = Integer.parseInt(br.readLine());
        for(int i=0; i<T; i++){
            N = Integer.parseInt(br.readLine());

            sb.append(dp[N][0]).append(" ").append(dp[N][1]).append('\n');
        }

        System.out.println(sb.toString());
    }

    public static int[] dynamic(int n){
        if(dp[n][0] != 0 || dp[n][1] != 0){
            return dp[n];
        }
        if(n==0){
            return dp[n] = new int[]{1, 0};
        } else if (n==1){
            return dp[n] = new int[]{0, 1};
        } else {
            return dp[n] = new int[]{
                    dynamic(n-1)[0] + dynamic(n-2)[0],
                    dynamic(n-1)[1] + dynamic(n-2)[1]
            };
        }
    }
}
