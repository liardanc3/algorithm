package main;

import java.io.*;
import java.util.*;

public class Main {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static StringBuilder sb = new StringBuilder();
    public static String input;
    public static int T, N, A, B, L, R;
    public static int[][] adj = new int[2][200_001];
    public static int[][] parent = new int[19][200_001];
    public static int[] depth = new int[200_001];
    public static int[] visited = new int[200_001];
    public static long[] path = new long[200_001];
    public static long[] pow = new long[200_001];
    public static long base = 1234567891L;
    public static long mod = (long) 1e9;
    public static Map<Long, Integer> path2Node = new HashMap<>();

    public static void setParent() {
        for (int i = 1; i <= 18; i++) {
            for (int j = 1; j <= N; j++) {
                parent[i][j] = parent[i - 1][parent[i - 1][j]];
            }
        }
    }

    public static void bfs() {
        Queue<Integer> q = new ArrayDeque<>();
        q.add(1);
        visited[1] = 1;
        depth[1] = 0;
        int d = 1;

        while (!q.isEmpty()) {
            int size = q.size();

            while (size-- > 0) {
                int now = q.poll();

                int left = adj[0][now];
                if (left != 0) {
                    parent[0][left] = now;
                    depth[left] = d;
                    path[left] = (path[now] * base + 1) % mod;
                    path2Node.put(path[left], left);
                    q.add(left);
                }

                int right = adj[1][now];
                if (right != 0) {
                    parent[0][right] = now;
                    depth[right] = d;
                    path[right] = (path[now] * base + 2) % mod;
                    path2Node.put(path[right], right);
                    q.add(right);
                }
            }

            d++;
        }
    }

    public static int lca(int a, int b) {
        if (depth[a] < depth[b]) {
            int tmp = b;
            b = a;
            a = tmp;
        }

        for (int i = 18; i >= 0; i--) {
            if (depth[a] - depth[b] >= (1 << i)) {
                a = parent[i][a];
            }
        }

        if (a == b) {
            return a;
        }

        for (int i = 18; i >= 0; i--) {
            if (parent[i][a] != parent[i][b]) {
                a = parent[i][a];
                b = parent[i][b];
            }
        }

        return parent[0][a];
    }

    public static void main(String[] args) throws IOException {
        pow[0] = 1L;
        for (int i = 1; i < 200_001; i++) {
            pow[i] = (pow[i - 1] * base) % mod;
        }

        T = Integer.parseInt(br.readLine());
        //assert 1 <= T;

        while (T-- > 0) {
            for (int i = 0; i <= N; i++) {
                path[i] = 0;
                visited[i] = 0;
                depth[i] = 0;
                adj[0][i] = 0;
                adj[1][i] = 0;
                for (int j = 0; j <= 18; j++) {
                    parent[j][i] = 0;
                }
            }
            path2Node.clear();

            N = Integer.parseInt(br.readLine());

            StringTokenizer ip = new StringTokenizer(br.readLine());

            A = Integer.parseInt(ip.nextToken());
            B = Integer.parseInt(ip.nextToken());

            for (int i = 1; i <= N; i++) {
                input = br.readLine();
                StringTokenizer token = new StringTokenizer(input);

                L = Integer.parseInt(token.nextToken());
                R = Integer.parseInt(token.nextToken());

                adj[0][i] = L;
                adj[1][i] = R;

                if (L != 0) {
                    parent[0][L] = i;
                }
                if (R != 0) {
                    parent[0][R] = i;
                }
            }

            bfs();
            setParent();

            int lca = lca(A, B);

            if ((depth[A] + depth[B] - 2 * depth[lca]) % 2 == 1) {
                bw.write("ERROR\n");
            } else {
                int diff = (depth[A] - depth[B]) / 2;

                // up 최소갯수(제일짧은 up)
                int len = Math.min(depth[A] - depth[lca], depth[B] - depth[lca]);

                // 성공여부
                boolean isSuccess = false;

                // B에서 위로 len 만큼 갈수있어야함(root 위로 뚫지않음)
                for (int i = len; i <= depth[A]; i++) {

                    // up = B, down = (LR)
                    int up = i;
                    int down = up - diff;

                    // [A > start > X > dstTmp > B]

                    // [dstTmp > B] B부터 dstTmp 까지 올려서(down) 확인
                    int downTmp = down;
                    int dstTmp = B;
                    for (int j = 18; j >= 0; j--) {
                        if (downTmp >= (1 << j)) {
                            dstTmp = parent[j][dstTmp];
                            downTmp -= (1 << j);
                        }
                    }
                    if (dstTmp == 0) {
                        continue;
                    }

                    // [A > start] A부터 start 까지 올려서(up) 확인
                    int start = A;
                    boolean isPossible = true;
                    for (int j = 18; j >= 0 && isPossible; j--) {
                        if (up >= (1 << j)) {
                            start = parent[j][start];
                            up -= (1 << j);
                        }
                        if (start == 0) {
                            isPossible = false;
                        }
                    }

                    // [start > X] 문자열이 dstTmp > B랑 같은지 확인
                    long dstTmp2B;
                    Integer x;
                    long root2DstTmp = path[dstTmp];
                    long root2B = path[B];
                    int diffDepth = depth[B] - depth[dstTmp];

                    dstTmp2B = (root2B - (root2DstTmp * pow[diffDepth]) % mod + mod) % mod;

                    long root2Start = path[start];
                    long start2X = dstTmp2B;
                    long root2X = (root2Start * pow[diffDepth] % mod + start2X) % mod;

                    x = path2Node.get(root2X);
                    if (x == null) {
                        continue;
                    }

                    // [X > dstTmp] 도달가능한지 확인
                    up = i;
                    for (int j = 18; j >= 0 && isPossible; j--) {
                        if (up >= (1 << j)) {
                            x = parent[j][x];
                            up -= (1 << j);
                        }
                        if (x == 0) {
                            isPossible = false;
                        }
                    }

                    // 성공
                    if (x == dstTmp) {
                        StringBuilder result = new StringBuilder();
                        int src = B;
                        int dst = dstTmp;
                        while (src != dst) {
                            int head = parent[0][src];

                            if (adj[0][head] == src) {
                                result.append("L");
                            } else {
                                result.append("R");
                            }
                            src = head;
                        }
                        result.reverse();

                        bw.write("B".repeat(i) + result + "\n");
                        isSuccess = true;
                        break;
                    }
                }

                if (!isSuccess) {
                    bw.write("ERROR\n");
                }
            }
        }

        bw.flush();
    }
}