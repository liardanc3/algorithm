package main;

import java.io.*;
import java.util.*;

public class _1671 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static StringTokenizer st;
    public static int n, answer;
    public static final int AUGMENT_PATH_END = 0;
    public static final int NOT_VISITED = Integer.MAX_VALUE;
    public static int[][] stat = new int[3][51];
    public static List<Integer>[] graph = new ArrayList[101];
    public static boolean[] in = new boolean[51];
    public static int[] left = new int[101];
    public static int[] right = new int[151];
    public static int[] dist = new int[151];

    public static boolean hasAugmentPathEnd() {
        Queue<Integer> q = new ArrayDeque<>();

        for (int i = 1; i <= n + n; i++) {
            if (left[i] == 0) {
                dist[i] = 0;
                q.add(i);
            } else {
                dist[i] = NOT_VISITED;
            }
        }

        dist[AUGMENT_PATH_END] = NOT_VISITED;

        while (!q.isEmpty()) {
            int l = q.poll();

            if (dist[l] < dist[AUGMENT_PATH_END]) {
                for (int r : graph[l]) {
                    int matchedLeft = right[r];

                    if (dist[matchedLeft] == NOT_VISITED) {
                        dist[matchedLeft] = dist[l] + 1;
                        q.add(matchedLeft);
                    }
                }
            }
        }

        return dist[AUGMENT_PATH_END] != NOT_VISITED;
    }

    public static boolean connectAugmentPathEnd(int l) {
        if (l == AUGMENT_PATH_END) {
            return true;
        }

        for (int r : graph[l]) {
            int matchedLeft = right[r];

            if (dist[matchedLeft] == dist[l] + 1 && connectAugmentPathEnd(matchedLeft)) {
                left[l] = r;
                right[r] = l;
                return true;
            }
        }

        dist[l] = NOT_VISITED;
        return false;
    }

    public static void bipartite() {
        while (hasAugmentPathEnd()) {
            for (int i = 1; i <= n + n; i++) {
                if (left[i] == 0) {
                    connectAugmentPathEnd(i);
                }
            }
        }
    }

    public static boolean isStrongerThan(int a, int b) {
        return stat[0][a] >= stat[0][b] && stat[1][a] >= stat[1][b] && stat[2][a] >= stat[2][b];
    }

    public static boolean isEqual(int a, int b) {
        return stat[0][a] == stat[0][b] && stat[1][a] == stat[1][b] && stat[2][a] == stat[2][b];
    }

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());

        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());

            stat[0][i] = Integer.parseInt(st.nextToken());
            stat[1][i] = Integer.parseInt(st.nextToken());
            stat[2][i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 1; i <= n + n; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (i == j) {
                    continue;
                }

                if (isStrongerThan(i, j)) {
                    graph[i].add(j + n * 2);
                    graph[i + n].add(j + n * 2);
                    in[j] = true;
                }

                if (isStrongerThan(j, i) && !isEqual(j, i)) {
                    graph[j].add(i + n * 2);
                    graph[j + n].add(i + n * 2);
                    in[i] = true;
                }
            }
        }

        bipartite();

        for (int i = 1; i <= n; i++) {
            if (right[i + n * 2] == 0) {
                answer++;
            }
        }

        System.out.println(answer);
    }
}