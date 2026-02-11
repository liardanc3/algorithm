package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;

public class _1238 {

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
    public static int N, M, X, a, b, c, answer;
    public static String[] input;
    public static List<List<Pair>> list = new ArrayList<>();
    public static int[][] dist = new int[1001][1001];

    public static void main(String[] args) throws IOException {
        input = br.readLine().split(" ");

        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);
        X = Integer.parseInt(input[2]);

        for(int i=0; i<=M; i++){
            list.add(new ArrayList<>());
        }

        for (int i = 0; i < M; i++) {
            input = br.readLine().split(" ");

            a = Integer.parseInt(input[0]);
            b = Integer.parseInt(input[1]);
            c = Integer.parseInt(input[2]);

            list.get(a).add(new Pair(b, c));
        }

        for(int i=1; i<=N; i++){
            dijkstra(i);
        }

        for(int i=1; i<=N; i++){
            if(dist[i][X] != Integer.MAX_VALUE && dist[X][i] != Integer.MAX_VALUE){
                answer = Math.max(answer, dist[i][X] + dist[X][i]);
            }
        }

        System.out.println(answer);
    }

    private static void dijkstra(int src){
        Arrays.fill(dist[src], Integer.MAX_VALUE);
        dist[src][src] = 0;

        PriorityQueue<Pair> pq = new PriorityQueue<>(
                (p1, p2) -> p1.b < p2.b ? -1 : 1
        );
        pq.add(new Pair(src, 0));

        while(!pq.isEmpty()){
            Pair pair = pq.poll();

            int now = pair.a;
            int d = pair.b;

            if(dist[src][now] < d){
                continue;
            }

            for(int i=0; i<list.get(now).size(); i++){
                Pair p = list.get(now).get(i);

                int next = p.a;
                int dd = p.b;

                if(dist[src][next] > d+dd){
                    dist[src][next] = d + dd;
                    pq.add(new Pair(next, dist[src][next]));
                }
            }
        }
    }
}

