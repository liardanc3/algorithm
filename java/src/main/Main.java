package main;

import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static StringBuilder sb = new StringBuilder();
    public static String input;
    public static List<Integer>[] adj = new ArrayList[250_001];
    public static int[][] parent = new int[20][250_001];
    public static int[] visited = new int[250_001];
    public static int[] depth = new int[250_001];
    public static int n, x, y, q, i, j, k, l, c;

    public static void dfs(int d, int now) {
        visited[now] = 1;
        depth[now] = d;

        for (int next : adj[now]) {
            if (visited[next] != 1) {
                parent[0][next] = now;
                dfs(d + 1, next);
            }
        }
    }

    public static void setParent() {
        for (int i = 1; i <= 19; i++) {
            for (int j = 1; j <= n; j++) {
                parent[i][j] = parent[i - 1][parent[i - 1][j]];
            }
        }
    }

    public static int lca(int a, int b) {
        if (depth[a] < depth[b]) {
            int tmp = b;
            b = a;
            a = tmp;
        }

        for (int i = 19; i >= 0; i--) {
            if (depth[a] - depth[b] >= (1 << i)) {
                a = parent[i][a];
            }
        }

        if (a == b) {
            return a;
        }

        for (int i = 19; i >= 0; i--) {
            if (parent[i][a] != parent[i][b]) {
                a = parent[i][a];
                b = parent[i][b];
            }
        }

        return parent[0][a];
    }

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());

        for (int i = 0; i < n - 1; i++) {
            StringTokenizer token = new StringTokenizer(br.readLine());
            x = Integer.parseInt(token.nextToken());
            y = Integer.parseInt(token.nextToken());

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

        q = Integer.parseInt(br.readLine());
        while (q-- > 0) {
            StringTokenizer token = new StringTokenizer(br.readLine());

            c = Integer.parseInt(token.nextToken());
            i = Integer.parseInt(token.nextToken());
            j = Integer.parseInt(token.nextToken());
            k = Integer.parseInt(token.nextToken());

            if (c == 1) {
                int distIJ = depth[i] + depth[j] - 2 * depth[lca(i, j)];
                int distIK = depth[i] + depth[k] - 2 * depth[lca(i, k)];
                int distJK = depth[j] + depth[k] - 2 * depth[lca(j, k)];

                bw.write(distIJ == distIK + distJK ? "NO\n" : "YES\n");
            } else {
                l = Integer.parseInt(token.nextToken());
                if (depth[l] < depth[k]) {
                    int tmp = l;
                    l = k;
                    k = tmp;
                }

                int lcaIL = lca(i, l);
                int lcaJL = lca(j, l);

                bw.write((lcaIL == l && lcaJL == l) || (lcaIL != l && lcaJL != l) ? "YES\n" : "NO\n");
            }
        }

        bw.flush();
    }
}