package main;

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static long n, k, q;

    public static void main(String[] args) throws IOException {
        StringTokenizer input = new StringTokenizer(br.readLine());

        // (N+1)/K = parent
        // logN / logK = depth
        n = Long.parseLong(input.nextToken());
        k = Integer.parseInt(input.nextToken());
        q = Integer.parseInt(input.nextToken());

        for (int i = 0; i < q; i++) {
            input = new StringTokenizer(br.readLine());

            long x = Long.parseLong(input.nextToken());
            long y = Long.parseLong(input.nextToken());

            if (k == 1) {
                bw.write(Math.abs(x - y) + "\n");
                continue;
            }

            long dist = 0;
            while (x != y) {
                dist++;
                if (x > y) {
                    x = (x - 2) / k + 1;
                } else {
                    y = (y - 2) / k + 1;
                }
            }

            bw.write((dist) + "\n");
        }

        bw.flush();
    }
}