package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class _1149 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int N;
    public static int[][] cost = new int[1001][3];
    public static int[][] dp = new int[1001][3];

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());

        for (int i = 1; i <= N; i++) {
            String[] input = br.readLine().split(" ");

            for(int j = 0; j < 3; j++){
                cost[i][j] = Integer.parseInt(input[j]);
            }
        }

        dp[1][0] = cost[1][0];
        dp[1][1] = cost[1][1];
        dp[1][2] = cost[1][2];

        System.out.println(Math.min(dynamic(N, 0), Math.min(dynamic(N, 1), dynamic(N, 2))));
    }

    private static int dynamic(int n, int color){
        if(dp[n][color] != 0){
            return dp[n][color];
        }

        dp[n][color] = Integer.MAX_VALUE;
        for(int i=0; i<3; i++){
            if(i != color){
                dp[n][color] = Math.min(dp[n][color], dynamic(n-1, i) + cost[n][color]);
            }
        }

        return dp[n][color];
    }
}

