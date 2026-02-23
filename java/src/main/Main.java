package main;

import java.io.*;
import java.util.*;

public class Main {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static String input;
    public static String[] inputArr;
    public static int n, p, conn;
    public static int mn = Integer.MAX_VALUE;
    public static long answer;
    public static int[] tree = new int[10001];
    public static int[] cost = new int[10001];
    public static PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[2]));

    public static int getRoot(int i) {
        while(tree[i] != i) {
            i = tree[i] = tree[tree[i]];
        }
        return tree[i];
    }

    public static void mst() {
        while(!pq.isEmpty() && conn < n - 1) {
            int[] edge = pq.poll();

            int a = edge[0];
            int b = edge[1];
            int w = edge[2];

            int ra = getRoot(a);
            int rb = getRoot(b);

            if (ra != rb) {
                tree[rb] = ra;
                conn++;
                answer += w;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        input = br.readLine();
        inputArr = input.split(" ");

        n = Integer.parseInt(inputArr[0]);
        p = Integer.parseInt(inputArr[1]);

        for (int i = 0; i < n; i++) {
            cost[i + 1] = Integer.parseInt(br.readLine());
            tree[i + 1] = i + 1;
            mn = Math.min(mn, cost[i + 1]);
        }

        for (int i = 0; i < p; i++) {
            StringTokenizer token = new StringTokenizer(br.readLine());

            int a = Integer.parseInt(token.nextToken());
            int b = Integer.parseInt(token.nextToken());
            int w = Integer.parseInt(token.nextToken());
            int ww = cost[a] + cost[b] + 2 * w;

            pq.add(new int[]{a, b, ww});
        }

        mst();
        System.out.println(answer + mn);
    }
}