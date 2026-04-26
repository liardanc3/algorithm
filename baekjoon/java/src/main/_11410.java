package main;

import java.io.*;
import java.util.*;

public class _11410 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringTokenizer st;
    public static int n, p, source = 1, sink = 50, INF = 1231231231, result, count;
    public static int[][] amount = new int[51][51];
    public static int[][] cost = new int[51][51];
    public static int[] dist = new int[51];
    public static int[] inQ = new int[51];
    public static Node[] path = new Node[51];
    public static List<Node>[] graph = new ArrayList[51];

    public static class Node {
        int next, capacity, cost, revIdx;

        public Node(int next, int capacity, int cost, int revIdx) {
            this.next = next;
            this.capacity = capacity;
            this.cost = cost;
            this.revIdx = revIdx;
        }
    }

    public static void main(String[] args) throws Exception {
        for (int i = 0; i < 51; i++) {
            graph[i] = new ArrayList<>();
        }

        init();
        makeGraph();
        mcmf();

        System.out.println(result);
    }

    public static void init() throws Exception {
        st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        p = Integer.parseInt(st.nextToken());

        for (int i = 1; i <= n - 1; i++) {
            st = new StringTokenizer(br.readLine());

            for (int j = i + 1; j <= n; j++) {
                amount[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for (int i = 1; i <= n - 1; i++) {
            st = new StringTokenizer(br.readLine());

            for (int j = i + 1; j <= n; j++) {
                cost[i][j] = Integer.parseInt(st.nextToken());
            }
        }
    }

    public static void makeGraph() {
        for (int i = 1; i < 50; i++) {
            addEdge(i, i + 1, p, 0);
        }

        for (int i = 1; i <= n - 1; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (amount[i][j] > 0) {
                    addEdge(i, j, amount[i][j], cost[i][j]);
                }
            }
        }
    }

    public static void addEdge(int now, int next, int capacity, int cost) {
        graph[now].add(new Node(next, capacity, cost, graph[next].size()));
        graph[next].add(new Node(now, 0, -cost, graph[now].size() - 1));
    }

    public static void mcmf() {
        while (count < p && spfa()) {
            int flow = p - count;

            for (int i = sink; i != source; ) {
                Node node = path[i];
                Node revNode = graph[node.next].get(node.revIdx);

                flow = Math.min(flow, node.capacity);
                i = revNode.next;
            }

            for (int i = sink; i != source; ) {
                Node node = path[i];
                Node revNode = graph[node.next].get(node.revIdx);

                node.capacity -= flow;
                revNode.capacity += flow;

                i = revNode.next;
            }

            count += flow;
            result += dist[sink] * flow;
        }
    }

    public static boolean spfa() {
        Arrays.fill(dist, -INF);
        Arrays.fill(inQ, 0);
        Arrays.fill(path, null);

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

                if (capacity > 0 && dist[next] < dist[now] + cost) {
                    dist[next] = dist[now] + cost;
                    path[next] = node;

                    if (inQ[next] == 0) {
                        inQ[next] = 1;
                        q.add(next);
                    }
                }
            }
        }

        return path[sink] != null;
    }

}