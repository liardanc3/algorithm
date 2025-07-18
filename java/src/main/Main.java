package src.main;

import java.io.*;
import java.util.Arrays;

public class Main {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static StringBuilder sb = new StringBuilder();
    public static int[] arr = new int[] {0,0,0,0,0,0,0};

    public static void main(String[] args) throws IOException {
        Arrays.stream(br.readLine().split(" "))
                .map(Integer::parseInt)
                .forEach(num -> arr[num]++);

        for (int i = 1; i <= 6; i++) {
            if (arr[i] != 0) {
                sb = new StringBuilder();
            }

            if (arr[i] == 3) {
                sb.append(10_000 + i * 1_000);
                System.out.println(sb.toString());
                return;
            } else if (arr[i] == 2) {
                sb.append(1_000 + i * 100);
                System.out.println(sb.toString());
                return;
            } else{
                sb.append(i * 100);
            }
        }

        System.out.println(sb.toString());
    }
}
