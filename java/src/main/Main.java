package main;

import java.io.*;
import java.util.*;

public class Main {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static String input;
    public static String[] inputArr;
    public static int n, m, u, v, c, k, conn;
    public static long w;
    public static int[][] tree = new int[18][200001];
    public static PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[2]));

    public static int getRoot(int pow, int i) {
        while (tree[pow][i] != i) {
            i = tree[pow][i] = tree[pow][tree[pow][i]];
        }
        return i;
    }

    public static void mst() {
        while (!pq.isEmpty() && conn < n - 1) {
            int[] edge = pq.poll();

            u = edge[0];
            v = edge[1];
            c = edge[2];
            k = edge[3];

            int pow = 31 - Integer.numberOfLeadingZeros(k);
            int ru = getRoot(pow, u);
            int rv = getRoot(pow, v);

            if (ru == rv) {
                continue;
            }

            tree[pow][ru] = rv;

            if (k == 1) {
                conn++;
                w += c;
                continue;
            }

            int range = (int) Math.pow(2, pow - 1);
            int delta = k - range;

            if (getRoot(pow - 1, u) != getRoot(pow - 1, v)) {
                pq.add(new int[]{u, v, c, range});
            }
            if (getRoot(pow - 1, (u + delta) % n) != getRoot(pow - 1, (v + delta) % n)){
                pq.add(new int[]{(u + delta) % n, (v + delta) % n, c + delta, range});
            }
        }
    }

    public static void main(String[] args) throws IOException {
        input = br.readLine();
        inputArr = input.split(" ");

        n = Integer.parseInt(inputArr[0]);
        m = Integer.parseInt(inputArr[1]);
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= 17; j++) {
                tree[j][i] = i;
            }
        }

        for (int i = 0; i < m; i++) {
            input = br.readLine();
            StringTokenizer token = new StringTokenizer(input);

            u = Integer.parseInt(token.nextToken());
            v = Integer.parseInt(token.nextToken());
            c = Integer.parseInt(token.nextToken());
            k = Integer.parseInt(token.nextToken());

            int pow = 31 - Integer.numberOfLeadingZeros(k);
            int range = (int) Math.pow(2, pow);
            int delta = k - range;

            pq.add(new int[]{u, v, c, range});
            pq.add(new int[]{(u + delta) % n, (v + delta) % n, c + delta, range});
        }

        mst();
        System.out.println(conn == n - 1 ? w : -1);

    }
}