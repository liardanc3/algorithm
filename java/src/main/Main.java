import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static StringBuilder sb = new StringBuilder();
    public static String input, answer;
    public static int T, N, A, B, L, R;
    public static int[][][] adj = new int[2][2][200_001];
    public static int[][] parent = new int[19][200_001];
    public static int[] depth = new int[200_001];
    public static int[] visited = new int[200_001];

    public static void setParent() {
        for (int i = 1; i <= 18; i++) {
            for (int j = 1; j <= N; j++) {
                parent[i][j] = parent[i - 1][parent[i - 1][j]];
            }
        }
    }

    public static void dfs(int d, int now) {
        visited[now] = 1;
        depth[now] = d;

        int left = adj[0][0][now];
        int right = adj[0][1][now];

        if (left != 0 && visited[left] == 0) {
            parent[0][left] = now;
            dfs(d + 1, left);
        }
        if (right != 0 && visited[right] == 0) {
            parent[0][right] = now;
            dfs(d + 1, right);
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

        T = Integer.parseInt(br.readLine());

        while (T-- > 0) {
            for (int i = 0; i <= N; i++) {
                visited[i] = 0;
                depth[i] = 0;
                adj[0][0][i] = 0;
                adj[0][1][i] = 0;
                adj[1][0][i] = 0;
                adj[1][1][i] = 0;
                for (int j = 0; j <= 18; j++) {
                    parent[j][i] = 0;
                }
            }

            N = Integer.parseInt(br.readLine());

            StringTokenizer ip = new StringTokenizer(br.readLine());

            A = Integer.parseInt(ip.nextToken());
            B = Integer.parseInt(ip.nextToken());

            for (int i = 1; i <= N; i++) {
                input = br.readLine();
                StringTokenizer token = new StringTokenizer(input);

                L = Integer.parseInt(token.nextToken());
                R = Integer.parseInt(token.nextToken());

                adj[0][0][i] = L;
                adj[0][1][i] = R;
                adj[1][0][L] = i;
                adj[1][1][R] = i;

                parent[0][L] = i;
                parent[0][R] = i;
            }

            dfs(0, 1);

            if ((depth[A] + depth[B] - 2 * depth[lca(A, B)]) % 2 == 1) {
                bw.write("ERROR\n");
            } else {
                setParent();

                int lca = lca(A, B);
                int diff = (depth[A] - depth[B]) / 2;

                // B 최소갯수(시작하는애가 lca 까지 도달하는 길이)
                int len = Math.min(depth[A] - depth[lca], depth[B] - depth[lca]);

                // 성공여부
                boolean isSuccess = false;

                // B에서 위로 len 만큼 갈수있어야함(root 위로 뚫지않음)
                for (int i = len; i <= depth[A] && !isSuccess; i++) {

                    // up = B, down = (LR)
                    int up = i;
                    int down = up - diff;

                    StringBuilder result = new StringBuilder();
                    int dst = B;
                    while (down-- > 0 && dst != 0) {
                        if (adj[1][0][dst] != 0) {
                            result.append("L");
                        } else {
                            result.append("R");
                        }

                        dst = parent[0][dst];
                    }
                    result.reverse();

                    // 길이 있으면 A부터 dst 까지 result 경로 검사
                    if (dst != 0) {

                        int start = A;
                        boolean isPossible = true;

                        // 처음 B
                        for (int j = 18; j >= 0 && isPossible; j--) {
                            if (up >= (1 << j)) {
                                start = parent[j][start];
                                up -= (1 << j);
                            }
                            if (start == 0) {
                                isPossible = false;
                            }
                        }
                        // LRLR (?까지)
                        for (int j = 0; j < result.length() && isPossible; j++) {
                            char c = result.charAt(j);

                            if (c == 'L') {
                                start = adj[0][0][start];
                            } else if (c == 'R') {
                                start = adj[0][1][start];
                            } else {
                                assert(true);
                            }

                            if (start == 0) {
                                isPossible = false;
                            }
                        }

                        // ? 부터 dst까지
                        up = i;
                        for (int j = 18; j >= 0 && isPossible; j--) {
                            if (up >= (1 << j)) {
                                start = parent[j][start];
                                up -= (1 << j);
                            }
                            if (start == 0) {
                                isPossible = false;
                            }
                        }

                        // A부터 dst까지 도달성공
                        if (isPossible && start == dst) {
                            bw.write("B".repeat(i) + result + "\n");
                            isSuccess = true;
                        }
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