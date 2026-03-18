package main;

import java.io.*;
import java.util.*;

public class _14284 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static StringTokenizer st;
    public static int n, m, a, b, c, s, t;
    public static List<int[]>[] adj = new ArrayList[5_001];
    public static int[] dist = new int[5_001];

    public static int toInt(String s) {
        return Integer.parseInt(s);
    }

    public static void dijkstra() {
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparing(a -> a[0]));
        pq.add(new int[] {s, 0});
        dist[s] = 0;
        while (!pq.isEmpty()) {
            int[] node = pq.poll();

            int now = node[0];
            int d = node[1];

            if (d <= dist[now]) {
                for (int[] nextNode : adj[now]) {
                    int next = nextNode[0];
                    int dd = nextNode[1];

                    if (d + dd < dist[next]) {
                        dist[next] = d + dd;
                        pq.add(new int[] {next, dist[next]});
                    }
                }
            }
        }
        System.out.println(dist[t]);
    }

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());

        n = toInt(st.nextToken());
        m = toInt(st.nextToken());
        Arrays.fill(dist, Integer.MAX_VALUE);

        while (m-- > 0) {
            st = new StringTokenizer(br.readLine());

            a = toInt(st.nextToken());
            b = toInt(st.nextToken());
            c = toInt(st.nextToken());

            if (adj[a] == null) {
                adj[a] = new ArrayList<>();
            }
            adj[a].add(new int[]{b, c});

            if (adj[b] == null) {
                adj[b] = new ArrayList<>();
            }
            adj[b].add(new int[]{a, c});
        }

        st = new StringTokenizer(br.readLine());
        s = toInt(st.nextToken());
        t = toInt(st.nextToken());

        dijkstra();
    }
}