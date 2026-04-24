package main;

import java.io.*;
import java.util.*;

public class _34547 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static StringTokenizer st;
    public static int n, a, b, k, mx;
    public static int[][] dp = new int[501][1001];

    public static int f(int day, int gap) {
        if (dp[day][gap] != -1) {
            return dp[day][gap];
        }

        dp[day][gap] = 0;

        int aa = (a + b + gap) / 2;
        int bb = a + b - aa;

        if (day < n) {
            for (int i = k; i <= aa; i++) {
                int nextA = aa - i;
                int nextB = bb + i;
                int nextGap = Math.abs(nextA - nextB);

                dp[day][gap] = Math.max(dp[day][gap], f(day + 1, nextGap));
            }
        }

        return dp[day][gap] = dp[day][gap] + aa * bb;
    }

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        a = Integer.parseInt(st.nextToken());
        b = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        if (a < b) {
            int tmp = b;
            b = a;
            a = tmp;
        }

        for (int i = 0; i <= n; i++) {
            Arrays.fill(dp[i], -1);
        }

        System.out.println(f(0, a - b) - a * b);
    }
}