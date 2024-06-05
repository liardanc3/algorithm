import java.io.*;
import java.util.*;

public class _1504 {

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
    public static int N, E, a, b, v1, v2, answer;
    public static int c;
    public static int[] dist = new int[1001];
    public static List<List<Pair>> list = new ArrayList<>();
    public static PriorityQueue<Pair> pq = new PriorityQueue<>(
            (p1, p2) -> p1.b > p2.b ? 1 : -1
    );

    public static void main(String[] args) throws IOException {
        String[] input = br.readLine().split(" ");

        N = Integer.parseInt(input[0]);
        E = Integer.parseInt(input[1]);
        for(int i=0; i<=N; i++){
            list.add(new ArrayList<>());
        }

        for(int i=0; i<E; i++){
            input = br.readLine().split(" ");

            a = Integer.parseInt(input[0]);
            b = Integer.parseInt(input[1]);
            c = Integer.parseInt(input[2]);

            list.get(a).add(new Pair(b,c));
            list.get(b).add(new Pair(a,c));
        }
        input = br.readLine().split(" ");

        v1 = Integer.parseInt(input[0]);
        v2 = Integer.parseInt(input[1]);

        int answer = dijkstra(v1, v2) + Math.min(
                dijkstra(1, v1) + dijkstra(v2, N),
                dijkstra(1, v2) + dijkstra(v1, N)
        );
        if(answer < 0){
            System.out.println(-1);
        } else {
            System.out.println(answer);
        }
    }

    private static int dijkstra(int src, int dst){
        Arrays.fill(dist, Integer.MAX_VALUE);
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
                int cost = list.get(now).get(i).b;
           
                if(dist[next] > d + cost){
                    dist[next] = d + cost;
                    pq.add(new Pair(next, dist[next]));
                }
            }
        }

        return dist[dst] != Integer.MAX_VALUE ? dist[dst] : -599999;
    }
}
