package main;

import java.io.*;
import java.util.*;

public class _17835 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static StringTokenizer st;
    public static int n, m, k, u, v, c, dst;
    public static long mx;
    public static List<Integer> list = new ArrayList<>();
    public static List<long[]>[] adj = new ArrayList[100_001];
    public static long[] dist = new long[100_001];

    public static int toInt(String s) {
        return Integer.parseInt(s);
    }

    public static void dijkstra() {
        PriorityQueue<long[]> pq = new PriorityQueue<>(Comparator.comparing(a -> a[1]));
        Arrays.fill(dist, Long.MAX_VALUE);
        for (Integer src : list) {
            pq.add(new long[]{src, 0});
            dist[src] = 0;
        }

        while (!pq.isEmpty()) {
            long[] node = pq.poll();

            int now = (int) node[0];
            long d = node[1];

            if (d <= dist[now] && adj[now] != null) {
                for (long[] nextNode : adj[now]) {
                    int next = (int) nextNode[0];
                    long dd = nextNode[1];

                    if (d + dd < dist[next]) {
                        dist[next] = d + dd;
                        pq.add(new long[]{next, dist[next]});
                    }
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            if (dist[i] > mx) {
                mx = dist[i];
                dst = i;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());

        n = toInt(st.nextToken());
        m = toInt(st.nextToken());
        k = toInt(st.nextToken());

        while (m-- > 0) {
            st = new StringTokenizer(br.readLine());

            u = toInt(st.nextToken());
            v = toInt(st.nextToken());
            c = toInt(st.nextToken());

            if (adj[v] == null) {
                adj[v] = new ArrayList<>();
            }
            adj[v].add(new long[]{u, c});
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < k; i++) {
            list.add(toInt(st.nextToken()));
        }

        dijkstra();
        System.out.println(dst + "\n" + mx);
    }
}