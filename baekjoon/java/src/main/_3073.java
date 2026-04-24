package main;

import java.io.*;
import java.util.*;

public class _3073 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static StringTokenizer st;
    public static final int INF = Integer.MAX_VALUE;
    public static int[] dist = new int[202];
    public static boolean[] inQ = new boolean[202];
    public static int[] idx = new int[202];
    public static int[] dfsVisited = new int[202];
    public static int n, m, childCount, homeCount = 100, source = 0, sink = 201, answer;
    public static Queue<int[]> children = new ArrayDeque<>();
    public static int[][][] visited = new int[101][100][100];
    public static int[][] arr = new int[100][100];
    public static int[] dy = new int[] {-1, 0, 0, 1};
    public static int[] dx = new int[] {0, -1, 1, 0};
    public static List<Node>[] graph = new ArrayList[202];
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

    public static void makeGraph() {
        int dollar = 1;
        while (!children.isEmpty()) {
            int size = children.size();
            while (size-- > 0) {
                int[] child = children.poll();

                int number = child[0];
                int y = child[1];
                int x = child[2];

                for (int i = 0; i < 4; i++) {
                    int ddy = y + dy[i];
                    int ddx = x + dx[i];

                    if (0 <= ddy && ddy < n && 0 <= ddx && ddx < m && visited[number][ddy][ddx] == 0) {
                        visited[number][ddy][ddx] = 1;
                        if (arr[ddy][ddx] > 0) {
                            addEdge(number, arr[ddy][ddx], 1, dollar);
                        }
                        children.add(new int[]{number, ddy, ddx});
                    }
                }
            }
            dollar++;
        }
    }

    public static boolean spfa() {
        Arrays.fill(dist, INF);
        Arrays.fill(inQ, false);

        dist[source] = 0;
        inQ[source] = true;

        Queue<Integer> q = new ArrayDeque<>();
        q.add(source);

        while (!q.isEmpty()) {
            int now = q.poll();
            inQ[now] = false;

            for (Node node : graph[now]) {
                int next = node.next;
                int capacity = node.capacity;
                int cost = node.cost;

                if (capacity > 0 && dist[now] + cost < dist[next]) {
                    dist[next] = dist[now] + cost;

                    if(!inQ[next]) {
                        inQ[next] = true;
                        q.add(next);
                    }
                }
            }
        }

        return dist[sink] != INF;
    }

    public static int dfs(int now, int flow) {
        dfsVisited[now] = 1;

        if (now == sink) {
            return flow;
        }

        for (; idx[now] < graph[now].size(); idx[now]++) {
            Node node = graph[now].get(idx[now]);

            int next = node.next;
            int capacity = node.capacity;
            int cost = node.cost;
            Node revNode = graph[next].get(node.revIdx);

            if (dfsVisited[next] == 0 && capacity > 0 && dist[now] + cost == dist[next]) {
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

    public static void init() {
        for (int i = 0; i <= 201; i++) {
            graph[i] = new ArrayList<>();
        }
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                for (int k = 0; k <= 100; k++) {
                    visited[k][i][j] = 0;
                }
                arr[i][j] = 0;
            }
        }
        children.clear();
        childCount = 0;
        homeCount = 100;
        answer = 0;
    }

    public static void main(String[] args) throws IOException {
        while (true) {
            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());

            if (n == 0 && m == 0) {
                break;
            }

            init();


            for (int i = 0; i < n; i++) {
                String line = br.readLine();

                for (int j = 0; j < m; j++) {
                    char ch = line.charAt(j);
                    if (ch == 'H') {
                        arr[i][j] = ++homeCount;
                        addEdge(homeCount, sink, 1, 0);
                    } else if (ch == 'm') {
                        children.add(new int[]{ ++childCount, i, j });
                        addEdge(source, childCount, 1, 0);
                    }
                }
            }

            makeGraph();

            while (spfa()) {
                Arrays.fill(idx, 0);

                while (true) {
                    Arrays.fill(dfsVisited, 0);

                    int flow = dfs(source, INF);

                    if (flow == 0) {
                        break;
                    }

                    answer += flow * dist[sink];
                }
            }

            bw.write(answer + "\n");
        }

        bw.flush();
    }
}