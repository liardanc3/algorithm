package src.main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class _10818 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int N, mn = 123123123, mx = -1231231232;

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());

        String[] input = br.readLine().split(" ");
        for(int i=1; i<=N; i++){
            int now = Integer.parseInt(input[i-1]);
            mn = Math.min(now, mn);
            mx = Math.max(now, mx);
        }

        System.out.println(mn + " " + mx);

    }
}

