package main;

import java.io.*;
import java.util.*;

public class _2188 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static StringTokenizer st;
    public static int n, m, matching;
    public static List<Integer>[] graph = new ArrayList[201];
    public static int[] left = new int[201];
    public static int[] right = new int[201];
    public static int[] dist = new int[201];

    public static boolean hasAugmentPathEnd() {
        Queue<Integer> q = new ArrayDeque<>();

        for (int i = 1; i <= n; i++) {
            if (left[i] == 0) {
                q.add(i);
                dist[i] = 0;
            } else {
                dist[i] = Integer.MAX_VALUE;
            }
        }

        dist[0] = Integer.MAX_VALUE;

        while (!q.isEmpty()) {
            int l = q.poll();

            if (dist[l] >= dist[0]) {
                continue;
            }

            for (int r : graph[l]) {
                int matchedLeft = right[r];

                if (dist[matchedLeft] == Integer.MAX_VALUE) {
                    dist[matchedLeft] = dist[l] + 1;
                    q.add(matchedLeft);
                }
            }
        }

        return dist[0] != Integer.MAX_VALUE;
    }

    public static boolean connectedAugmentPathEnd(int l) {
        if (l == 0) {
            return true;
        }

        for (int r : graph[l]) {
            int matchedLeft = right[r];

            if (dist[l] + 1 == dist[matchedLeft] && connectedAugmentPathEnd(matchedLeft)) {
                right[r] = l;
                left[l] = r;
                return true;
            }
        }

        dist[l] = Integer.MAX_VALUE;
        return false;
    }

    public static int bipartite() {
        int matching = 0;

        while (hasAugmentPathEnd()) {
            for (int i = 1; i <= n; i++) {
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

            st = new StringTokenizer(br.readLine());

            int count = Integer.parseInt(st.nextToken());
            while (count-- > 0) {
                int r = Integer.parseInt(st.nextToken());

                graph[i].add(r);
            }
        }

        System.out.println(bipartite());
    }
}