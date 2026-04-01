package main;

import java.io.*;
import java.util.*;

public class _1585 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static StringTokenizer st;
    public static int n, t, f, source = 0, sink, mn, mx, minFlow;
    public static final int INF = Integer.MAX_VALUE;
    public static List<Node>[] graph = new ArrayList[102];
    public static int[] w = new int[101];
    public static int[] dist = new int[102];
    public static int[] visited = new int[102];
    public static int[] idx = new int[102];
    public static boolean[] inQ = new boolean[102];

    public static class Node {
        int next, capacity, cost, revIdx;

        public Node(int next, int capacity, int cost, int revIdx) {
            this.next = next;
            this.capacity = capacity;
            this.cost = cost;
            this.revIdx = revIdx;
        }
    }

    public static boolean spfa(boolean isMn) {
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

                boolean condition = isMn ? (dist[now] + cost < dist[next]) : (dist[next] == INF || dist[now] + cost > dist[next]);
                if (capacity > 0 && condition && next != 0) {
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

    public static void addEdge(int now, int next, int capacity, int cost) {
        graph[now].add(new Node(next, capacity, cost, graph[next].size()));
        graph[next].add(new Node(now, 0, -cost, graph[now].size() - 1));
    }

    public static int dfs(int now, int flow) {
        visited[now] = 1;

        if (now == sink) {
            return flow;
        }

        for (; idx[now] < graph[now].size(); idx[now]++) {
            Node node = graph[now].get(idx[now]);

            int next = node.next;
            int cost = node.cost;
            int revIdx = node.revIdx;

            Node revNode = graph[next].get(revIdx);

            if (visited[next] == 0 && node.capacity > 0 && dist[now] + cost == dist[next]) {
                int blockFlow = dfs(next, Math.min(node.capacity, flow));

                if (blockFlow > 0) {
                    node.capacity -= blockFlow;
                    revNode.capacity += blockFlow;

                    return blockFlow;
                }
            }
        }

        return 0;
    }

    public static void clear() {
        for (int i = source; i <= sink; i++) {
            graph[i] = new ArrayList<>();
        }
        for (int i = 1; i <= n; i++) {
            addEdge(source, i, 1, 0);
            for (int j = n + 1; j <= 2 * n; j++) {
                if (w[i] < w[j]) {
                    if (f > (w[j] - w[i])) {
                        addEdge(i, j, 1, Math.min(t,(f - w[j] + w[i]) * (f - w[j] + w[i])));
                    } else {
                        addEdge(i, j, 1, 0);
                    }
                }
            }
            addEdge(i + n, sink, 1, 0);
        }
    }
    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        sink = 2 * n + 1;

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) {
            w[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for (int i = n + 1; i <= 2 * n; i++) {
            w[i] = Integer.parseInt(st.nextToken());
        }
        f = Integer.parseInt(br.readLine());
        t = Integer.parseInt(br.readLine());

        clear();
        while (spfa(true)) {
            Arrays.fill(idx, 0);

            while (true) {
                Arrays.fill(visited, 0);

                int flow = dfs(0, INF);

                if (flow == 0) {
                    break;
                }

                mn += flow * dist[sink];
                minFlow++;
            }
        }

        if (minFlow != n) {
            System.out.println("-1");
            System.exit(0);
        }

        clear();
        while (spfa(false)) {
            Arrays.fill(idx, 0);

            while (true) {
                Arrays.fill(visited, 0);

                int flow = dfs(0, INF);

                if (flow == 0) {
                    break;
                }

                mx += flow * dist[sink];
            }
        }

        System.out.println(mn + " " + mx);
    }
}