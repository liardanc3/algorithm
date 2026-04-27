package main;

import java.io.*;
import java.util.*;

public class _2570 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static StringTokenizer st;
    public static final int INF = Integer.MAX_VALUE;
    public static int n, m, leftCount, rightCount, matching;
    public static int[][] arr = new int[101][101];
    public static int[][] leftLine = new int[101][101];
    public static int[][] rightLine = new int[101][101];
    public static int[][] visitedLeft = new int[101][101];
    public static int[][] visitedRight = new int[101][101];
    public static List<Integer>[] graph = new ArrayList[10001];
    public static int[] left = new int[10001];
    public static int[] right = new int[10001];
    public static int[] dist = new int[10001];

    public static void init() throws IOException {
        n = Integer.parseInt(br.readLine());
        m = Integer.parseInt(br.readLine());

        for (int i = 0; i < 10001; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());

            int y = Integer.parseInt(st.nextToken());
            int x = Integer.parseInt(st.nextToken());

            arr[y][x] = 1;
        }

        makeLeftLines();
        makeRightLines();
        makeGraph();
    }

    public static void makeLeftLines() {
        // 왼쪽위부터 우측아래로 대각선 긁어오기
        for (int y = 1; y <= n; y++) {
            for (int x = 1; x <= n; x++) {
                if (arr[y][x] == 1 || visitedLeft[y][x] == 1) {
                    continue;
                }

                leftCount++;

                int ddy = y;
                int ddx = x;

                while (ddy <= n && ddx <= n && arr[ddy][ddx] == 0) {
                    visitedLeft[ddy][ddx] = 1;
                    leftLine[ddy][ddx] = leftCount;
                    ddy++;
                    ddx++;
                }
            }
        }
    }

    public static void makeRightLines() {
        // 오른쪽위부터 왼쪽아래로 대각선 긁어오기
        for (int y = 1; y <= n; y++) {
            for (int x = n; x >= 1; x--) {
                if (arr[y][x] == 1 || visitedRight[y][x] == 1) {
                    continue;
                }

                rightCount++;

                int ddy = y;
                int ddx = x;

                while (ddy <= n && ddx >= 1 && arr[ddy][ddx] == 0) {
                    visitedRight[ddy][ddx] = 1;
                    rightLine[ddy][ddx] = rightCount;
                    ddy++;
                    ddx--;
                }
            }
        }
    }

    public static void makeGraph() {
        for (int y = 1; y <= n; y++) {
            for (int x = 1; x <= n; x++) {
                if (arr[y][x] == 1) {
                    continue;
                }

                graph[leftLine[y][x]].add(rightLine[y][x]);
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
        init();

        bw.write(bipartite() + "\n");
        bw.flush();
    }
}