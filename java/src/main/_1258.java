package main;

import java.io.*;
import java.util.*;

public class _1258 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static StringTokenizer st;
    public static int n, source, sink, minCost;
    public static final int INF = Integer.MAX_VALUE;
    public static List<Node>[] graph = new ArrayList[202];
    public static int[] dist = new int[202];
    public static boolean[] inQ = new boolean[202];
    public static int[] idx = new int[202];
    public static int[] visited = new int[202];

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

    static boolean spfa() {
        Arrays.fill(dist, INF);
        Arrays.fill(inQ, false);

        dist[source] = 0;
        inQ[source] = true;

        Queue<Integer> q = new ArrayDeque<>();
        q.add(source);

        while(!q.isEmpty()) {
            int now = q.poll();
            inQ[now] = false;

            for (Node node : graph[now]) {
                int next = node.next;
                int capacity = node.capacity;
                int cost = node.cost;

                if (capacity > 0 && dist[next] > dist[now] + cost) {
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

    public static int dfs(int now, int flow) {
        visited[now] = 1;

        if (now == sink) {
            return flow;
        }

        for(; idx[now] < graph[now].size(); idx[now]++) {
            Node node = graph[now].get(idx[now]);

            int next = node.next;
            int cost = node.cost;

            Node revNode = graph[next].get(node.revIdx);

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

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());

        source = 0;
        n = Integer.parseInt(st.nextToken());
        sink = n + n + 1;
        for (int i = source; i <= sink; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());

            addEdge(source, i, 1, 0);
            for (int j = 1 + n; j <= n + n; j++) {
                int cost = Integer.parseInt(st.nextToken());

                addEdge(i, j, 1, cost);
            }
        }

        for (int i = n + 1; i <= sink; i++) {
            addEdge(i, sink, 1, 0);
        }

        while(spfa()) {
            Arrays.fill(idx, 0);

            while (true) {
                Arrays.fill(visited, 0);

                int flow = dfs(0, INF);

                if (flow == 0) {
                    break;
                }

                minCost += flow * dist[sink];
            }
        }

        System.out.println(minCost);
    }
}