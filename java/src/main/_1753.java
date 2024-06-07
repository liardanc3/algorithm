package src.main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;

public class _1753 {

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
    public static List<List<Pair>> list = new ArrayList<>();
    public static PriorityQueue<Pair> pq = new PriorityQueue<>(
            (p1, p2) -> p1.b > p2.b ? 1 : -1
    );
    public static int[] dist = new int[20001];
    public static int V, E, K, u, v, w;

    public static void main(String[] args) throws IOException {
        String[] input = br.readLine().split(" ");

        V = Integer.parseInt(input[0]);
        E = Integer.parseInt(input[1]);
        K = Integer.parseInt(br.readLine());

        for(int i=0; i<=V; i++){
            list.add(new ArrayList<>());
        }

        for(int i=0; i<E; i++){
            input = br.readLine().split(" ");

            u = Integer.parseInt(input[0]);
            v = Integer.parseInt(input[1]);
            w = Integer.parseInt(input[2]);

            list.get(u).add(new Pair(v, w));
        }

        dijkstra();
        for(int i=1; i<=V; i++){
            sb.append(dist[i] != Integer.MAX_VALUE ? dist[i] : "INF").append("\n");
        }
        System.out.println(sb);
    }

    private static void dijkstra(){
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[K] = 0;
        pq.add(new Pair(K, 0));

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
                    pq.add(new Pair(next, dist[next]));
                }
            }
        }
    }
}

