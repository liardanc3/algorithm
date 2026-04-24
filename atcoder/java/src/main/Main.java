package main;

import java.io.*;
import java.util.*;

public class Main {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static StringTokenizer st;
    public static int T, n, m, source = 0, sink = 401, INF = 1_000_000_000, count, result;
    public static int[] dist = new int[402];
    public static int[] inQ = new int[402];
    public static Node[] path = new Node[402];
    public static List<Node>[] graph = new ArrayList[402];
    public static Line[] hArr = new Line[201];
    public static Line[] vArr = new Line[201];

    public static class Line {
        int x1, y1, x2, y2, w;

        public Line(int x1, int y1, int x2, int y2, int w) {
            this.x1 = x1;
            this.y1 = y1;
            this.x2 = x2;
            this.y2 = y2;
            this.w = w;
        }
    }

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
        for (int i = 0; i < 402; i++) {
            graph[i] = new ArrayList<>();
        }

        T = Integer.parseInt(br.readLine());

        while (T-- > 0) {
            init();
            makeGraph();
            mcmf();

            sb.append(count).append(" ").append(result).append("\n");
        }

        System.out.print(sb);
    }

    public static void init() throws Exception {
        for (int i = 0; i < 402; i++) {
            graph[i].clear();
        }

        st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        count = 0;
        result = 0;

        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());

            int x1 = Integer.parseInt(st.nextToken());
            int y1 = Integer.parseInt(st.nextToken());
            int x2 = Integer.parseInt(st.nextToken());
            int y2 = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());

            if (x1 > x2) {
                int temp = x1;
                x1 = x2;
                x2 = temp;
            }

            hArr[i] = new Line(x1, y1, x2, y2, w);
        }

        for (int i = 1; i <= m; i++) {
            st = new StringTokenizer(br.readLine());

            int x1 = Integer.parseInt(st.nextToken());
            int y1 = Integer.parseInt(st.nextToken());
            int x2 = Integer.parseInt(st.nextToken());
            int y2 = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());

            if (y1 > y2) {
                int temp = y1;
                y1 = y2;
                y2 = temp;
            }

            vArr[i] = new Line(x1, y1, x2, y2, w);
        }
    }

    public static void makeGraph() {
        for (int i = 1; i <= n; i++) {
            addEdge(source, i, 1, 0);
        }

        for (int i = 1; i <= m; i++) {
            addEdge(n + i, sink, 1, 0);
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (isCross(hArr[i], vArr[j])) {
                    addEdge(i, n + j, 1, hArr[i].w * vArr[j].w);
                }
            }
        }
    }

    public static boolean isCross(Line h, Line v) {
        return h.x1 < v.x1 && v.x1 < h.x2 && v.y1 < h.y1 && h.y1 < v.y2;
    }

    public static void addEdge(int now, int next, int capacity, int cost) {
        graph[now].add(new Node(next, capacity, cost, graph[next].size()));
        graph[next].add(new Node(now, 0, -cost, graph[now].size() - 1));
    }

    public static void mcmf() {
        while (spfa()) {
            int flow = INF;

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
                    dist[now] = dist[next] + cost;
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