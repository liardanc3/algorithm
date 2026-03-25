package main;

import java.io.*;
import java.util.*;

public class _2673 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static StringTokenizer st;
    public static int n, a, b, mx;
    public static int[][] dp = new int[101][101];
    public static int[][] line = new int[101][101];

    public static int f(int left, int right) {
        if (dp[left][right] != -1) {
            return dp[left][right];
        }
        if (left >= right) {
            return 0;
        }

        dp[left][right] = 0;

        if (line[left][right] == 1) {
            dp[left][right] = f(left + 1, right - 1) + 1;
        }

        for (int i = left + 1; i <= right - 1; i++) {
            dp[left][right] = Math.max(dp[left][right], f(left, i) + f(i, right));
        }

        return dp[left][right];
    }

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());

            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());

            if (a > b) {
                int tmp = b;
                b = a;
                a = tmp;
            }

            line[a][b] = 1;
        }
        for (int i = 1; i < 100; i++) {
            for (int j = i + 1; j <= 100; j++) {
                dp[i][j] = -1;
            }
        }
        mx = f(1, 100);
        System.out.println(mx);
    }
}