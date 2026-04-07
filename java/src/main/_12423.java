package main;

import java.io.*;
import java.util.*;

public class _12423 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static StringTokenizer st;
    public static final int INF = Integer.MAX_VALUE;
    public static int t, n, a, b, c, d, e, f, sink = 7, source = 0, answer;
    public static int[] dist = new int[8];
    public static boolean[] inQ = new boolean[8];
    public static int[] idx = new int[8];
    public static int[] visited = new int[8];
    public static List<Node>[] graph = new ArrayList[8];

    public static class Node {
        int next, capacity, cost, revIdx;

        public Node(int next, int capacity, int cost, int revIdx) {
            this.next = next;
            this.capacity = capacity;
            this.cost = cost;
            this.revIdx = revIdx;
        }
    }

    public static void main(String[] args) throws IOException {
        t = Integer.parseInt(br.readLine());
        for (int i = 1; i <= t; i++) {
            init();

            while (spfa()) {
                Arrays.fill(idx, 0);

                while (true) {
                    Arrays.fill(visited, 0);

                    int flow = dfs(0, INF);

                    if (flow == 0) {
                        break;
                    }

                    answer += flow * (-dist[sink]);
                }
            }

            bw.write("Case #" + i + ": " + answer + "\n");
        }
        bw.flush();
    }

    private static int dfs(int now, int flow) {
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

            if (visited[next] == 0 && capacity > 0 && dist[next] == dist[now] + cost) {
                int blockFlow = dfs(next, Math.min(flow, capacity));

                if (blockFlow > 0) {
                    node.capacity -= blockFlow;
                    revNode.capacity += blockFlow;

                    return blockFlow;
                }
            }
        }

        return 0;
    }

    private static boolean spfa() {
        Arrays.fill(dist, INF);
        Arrays.fill(inQ, false);

        Queue<Integer> q = new ArrayDeque<>();
        q.add(source);
        inQ[source] = true;
        dist[source] = 0;

        while (!q.isEmpty()) {
            int now = q.poll();
            inQ[now] = false;

            for (Node node : graph[now]) {
                int next = node.next;
                int capacity = node.capacity;
                int cost = node.cost;

                if (capacity > 0 && dist[now] + cost < dist[next]) {
                    dist[next] = dist[now] + cost;

                    if (!inQ[next]) {
                        inQ[next] = true;
                        q.add(next);
                    }
                }
            }
        }

        return dist[sink] != INF;
    }

    private static void addEdge(int now, int next, int capacity, int cost) {
        graph[now].add(new Node(next, capacity, cost, graph[next].size()));
        graph[next].add(new Node(now, 0, -cost, graph[now].size() - 1));
    }

    private static void init() throws IOException {
        answer = 0;
        for (int i = 0; i <= 7; i++) {
            graph[i] = new ArrayList<>();
        }

        st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        a = Integer.parseInt(st.nextToken());
        b = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        d = Integer.parseInt(st.nextToken());
        e = Integer.parseInt(st.nextToken());
        f = Integer.parseInt(st.nextToken());

        // source > 1, 2, 3
        addEdge(source, 1, a, 0);
        addEdge(source, 2, b, 0);
        addEdge(source, 3, c, 0);

        // 1, 2, 3 > 4, 5, 6
        st = new StringTokenizer(br.readLine());
        addEdge(1, 4, Math.min(a, d), -Integer.parseInt(st.nextToken()));
        addEdge(1, 5, Math.min(a, e), -Integer.parseInt(st.nextToken()));
        addEdge(1, 6, Math.min(a, f), -Integer.parseInt(st.nextToken()));

        st = new StringTokenizer(br.readLine());
        addEdge(2, 4, Math.min(b, d), -Integer.parseInt(st.nextToken()));
        addEdge(2, 5, Math.min(b, e), -Integer.parseInt(st.nextToken()));
        addEdge(2, 6, Math.min(b, f), -Integer.parseInt(st.nextToken()));

        st = new StringTokenizer(br.readLine());
        addEdge(3, 4, Math.min(c, d), -Integer.parseInt(st.nextToken()));
        addEdge(3, 5, Math.min(c, e), -Integer.parseInt(st.nextToken()));
        addEdge(3, 6, Math.min(c, f), -Integer.parseInt(st.nextToken()));

        // 4, 5, 6 > sink
        addEdge(4, sink, d, 0);
        addEdge(5, sink, e, 0);
        addEdge(6, sink, f, 0);
    }
}