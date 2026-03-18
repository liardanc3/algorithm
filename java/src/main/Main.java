package main;

import java.io.*;
import java.util.*;

public class Main {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static int n, m, k, answer, conn;
    public static int[] tree = new int[1001];
    public static PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparing(a -> a[0]));

    public static int getRoot(int i) {
        return (tree[i] == i) ? i : (tree[i] = getRoot(tree[i]));
    }

    public static void mst() {
        while (!pq.isEmpty() && conn < n) {
            int[] edges = pq.poll();

            int w = edges[0];
            int a = edges[1];
            int b = edges[2];

            int ra = getRoot(a);
            int rb = getRoot(b);

            if (ra != rb) {
                tree[ra] = rb;
                conn++;
                answer += w;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        StringTokenizer input = new StringTokenizer(br.readLine());

        n = Integer.parseInt(input.nextToken());
        m = Integer.parseInt(input.nextToken());
        k = Integer.parseInt(input.nextToken());
        conn = k - 1;

        input = new StringTokenizer(br.readLine());

        for (int i = 0; i <= n; i++) {
            tree[i] = i;
        }
        for (int i = 0; i < k; i++) {
            tree[Integer.parseInt(input.nextToken())] = 0;
        }

        for (int i = 0; i < m; i++) {
            input = new StringTokenizer(br.readLine());

            int u = Integer.parseInt(input.nextToken());
            int v = Integer.parseInt(input.nextToken());
            int w = Integer.parseInt(input.nextToken());

            pq.add(new int[]{w, u, v});
        }

        mst();
        System.out.println(answer);
    }
}