package main;

import java.io.*;
import java.util.StringTokenizer;

public class _25345 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static StringTokenizer st;
    public static int n, k;
    public static final long MOD = (long) (1e9 + 7);
    public static long[] fact = new long[2001];

    public static long pow(long a, long b) {
        if (b == 0) {
            return 1;
        }
        if (b == 1) {
            return a;
        }

        long half = pow(a, b/2) % MOD;

        if (b % 2 == 1) {
            return ((half * half) % MOD * a) % MOD;
        } else {
            return (half * half) % MOD;
        }
    }

    public static void main(String[] args) throws Exception {
        fact[0] = 1;
        for (int i = 1; i <= 2000; i++) {
            fact[i] = (fact[i-1] * i) % MOD;
        }
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());

        // nCk = (n! % MOD * k^(MOD-2) % MOD * (n-k)^(MOD-2) % MOD) % MOD
        // 2^k - 1
        long tower = (fact[n] % MOD * pow(fact[k], MOD-2) % MOD * pow(fact[n-k], MOD-2) % MOD) % MOD;
        long order = pow(2, k - 1) % MOD;
        System.out.println((tower * order) % MOD);
    }

}