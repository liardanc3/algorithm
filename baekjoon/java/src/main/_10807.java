package main;

import java.io.*;
import java.util.Arrays;

public class _10807 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static StringBuilder sb = new StringBuilder();
    public static int n, v;
    public static int[] arr = new int[201];

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        String[] input = br.readLine().split(" ");

        while (--n >= 0) {
            arr[Integer.parseInt(input[n]) + 100]++;
        }

        System.out.println(arr[Integer.parseInt(br.readLine()) + 100]);
    }
}
