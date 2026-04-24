import java.io.*;
import java.util.*;

public class _1967 {

    public static class Pair {
        int a;
        int b;

        public Pair(int a, int b) {
            this.a = a;
            this.b = b;
        }
    }

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int N, a, b, c, mx, idx;
    public static int[] dist = new int[10002];
    public static List<List<Pair>> list = new ArrayList<>();
    public static PriorityQueue<Pair> pq = new PriorityQueue<>(
            (p1, p2) -> p1.b > p2.b ? 1 : -1
    );

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        for(int i=0; i<=N+1; i++){
            list.add(new ArrayList<>());
        }

        for(int i=0; i<N-1; i++){
            String[] input = br.readLine().split(" ");

            a = Integer.parseInt(input[0]);
            b = Integer.parseInt(input[1]);
            c = Integer.parseInt(input[2]);

            list.get(a).add(new Pair(b, c));
            list.get(b).add(new Pair(a, c));
        }

        dijkstra(1);
        dijkstra(idx);

        System.out.println(mx);
    }

    private static void dijkstra(int src){
        mx = 0;
        idx = 1;
        Arrays.fill(dist, Integer.MAX_VALUE);
        pq.clear();

        dist[src] = 0;
        pq.add(new Pair(src, 0));

        while(!pq.isEmpty()){
            Pair p = pq.poll();

            int now = p.a;
            int d = p.b;

            if(dist[now] < d){
                continue;
            }

            for(int i=0; i<list.get(now).size(); i++){
                int next = list.get(now).get(i).a;
                int dd = list.get(now).get(i).b;

                if(d + dd < dist[next]){
                    dist[next] = d + dd;
                    pq.add(new Pair(next, d + dd));
                }
            }
        }

        for (int i=1; i<=N; i++){
            if(mx < dist[i]){
                mx = dist[i];
                idx = i;
            }
        }
    }
}