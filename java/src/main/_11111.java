package main;

import java.io.*;
import java.util.*;

public class _11111 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static StringTokenizer st;
    public static int n, m, source = 0, sink = 5001, copy = 2500, INF = Integer.MAX_VALUE, result;
    public static int[][] priceArr = new int[][]{{10, 8, 7, 5, 1}, {8, 6, 4, 3, 1}, {7, 4, 3, 2, 1}, {5, 3, 2, 2, 1}, {1, 1, 1, 1, 0}};
    public static int[][] input = new int[50][50];
    public static int[] idx = new int[5002];
    public static int[] dist = new int[5002];
    public static int[] visited = new int[5002];
    public static int[] copyVisited = new int[5002];
    public static int[] inQ = new int[5002];
    public static List<Node>[] graph = new ArrayList[5002];

    public static class Node {
        int next, capacity, cost, revIdx;

        public Node(int next, int capacity, int cost, int revIdx) {
            this.next = next;
            this.capacity = capacity;
            this.cost = cost;
            this.revIdx = revIdx;
        }
    }

    public static void addEdge(int now, int next, int capacity, int cost) {
        graph[now].add(new Node(next, capacity, cost, graph[next].size()));
        graph[next].add(new Node(now, 0, -cost, graph[now].size() - 1));
    }

    public static void main(String[] args) throws Exception {
        init();
        makeGraph();
        mcmf();
        System.out.println(result);
    }

    public static void mcmf() {
        while (spfa()) {
            Arrays.fill(idx, 0);

            while (true) {
                Arrays.fill(visited, 0);

                int flow = dfs(source, INF);

                if (flow == 0) {
                    break;
                }
                if (dist[sink] < 0) {
                    break;
                }

                result += dist[sink] * flow;
            }
        }
    }

    public static int dfs(int now, int flow) {
        visited[now] = 1;

        if (now == sink) {
            return flow;
        }

        for (; idx[now] < graph[now].size(); idx[now]++) {
            Node node = graph[now].get(idx[now]);

            int next = node.next;
            int capacity = node.capacity;
            int cost = node.cost;
            Node revNode = graph[next].get(node.revIdx);

            if (visited[next] == 0 && capacity > 0 && dist[now] + cost == dist[next]) {
                int blockFlow = dfs(next, Math.min(capacity, flow));

                if (blockFlow > 0) {
                    node.capacity -= blockFlow;
                    revNode.capacity += blockFlow;

                    return blockFlow;
                }
            }
        }

        return 0;
    }

    public static boolean spfa() {
        Arrays.fill(dist, INF);
        Arrays.fill(inQ, 0);

        Queue<Integer> q = new ArrayDeque<>();
        q.add(source);
        dist[source] = 0;
        inQ[source] = 1;

        while (!q.isEmpty()) {
            int now = q.poll();
            inQ[now] = 0;

            for (Node node : graph[now]) {
                int next = node.next;
                int capacity = node.capacity;
                int cost = node.cost;

                if (capacity > 0 && (dist[now] + cost > dist[next] || dist[next] == INF)) {
                    dist[next] = dist[now] + cost;

                    if (inQ[next] == 0) {
                        inQ[next] = 1;
                        q.add(next);
                    }
                }
            }
        }

        return dist[sink] != INF;
    }

    public static void makeGraph() {
        // 짝수 줄 = 짝수 번호 left
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i % 2 == j % 2) {
                    int now = (j + 1) + (i * m);
                    addEdge(source, now, 1, 0);

                    int left = now - 1;
                    if (j - 1 >= 0) {
                        int price = priceArr[input[i][j]][input[i][j - 1]];

                        addEdge(now, left, 1, price);
                        if (copyVisited[left] == 0) {
                            copyVisited[left] = 1;
                            addEdge(left, left + copy, 1, 0);
                            addEdge(left + copy, sink, 1, 0);
                        }
                    }

                    int right = now + 1;
                    if (j + 1 < m) {
                        int price = priceArr[input[i][j]][input[i][j + 1]];

                        addEdge(now, right, 1, price);
                        if (copyVisited[right] == 0) {
                            copyVisited[right] = 1;
                            addEdge(right, right + copy, 1, 0);
                            addEdge(right + copy, sink, 1, 0);
                        }
                    }

                    int top = now - m;
                    if (i - 1 >= 0) {
                        int price = priceArr[input[i][j]][input[i - 1][j]];

                        addEdge(now, top, 1, price);
                        if (copyVisited[top] == 0) {
                            copyVisited[top] = 1;
                            addEdge(top, top + copy, 1, 0);
                            addEdge(top + copy, sink, 1, 0);
                        }
                    }

                    int bottom = now + m;
                    if (i + 1 < n) {
                        int price = priceArr[input[i][j]][input[i + 1][j]];

                        addEdge(now, bottom, 1, price);
                        if (copyVisited[bottom] == 0) {
                            copyVisited[bottom] = 1;
                            addEdge(bottom, bottom + copy, 1, 0);
                            addEdge(bottom + copy, sink, 1, 0);
                        }
                    }
                }
            }
        }
    }

    public static void init() throws IOException {
        for (int i = 0; i <= 5001; i++) {
            graph[i] = new ArrayList<>();
        }
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        for (int i = 0; i < n; i++) {
            String line = br.readLine();
            for (int j = 0; j < m; j++) {
                input[i][j] = Math.min(4, (line.charAt(j) - 'A'));
            }
        }
    }

}