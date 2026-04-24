package main;

import java.io.*;
import java.util.*;

public class _2051 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static StringTokenizer st;
    public static int n, m, b, matching;
    public static List<Integer>[] graph = new ArrayList[1001];
    public static int[] left = new int[1001];
    public static int[] right = new int[1001];
    public static int[] dist = new int[1001];
    public static int[] visited = new int[1001];
    public static Set<Integer> leftSet = new HashSet<>();
    public static Set<Integer> rightSet = new HashSet<>();

    public static boolean hasAugmentPathEnd() {
        Queue<Integer> q = new ArrayDeque<>();

        for (int l = 1; l <= n; l++) {
            if (left[l] == 0) {
                q.add(l);
                dist[l] = 0;
            } else {
                dist[l] = Integer.MAX_VALUE;
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

        for (Integer r : graph[l]) {
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

    public static void bipartite() {
        while (hasAugmentPathEnd()) {
            for (int i = 1; i <= n; i++) {
                if (left[i] == 0 && connectedAugmentPathEnd(i)) {
                    matching++;
                }
            }
        }
    }

    public static void trace(int l) {
        visited[l] = 1;
        leftSet.remove(l);
        for (int r : graph[l]) {
            rightSet.add(r);

            if (left[l] == r) {
                continue;
            }

            int matchedLeft = right[r];
            if (matchedLeft != 0 && visited[matchedLeft] != 1) {
                trace(matchedLeft);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        for (int i = 1; i <= n; i++) {
            graph[i] = new ArrayList<>();
            leftSet.add(i);
        }

        m = Integer.parseInt(st.nextToken());
        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());

            int count = Integer.parseInt(st.nextToken());
            while (count-- > 0) {
                b = Integer.parseInt(st.nextToken());
                graph[i].add(b);
            }
        }

        bipartite();

        bw.write(matching + "\n");
        for (int i = 1; i <= n; i++) {
            if (left[i] == 0) {
                trace(i);
            }
        }
        bw.write(leftSet.size() + " ");
        for (Integer i : leftSet) {
            bw.write(i + " ");
        }
        bw.write("\n" + rightSet.size() + " ");
        for (Integer i : rightSet) {
            bw.write(i + " ");
        }
        bw.flush();
    }
}