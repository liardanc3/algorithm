package main;

import java.io.*;
import java.util.*;

public class _11014 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static StringTokenizer st;
    public static int c, n, m, total, leftCount, rightCount, matching;
    public static final int INF = Integer.MAX_VALUE;
    public static char[][] map = new char[81][81];
    public static int[][] idx = new int[81][81];
    public static List<Integer>[] graph = new ArrayList[6401];
    public static int[] left = new int[6401];
    public static int[] right = new int[6401];
    public static int[] dist = new int[6401];
    public static int[] dy = {-1, 0, 1, -1, 0, 1};
    public static int[] dx = {-1, -1, -1, 1, 1, 1};

    public static void init() throws IOException {
        for (int i = 0; i <= 6400; i++) {
            graph[i] = new ArrayList<>();
        }
        st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        total = 0;
        leftCount = 0;
        rightCount = 0;
        matching = 0;

        Arrays.fill(left, 0);
        Arrays.fill(right, 0);
        Arrays.fill(dist, 0);

        for (int i = 0; i < n; i++) {
            Arrays.fill(idx[i], 0);

            String line = br.readLine();

            for (int j = 0; j < m; j++) {
                map[i][j] = line.charAt(j);

                if (map[i][j] == 'x') {
                    continue;
                }

                total++;

                if (j % 2 == 0) {
                    idx[i][j] = ++leftCount;
                } else {
                    idx[i][j] = ++rightCount;
                }
            }
        }

        makeGraph();
    }

    public static void makeGraph() {
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if (map[y][x] == 'x' || x % 2 == 1) {
                    continue;
                }

                int now = idx[y][x];

                for (int d = 0; d < 6; d++) {
                    int ny = y + dy[d];
                    int nx = x + dx[d];

                    if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
                        continue;
                    }

                    if (map[ny][nx] == 'x') {
                        continue;
                    }

                    graph[now].add(idx[ny][nx]);
                }
            }
        }
    }

    public static boolean hasAugmentPathEnd() {
        Queue<Integer> q = new ArrayDeque<>();

        for (int l = 1; l <= leftCount; l++) {
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
            for (int l = 1; l <= leftCount; l++) {
                if (left[l] == 0 && connectedAugmentPathEnd(l)) {
                    matching++;
                }
            }
        }

        return matching;
    }

    public static void main(String[] args) throws IOException {
        c = Integer.parseInt(br.readLine());

        for (int i = 0; i <= 6400; i++) {
            graph[i] = new ArrayList<>();
        }

        while (c-- > 0) {
            init();
            bw.write(total - bipartite() + "\n");
        }

        bw.flush();
    }
}