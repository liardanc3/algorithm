package main;

import java.io.*;
import java.util.*;

public class _3295 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static StringTokenizer st;
    public static int t, n, m, u, v, matching;
    public static final int AUGMENT_PATH_END = 0;
    public static final int INF = Integer.MAX_VALUE;
    public static List<Integer>[] graph = new ArrayList[2001];
    public static int[] left = new int[2001];
    public static int[] right = new int[2001];
    public static int[] dist = new int[2001];

    public static boolean hasAugmentPathEnd() {
        Queue<Integer> q = new ArrayDeque<>();

        for (int l = 1; l <= n; l++) {
            if (left[l] == 0) {
                q.add(l);
                dist[l] = 0;
            } else {
                dist[l] = INF;
            }
        }

        dist[AUGMENT_PATH_END] = INF;

        while (!q.isEmpty()) {
            int l = q.poll();

            if (dist[l] >= dist[AUGMENT_PATH_END]) {
                continue;
            }

            for (int r : graph[l]) {
                int matchedLeft = right[r];

                if (dist[matchedLeft] == INF) {
                    dist[matchedLeft] = dist[l] + 1;
                    q.add(matchedLeft);
                }
            }
        }

        return dist[AUGMENT_PATH_END] != INF;
    }

    public static boolean connectedAugmentPathEnd(int l) {
        if (l == AUGMENT_PATH_END) {
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

    public static void bipartite() {
        while (hasAugmentPathEnd()) {
            for (int l = 1; l <= n; l++) {
                if (left[l] == 0 && connectedAugmentPathEnd(l)) {
                    matching++;
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            Arrays.fill(left, 0);
            Arrays.fill(right, 0);
            Arrays.fill(dist, 0);
            matching = 0;

            st = new StringTokenizer(br.readLine());

            n = Integer.parseInt(st.nextToken());
            for (int i = 1; i <= 2000; i++) {
                graph[i] = new ArrayList<>();
            }
            m = Integer.parseInt(st.nextToken());

            for (int i = 0; i < m; i++) {
                st = new StringTokenizer(br.readLine());

                u = Integer.parseInt(st.nextToken()) + 1;
                v = Integer.parseInt(st.nextToken()) + 1 + 1000;
                graph[u].add(v);
            }

            bipartite();
            bw.write(matching + "\n");
        }
        bw.flush();
    }
}