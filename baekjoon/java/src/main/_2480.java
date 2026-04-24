package main;

import java.io.*;
import java.util.Arrays;

public class _2480 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int[] arr = new int[] {0,0,0,0,0,0,0};
    public static int mx = 0;

    public static void main(String[] args) throws IOException {
        Arrays.stream(br.readLine().split(" "))
                .map(Integer::parseInt)
                .forEach(num -> arr[num]++);

        for (int i = 1; i <= 6; i++) {
            if (arr[i] == 3) {
                mx = Math.max(mx, 10_000 + i * 1_000);
            } else if (arr[i] == 2) {
                mx = Math.max(mx, 1_000 + i * 100);
            } else if (arr[i] == 1) {
                mx = Math.max(mx, i * 100);
            }
        }

        System.out.print(mx);
    }
}
