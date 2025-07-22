package src.main;

import java.io.*;
import java.util.Arrays;

public class _25304 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static StringBuilder sb = new StringBuilder();
    public static int x, n, a, b, sum;

    public static void main(String[] args) throws IOException {
        x = Integer.parseInt(br.readLine());
        n = Integer.parseInt(br.readLine());

        while (n-- > 0) {
            String[] input = br.readLine().split(" ");
            sum += Integer.parseInt(input[0]) * Integer.parseInt(input[1]);
        }

        System.out.println(sum == x ? "Yes" : "No");
    }
}
