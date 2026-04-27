package main;

import java.io.*;
import java.util.*;

public class _1574 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static StringTokenizer st;
    public static int r, c, n, matching;
    public static final int INF = Integer.MAX_VALUE;
    public static int[][] arr = new int[301][301];
    public static List<Integer>[] graph = new ArrayList[301];
    public static int[] left = new int[301];
    public static int[] right = new int[301];
    public static int[] dist = new int[301];

    public static void init() throws IOException {
        st = new StringTokenizer(br.readLine());

        r = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());

        for (int i = 0; i <= 300; i++) {
            graph[i] = new ArrayList<>();
        }

        while (n-- > 0) {
            st = new StringTokenizer(br.readLine());

            int y = Integer.parseInt(st.nextToken());
            int x = Integer.parseInt(st.nextToken());

            arr[y][x] = 1;
        }

        for (int y = 1; y <= Main.r; y++) {
            for (int x = 1; x <= Main.c; x++) {
                if (arr[y][x] == 1) {
                    continue;
                }

                graph[y].add(x);
            }
        }
    }

    public static boolean hasAugmentPathEnd() {
        Queue<Integer> q = new ArrayDeque<>();

        for (int l = 1; l <= r; l++) {
            if (left[l] == 0) {
                q.add(l);
                dist[l] = 0;
            } else {
                dist[l] = INF;
            }
        }

        dist[0] = INF;

        while (!q.isEmpty()) {
            int l = q.poll();

            if (dist[l] >= dist[0]) {
                continue;
            }

            for (int next : graph[l]) {
                int matchedLeft = right[next];

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

        for (int next : graph[l]) {
            int matchedLeft = right[next];

            if (dist[l] + 1 == dist[matchedLeft] && connectedAugmentPathEnd(matchedLeft)) {
                left[l] = next;
                right[next] = l;
                return true;
            }
        }

        dist[l] = INF;
        return false;
    }

    public static int bipartite() {
        while (hasAugmentPathEnd()) {
            for (int l = 1; l <= r; l++) {
                if (left[l] == 0 && connectedAugmentPathEnd(l)) {
                    matching++;
                }
            }
        }

        return matching;
    }

    public static void main(String[] args) throws IOException {
        init();

        bw.write(bipartite() + "\n");
        bw.flush();
    }
}