package main;

import java.io.*;
import java.util.*;

public class _11376 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static StringTokenizer st;
    public static int n, m, matching;
    public static final int INF = Integer.MAX_VALUE;
    public static List<Integer>[] graph = new ArrayList[2001];
    public static int[] left = new int[2001];
    public static int[] right = new int[1001];
    public static int[] dist = new int[2001];

    public static boolean hasAugmentPathEnd() {
        Queue<Integer> q = new ArrayDeque<>();

        for (int i = 1; i <= 2 * n; i++) {
            if (left[i] == 0) {
                dist[i] = 0;
                q.add(i);
            } else {
                dist[i] = INF;
            }
        }

        dist[0] = INF;

        while (!q.isEmpty()) {
            int l = q.poll();

            for (int r : graph[l]) {
                int matchedLeft = right[r];

                if (dist[matchedLeft] == INF) {
                    dist[matchedLeft] = dist[l] + 1;
                    q.add(matchedLeft);
                }
            }
        }

        return dist[0] != INF;
    }

    public static boolean connectedAugmentPathEnd(int l) {
        if (l == 0) {
            return true;
        }

        for (int r : graph[l]) {
            int matchedLeft = right[r];

            if (dist[l] + 1 == dist[matchedLeft] && connectedAugmentPathEnd(matchedLeft)) {
                left[l] = r;
                right[r] = l;
                return true;
            }
        }

        dist[l] = INF;
        return false;
    }

    public static int bipartite() {
        while (hasAugmentPathEnd()) {
            for (int i = 1; i <= 2 * n; i++) {
                if (left[i] == 0 && connectedAugmentPathEnd(i)) {
                    matching++;
                }
            }
        }

        return matching;
    }

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        graph[0] = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            graph[i] = new ArrayList<>();
            graph[i + n] = new ArrayList<>();

            st = new StringTokenizer(br.readLine());

            int number = Integer.parseInt(st.nextToken());
            while (number-- > 0) {
                int work = Integer.parseInt(st.nextToken());
                graph[i].add(work);
                graph[i + n].add(work);
            }
        }

        System.out.println(bipartite());
    }
}