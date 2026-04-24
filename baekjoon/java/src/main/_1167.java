package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;

public class _1167 {

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
    public static int V, answerIdx;
    public static long answer;
    public static long[] dist = new long[100_001];
    public static int[] visited = new int[100_001];
    public static List<List<Pair>> graph = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        V = Integer.parseInt(br.readLine());
        for (int i = 0; i <= V; i++) {
            graph.add(new ArrayList<>());
        }

        for (int i = 0; i < V; i++) {
            String[] input = br.readLine().split(" ");

            int src = Integer.parseInt(input[0]);

            for (int j = 1; j < input.length; j++) {
                int dst = Integer.parseInt(input[j]);
                if(dst == -1){
                    break;
                }
                int dist = Integer.parseInt(input[j + 1]);
                j++;

                graph.get(src).add(new Pair(dst, dist));
                graph.get(dst).add(new Pair(src, dist));
            }
        }

        dfs(1, 0);
        answer = 0;

        Arrays.fill(visited, 0);
        dfs(answerIdx, 0);

        System.out.println(answer);
    }

    private static void dfs(int now, int cost) {
        visited[now] = 1;
        dist[now] = cost;
        answer = Math.max(answer, cost);
        if(answer == cost){
            answerIdx = now;
        }

        for(int i=0; i< graph.get(now).size(); i++){
            Pair p = graph.get(now).get(i);

            int next = p.a;
            int c = p.b;

            if(visited[next] == 0){
                dfs(next, c + cost);
            }
        }
    }
}

