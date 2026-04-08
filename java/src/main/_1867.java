package main;

import java.io.*;
import java.util.*;

public class _1867 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static StringTokenizer st;
    public static int n, k;
    public static final int INF = Integer.MAX_VALUE;
    public static List<Integer>[] graph = new ArrayList[1001];
    public static Set<Integer> leftSet = new HashSet<>();
    public static Set<Integer> leftMvcSet = new HashSet<>();
    public static Set<Integer> rightMvcSet = new HashSet<>();
    public static int[] left = new int[501];
    public static int[] right = new int[1001];
    public static int[] dist = new int[1001];
    public static int[] visited = new int[1001];

    public static boolean hasAugmentPathEnd() {
        Queue<Integer> q = new ArrayDeque<>();

        for (int l : leftSet) {
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

            if (dist[l] < dist[0]) {
                for (int r : graph[l]) {
                    int matchedLeft = right[r];

                    if (dist[matchedLeft] == INF && dist[l] + 1 < dist[matchedLeft]) {
                        dist[matchedLeft] = dist[l] + 1;
                        q.add(matchedLeft);
                    }
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

            if (dist[matchedLeft] == dist[l] + 1 && connectedAugmentPathEnd(matchedLeft)) {
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
            for (int l : leftSet) {
                if (left[l] == 0) {
                    connectedAugmentPathEnd(l);
                }
            }
        }
    }

    public static void findMvc(int l) {
        visited[l] = 1;
        leftMvcSet.remove(l);

        for (int r : graph[l]) {
            if (left[l] == r) {
                continue;
            }

            int matchedLeft = right[r];
            if (matchedLeft != 0 && visited[matchedLeft] == 0) {
                rightMvcSet.add(r);
                findMvc(matchedLeft);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        for (int i = 1; i <= n + n; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int i = 0; i < k; i++) {
            st = new StringTokenizer(br.readLine());

            int left = Integer.parseInt(st.nextToken());
            int right = Integer.parseInt(st.nextToken());

            graph[left].add(right);
            leftSet.add(left);
        }

        bipartite();

        leftMvcSet.addAll(leftSet);

        for (int l : leftSet) {
            if (left[l] == 0) {
                Arrays.fill(visited, 0);
                findMvc(l);
            }
        }

        System.out.println(leftMvcSet.size() + rightMvcSet.size());
    }
}