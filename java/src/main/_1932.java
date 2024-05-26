import java.io.*;
import java.util.*;

public class _1932 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int N;
    public static int[][] arr = new int[501][501];
    public static long[][] dp = new long[501][501];
    public static long answer = 0;

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());

        for(int i=1; i<=N; i++){
            String[] input = br.readLine().split(" ");
            for(int j=1; j<=i; j++){
                arr[i][j] = Integer.parseInt(input[j-1]);
            }
        }

        for(int i=1; i<=N; i++){
            answer = Math.max(answer, dynamic(N, i));
        }

        System.out.println(answer);
    }

    private static long dynamic(int r, int c){
        if(r==0 || c==0 || c>r){
            return 0;
        }
        if(dp[r][c] != 0){
            return dp[r][c];
        }

        return dp[r][c] = arr[r][c] + Math.max(dynamic(r-1, c-1), dynamic(r-1, c));
    }
}