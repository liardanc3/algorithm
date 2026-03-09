package main;

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static int N, Q, a, b, c;
    public static List<Integer>[] adj = new ArrayList[100_001];
    public static int[] depth = new int[100_001];
    public static int[] visited = new int[100_001];
    public static int[][] parent = new int[18][100_001];

    public static void dfs(int d, int now) {
        visited[now] = 1;
        depth[now] = d;

        if (adj[now] != null) {
            for (Integer next : adj[now]) {
                if (visited[next] != 1) {
                    parent[0][next] = now;
                    dfs(d + 1, next);
                }
            }
        }
    }

    public static void setParent() {
        for (int i = 1; i <= 17; i++) {
            for (int j = 1; j <= 100_000; j++) {
                parent[i][j] = parent[i - 1][parent[i - 1][j]];
            }
        }
    }

    public static int lca(int x, int y) {
        if (depth[x] < depth[y]) {
            int tmp = y;
            y = x;
            x = tmp;
        }

        for (int i = 17; i >= 0; i--) {
            if (depth[x] - depth[y] >= (1 << i)) {
                x = parent[i][x];
            }
        }

        if (x == y) {
            return x;
        }

        for (int i = 17; i >= 0; i--) {
            if (parent[i][x] != parent[i][y]) {
                x = parent[i][x];
                y = parent[i][y];
            }
        }

        return parent[0][x];
    }

    public static int dist(int src, int dst) {
        return depth[src] + depth[dst] - 2 * depth[lca(src, dst)];
    }

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        for (int i = 0; i < N - 1; i++) {
            StringTokenizer input = new StringTokenizer(br.readLine());

            int x = Integer.parseInt(input.nextToken());
            int y = Integer.parseInt(input.nextToken());

            if (adj[x] == null) {
                adj[x] = new ArrayList<>();
            }
            adj[x].add(y);

            if (adj[y] == null) {
                adj[y] = new ArrayList<>();
            }
            adj[y].add(x);
        }

        dfs(0, 1);
        setParent();

        Q = Integer.parseInt(br.readLine());
        while (Q-- > 0) {
            StringTokenizer input = new StringTokenizer(br.readLine());

            a = Integer.parseInt(input.nextToken());
            b = Integer.parseInt(input.nextToken());
            c = Integer.parseInt(input.nextToken());

            int aa, bb, cc;

            int distAB = dist(a, b);
            int distAC = dist(a, c);
            int distBC = dist(b, c);

            if (distAB >= distAC && distAB >= distBC) {
                aa = a; bb = b; cc = c;
            } else if (distAC >= distAB && distAC >= distBC) {
                aa = a; bb = c; cc = b;
            } else {
                aa = b; bb = c; cc = a;
            }

            if (distAB % 2 == 1 || distAC % 2 == 1 || distBC % 2 == 1) {
                bw.write("-1\n");
                continue;
            }

            int diff = dist(aa, bb) / 2;
            int center = depth[aa] < depth[bb] ? bb : aa;
            for (int i = 17; i >= 0; i--) {
                if (diff >= (1 << i)) {
                    center = parent[i][center];
                    diff -= (1 << i);
                }
            }

            int distAA = dist(aa, center);
            int distBB = dist(bb, center);
            int distCC = dist(cc, center);

            if (distAA == distBB && distAA == distCC) {
                bw.write(center + "\n");
            } else {
                bw.write("-1\n");
            }
        }
        bw.flush();
    }
}