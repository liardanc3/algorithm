package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class _13172 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int M;
    public static long answer, a, b, bRev;
    public static long DIV = 1_000_000_007L;

    public static void main(String[] args) throws IOException {
        M = Integer.parseInt(br.readLine());

        for (int i = 0; i < M; i++) {
            String[] input = br.readLine().split(" ");

            b = Long.parseLong(input[0]) % DIV;
            a = Long.parseLong(input[1]) % DIV;

            bRev = getRev(b);
            answer = (answer + (a % DIV * bRev % DIV ) % DIV) % DIV;
        }

        System.out.println(answer);
    }

    private static long getRev(long n) {
        return power(n, DIV - 2) % DIV;
    }

    private static long power(long n, long p) {
        if (p == 0) return 1;
        if (p == 1) return n;

        long half = power(n, p / 2) % DIV;

        if (p % 2 == 0) {
            return (half * half) % DIV;
        }
        return (((half * half) % DIV) * n) % DIV;
    }
}

