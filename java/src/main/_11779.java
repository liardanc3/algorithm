package src.main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class _11779 {

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
    public static int n, m, a, b, c;
    public static int[] trace = new int[1001];
    public static int[] dist = new int[1001];
    public static PriorityQueue<Pair> pq = new PriorityQueue<>(
            (p1, p2) -> {
                if(p1.b != p2.b){
                    return p1.b > p2.b ? 1 : -1;
                }
                return 0;
            }
    );
    public static List<List<Pair>> list = new ArrayList<>();
    public static Stack<Integer> st = new Stack<>();

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        for(int i=0; i<=n; i++){
            list.add(new ArrayList<>());
        }

        m = Integer.parseInt(br.readLine());

        for(int i=0; i<m; i++){
            String[] input = br.readLine().split(" ");

            a = Integer.parseInt(input[0]);
            b = Integer.parseInt(input[1]);
            c = Integer.parseInt(input[2]);

            list.get(a).add(new Pair(b,c));
        }

        String[] input = br.readLine().split(" ");

        a = Integer.parseInt(input[0]);
        b = Integer.parseInt(input[1]);

        dijkstra(a, b);

        System.out.println(dist[b]);

        while(b != a){
            st.add(b);
            b = trace[b];
        }
        st.add(a);

        System.out.println(st.size());
        while(!st.isEmpty()){
            System.out.printf("%d ", st.pop());
        }
    }

    private static void dijkstra(int src, int dst){
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[src] = 0;
        pq.add(new Pair(src, 0));

        while(!pq.isEmpty()){
            Pair pair = pq.poll();

            int now = pair.a;
            int d = pair.b;

            if(dist[now] < d){
                continue;
            }

            for(int i=0; i<list.get(now).size(); i++){
                int next = list.get(now).get(i).a;
                int dd = list.get(now).get(i).b;

                if(d + dd < dist[next]){
                    dist[next] = d + dd;
                    pq.add(new Pair(next, dist[next]));
                    trace[next] = now;
                }
            }
        }
    }
}

